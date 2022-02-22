#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <detours.h>

#include <iostream>
#include <string>

#include "hook.h"
#include "pointer.h"
#include "structure.h"

#include "..\loader\loader.h"


// Current award day
unsigned int g_current_day = 0;

// Memory for CGuiPic (border image)
char g_img_border_mem[0x14]{ 0x00 };

// Memory for CGuiPic (sign image)
char g_img_sign_mem[0x14]{ 0x00 };

// Apply reward packet sent flag
bool g_packet_sent = false;

// Is reward form showing
bool g_reward_form_showing = false;

// Pointer to last item slot
void* g_last_slot_ptr = nullptr;



// Show daily reward form
void ShowReward(const pkodev::reward_data& data);

// Send reward apply packet to GameServer
void SendPacket();

// Apply reward button click event
void __cdecl ButtonRewardPressHandler(void* pSender, int x, int y, DWORD dwKey);

// Reward form close event
void __cdecl FormRewardCloseHandler(void* pSender, bool& IsClose);

// bool CCommandObj::IsAllowUse()
bool __cdecl IsAllowUse();


// Entry point
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    // Nothing to do . . .
    return TRUE;
}


// Get mod information
void __cdecl GetModInformation(mod_info& info)
{
    strcpy_s(info.name,    TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author,  TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

// Start the mod
void __cdecl Start(const char* path)
{
    // Enable hooks
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::pointer::NetIF__HandlePacketMessage, pkodev::hook::NetIF__HandlePacketMessage);
    DetourAttach(&(PVOID&)pkodev::pointer::CItemCommand__Render, pkodev::hook::CItemCommand__Render);
    DetourTransactionCommit();
}

// Stop the mod
void __cdecl Stop()
{
    // Disable hooks
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::pointer::NetIF__HandlePacketMessage, pkodev::hook::NetIF__HandlePacketMessage);
    DetourDetach(&(PVOID&)pkodev::pointer::CItemCommand__Render, pkodev::hook::CItemCommand__Render);
    DetourTransactionCommit();
}

// Show daily reward form
void ShowReward(const pkodev::reward_data& data)
{
    // Search daily reward form
    void* frmReward = pkodev::pointer::CUIInterface___FindForm(
        reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CUIInterface),
        "frmReward"
    );

    // Check that form is found
    if (frmReward != nullptr)
    {
        // Set form close event
        *reinterpret_cast<unsigned int*>(
            reinterpret_cast<unsigned int>(frmReward) + 0xA8
        ) = reinterpret_cast<unsigned int>(FormRewardCloseHandler);

        // Item slots
        void* cmdItemSlot[pkodev::MAX_DAYS];

        // Initialize item slots
        for (unsigned int i = 0; i < pkodev::MAX_DAYS; ++i)
        {
            // Make item slot name
            char tmp[32]{ 0x00 };
            sprintf_s(tmp, sizeof(tmp), "cmdItemSlot%d", i);

            // Search item slot
            cmdItemSlot[i] = pkodev::pointer::CForm__Find(frmReward, tmp);

            // Check that slot is found
            if (cmdItemSlot[i] != nullptr)
            {
                // Clear item slot
                pkodev::pointer::COneCommand__DelCommand(cmdItemSlot[i]);
            }
        }

        // Search apply button
        void* btnGetReward = pkodev::pointer::CForm__Find(frmReward, "btnGetReward");

        // Check that button is found
        if (btnGetReward != nullptr)
        {
            // Set click event
            *reinterpret_cast<unsigned int*>(
                reinterpret_cast<unsigned int>(btnGetReward) + 0x94
            ) = reinterpret_cast<unsigned int>(ButtonRewardPressHandler);

            // Unlock the button
            (*(void(__thiscall**)(void*, bool))(*(DWORD*)btnGetReward + 0x2C))(btnGetReward, true);
        }

        // Set patch for function CItemCommand::SetTotalNum()
        char patch[] = { (char)0x90, (char)0x90 };
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CItemCommand__SetTotalNum__Patch), reinterpret_cast<LPCVOID>(patch), sizeof(patch), nullptr);

        // Fill item slots
        for (unsigned int i = 0; (i < data.day && i < pkodev::MAX_DAYS); ++i)
        {
            // Check item slot pointer
            if (cmdItemSlot[i] == nullptr)
            {
                // Skip slot
                continue;
            }

            // Get an item by ID
            void* item = pkodev::pointer::GetItemRecordInfo(data.items[i].id);

            // Check that item is found
            if (item != nullptr)
            {
                // Allocate some memory for CItemCommand object
                void* command = pkodev::pointer::operator__new(0xEC);

                // Call CItemCommand::CItemCommand() constructor
                pkodev::pointer::CItemCommand__CItemCommand(command, item);

                // Set items number
                pkodev::pointer::CItemCommand__SetTotalNum(command, data.items[i].number);

                // Disable double-click on Item command event
                *reinterpret_cast<unsigned int*>(
                    *reinterpret_cast<unsigned int*>(
                        reinterpret_cast<unsigned int>(command)
                        ) + 0x7C
                ) = reinterpret_cast<unsigned int>(IsAllowUse);

                // Shadow previous days
                if ( (i + 1) < data.day )
                {
                    pkodev::pointer::CItemCommand__SetIsSolid(command, false);
                }

                // Save pointer to the latest item slot
                g_last_slot_ptr = command;

                // Add item command to control
                pkodev::pointer::COneCommand__AddCommand(cmdItemSlot[i], command);
            }
        }

        // Reset patch for function CItemCommand::SetTotalNum()
        char patch_[] = { (char)0x7E, (char)0x08 };
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CItemCommand__SetTotalNum__Patch), reinterpret_cast<LPCVOID>(patch_), sizeof(patch_), nullptr);

        // Save current day
        g_current_day = data.day;

        // Packet is not sent
        g_packet_sent = false;

        // Form is showing
        g_reward_form_showing = true;

        // Load pictures
        auto load_image = [](void *mem, const char *path, int w, int y, int tx, int ty) -> bool
        {
            // Call CGuiPic constructor
            pkodev::pointer::CGuiPic__CGuiPic(mem, nullptr, 0);

            // Load the image from file
            return pkodev::pointer::CGuiPic__LoadImage(mem, path, w, y, 0, tx, ty, 0, 0);
        };

        // Load border image
        bool success = (
            load_image(reinterpret_cast<void*>(g_img_border_mem), "texture\\mods\\pkodev.mod.reward\\main.png", 32, 32, 332, 159) &&
            load_image(reinterpret_cast<void*>(g_img_sign_mem),   "texture\\mods\\pkodev.mod.reward\\main.png", 12, 12, 319, 159)
        );

        // Open form
        if (success == true)
        {
            pkodev::pointer::CForm__Show(frmReward);
        }
    }
}

// Send reward apply packet to GameServer
void SendPacket()
{
    // Initialize packet
    char wpacket[0x38]{ 0x00 };
    pkodev::pointer::TcpCommApp__GetWPacket(
        reinterpret_cast<void*>(*reinterpret_cast<unsigned int*>(pkodev::address::MOD_EXE_VERSION::TcpCommApp)),
        reinterpret_cast<void*>(wpacket)
    );

    // Write packet ID
    pkodev::pointer::WPacket__WriteCmd(reinterpret_cast<void*>(wpacket), 499);

    // Send packet to server
    pkodev::pointer::NetIF__SendPacketMessage(
        reinterpret_cast<void*>(*reinterpret_cast<unsigned int*>(pkodev::address::MOD_EXE_VERSION::TcpCommApp)),
        reinterpret_cast<void*>(wpacket)
    );
}

// Apply reward button click event
void __cdecl ButtonRewardPressHandler(void* pSender, int x, int y, DWORD dwKey)
{
    // Increase current day
    g_current_day++;

    // Darken the last item slot
    if (g_last_slot_ptr != nullptr)
    {
        pkodev::pointer::CItemCommand__SetIsSolid(g_last_slot_ptr, false);
    }
    
    // Lock the button
    (*(void(__thiscall**)(void*, bool))(*(DWORD*)pSender + 0x2C))(pSender, false);

    // Packet sent
    g_packet_sent = true;

    // Send packet to server
    SendPacket();
}

// Reward form close event
void __cdecl FormRewardCloseHandler(void* pSender, bool& IsClose)
{
    // Form is closed
    g_reward_form_showing = false;

    // Check that packet was not sent yet
    if (g_packet_sent == false)
    {
        // Send packet
        SendPacket();
    }
}

// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
bool __stdcall pkodev::hook::NetIF__HandlePacketMessage(void* datasock, void* pk)
{
    // Read packet ID
    unsigned short int cmd = pkodev::pointer::RPacket__ReadCmd(pk);

    // Check reward packet ID
    if (cmd == 999)
    {
        // Daily reward data
        pkodev::reward_data data;

        // Read current day
        data.day = pkodev::pointer::RPacket__ReadLong(pk);

        // Read item list
        for (unsigned int i = 0; i < data.day; ++i)
        {
            data.items[i].id = pkodev::pointer::RPacket__ReadLong(pk);
            data.items[i].number = pkodev::pointer::RPacket__ReadLong(pk);
        }

        // Show form
        ShowReward(data);

        // Packet successfully handled
        return true;
    }

    // Call original function NetIF::HandlePacketMessage()
    return pkodev::pointer::NetIF__HandlePacketMessage(reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::NetIF), datasock, pk);
}

// bool CCommandObj::IsAllowUse()
bool __cdecl IsAllowUse()
{
    return false;
}

// void CItemCommand::Render(int x, int y)
void __fastcall pkodev::hook::CItemCommand__Render(void* This, void* NotUsed,
    int x, int y)
{
    // Check that reward from is showing
    if (g_reward_form_showing == false)
    {
        // Call original function CItemCommand::Render()
        pkodev::pointer::CItemCommand__Render(This, x, y);
        return;
    }

    // Convert std::string to const char *
    auto c_str = [](void *std__string) -> const char*
    {
        const char* str = nullptr;

        if (*(DWORD*)((DWORD)std__string + 0x28) < 0x10)
            str = (const char*)((DWORD)std__string + 0x14);
        else
            str = *(const char**)((DWORD)std__string + 0x14);

        return str;
    };

    // Get pointer to form name (std::string)
    const char* form = c_str(
        reinterpret_cast<void*>(
            *reinterpret_cast<unsigned int*>(
                *reinterpret_cast<unsigned int*>(
                    reinterpret_cast<unsigned int>(This) + 0x0C
                ) + 0x80
            )
        )
    );

    // Check form name
    if ( std::strcmp(form, "frmReward") == 0 )
    {
        // Get item slot name
        const char* slot = c_str(
            reinterpret_cast<void*>(
                *reinterpret_cast<unsigned int*>(
                    reinterpret_cast<unsigned int>(This) + 0x0C
                )
            )
        );

        // Get day from item slot name
        unsigned int day = std::stoul( std::string(slot, 11, 1)  ) + 1;

        // Render border
        if (day == g_current_day)
        {
            // Draw border image
            pkodev::pointer::CGuiPic__Render(
                reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiPic),
                x,
                y,
                (
                    *reinterpret_cast<unsigned int*>(g_img_border_mem)
                    +
                    *reinterpret_cast<unsigned int*>(
                        reinterpret_cast<unsigned int>(g_img_border_mem) + 4
                    )
                )
            );
        }

        // Set patch for function CItemCommand::Render()
        char patch[] = { (char)0x66, (char)0x83, (char)0xF8, (char)0x00 };
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CItemCommand__Render__Patch), reinterpret_cast<LPCVOID>(patch), sizeof(patch), nullptr);
        
        // Call original function CItemCommand::Render()
        pkodev::pointer::CItemCommand__Render(This, x, y);
        
        // Reset patch for function CItemCommand::Render()
        char patch_[] = { (char)0x66, (char)0x3D, (char)0x01, (char)0x00 };
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CItemCommand__Render__Patch), reinterpret_cast<LPCVOID>(patch_), sizeof(patch_), nullptr);

        // Render sign
        if (day < g_current_day)
        {
            // Draw sign image
            pkodev::pointer::CGuiPic__Render(
                reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CGuiPic),
                x + 12,
                y + 12,
                (
                    *reinterpret_cast<unsigned int*>(g_img_sign_mem)
                    +
                    *reinterpret_cast<unsigned int*>(
                        reinterpret_cast<unsigned int>(g_img_sign_mem) + 4
                    )
                )
            );
        }
    }
    else
    {
        // Call original function CItemCommand::Render()
        pkodev::pointer::CItemCommand__Render(This, x, y);
    }
}
