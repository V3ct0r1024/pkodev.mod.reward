#include <windows.h>
#include <detours.h>

#include <iostream>
#include <ctime>

#include "pointer.h"
#include "hook.h"
#include "structure.h"
#include "utils.h"

#include "..\loader\loader.h"


/*
    USE GameDB
    ALTER TABLE character ADD reward VARCHAR(128) NOT NULL DEFAULT '0' WITH VALUES
*/

// Get character ID
unsigned int GetRoleID(void* role);

// Get main character
void* GetMainCha(void* role);

// Load award data from database
bool SelectRoleRewardDB(void *role, pkodev::reward& data);

// Save award data to database
bool UpdateRoleRewardDB(void* role, const pkodev::reward& data);

// Get item list for a next 7 days
void CreateRoleReward(void* role, unsigned long long time, pkodev::reward& data);

// Send packet with daily award data to the player
void SyncRoleReward(void* role, const pkodev::reward& data);

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
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

// Start the mod
void __cdecl Start(const char* path)
{
    // Enable hooks
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::pointer::CCharacter__Cmd_EnterMap, pkodev::hook::CCharacter__Cmd_EnterMap);
    DetourAttach(&(PVOID&)pkodev::pointer::CCharacter__ProcessPacket, pkodev::hook::CCharacter__ProcessPacket);
    DetourTransactionCommit();

    // Print welcome message
    std::cout << "[pkodev.mod.reward] Daily reward system ver. 1.0 by V3ct0r enabled!" << std::endl;
}

// Stop the mod
void __cdecl Stop()
{
    // Disable hooks
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::pointer::CCharacter__Cmd_EnterMap, pkodev::hook::CCharacter__Cmd_EnterMap);
    DetourDetach(&(PVOID&)pkodev::pointer::CCharacter__ProcessPacket, pkodev::hook::CCharacter__ProcessPacket);
    DetourTransactionCommit();
}

// Get character ID
unsigned int GetRoleID(void* role)
{
    return *reinterpret_cast<unsigned int*>(
        *reinterpret_cast<unsigned int*>(
            reinterpret_cast<unsigned int>(role) + 0x21C
        ) + 0xFE8
    );
}

// Get main character
void* GetMainCha(void* role)
{
    return reinterpret_cast<void*>(
        *reinterpret_cast<unsigned int*>(
            *reinterpret_cast<unsigned int*>(
                reinterpret_cast<unsigned int>(role) + 0x21C
            ) + 0x1078
        )
    );
}

// Load award from database
bool SelectRoleRewardDB(void* role, pkodev::reward& data)
{
    // Columns number
    const unsigned int MAX_COL = 1;

    // Field length
    const unsigned int MAX_DATALEN = 128;

    // A buffer for SQL query
    char sql[64]{ 0x00 };

    // A buffer for query result
    char buf[MAX_COL][MAX_DATALEN]{ 0x00 };

    // Result length
    unsigned int buf_len[MAX_COL]{0x00};

    // SQL query handle
    int hstmt = 0;

    // Column number in query result
    int colnum = 0;


    // Build SQL-query
    sprintf_s(sql, sizeof(sql), "SELECT reward FROM character WHERE cha_id = %d", GetRoleID(role));

    // Get SQL query handle
    short int ret = pkodev::pointer::SQLAllocHandle(
        3,
        *reinterpret_cast<unsigned int*>(
            pkodev::address::MOD_EXE_VERSION::CGameDB + 0x28
         ),
        &hstmt
    );
    
    // Check SQLAllocHandle() result
    if ( (ret != 0) && (ret != 1) )
    {
        // Free handle
        pkodev::pointer::SQLFreeHandle(3, hstmt);

        // SQLAllocHandle() failed
        return false;
    }
    
    // Execute SQL query
    ret = pkodev::pointer::SQLExecDirect(hstmt, sql, 0xFFFFFFFD);

    // Check SQLExecDirect() result
    if (ret != 0)
    {
        // Free handle
        pkodev::pointer::SQLFreeHandle(3, hstmt);

        // SQLExecDirect() failed
        return false;
    }

    // Get column number
    ret = pkodev::pointer::SQLNumResultCols(hstmt, &colnum);

    // Check SQLNumResultCols() result
    if (ret != 0)
    {
        // Free handle
        pkodev::pointer::SQLFreeHandle(3, hstmt);

        // SQLNumResultCols() failed
        return false;
    }

    // Check max number of columns
    if (colnum > MAX_COL) colnum = MAX_COL;

    // Bind columns
    for (int i = 0; i < colnum; ++i)
    {
        pkodev::pointer::SQLBindCol(
            hstmt, 
            (i + 1),
            1,
            reinterpret_cast<int>(buf[i]), 
            MAX_DATALEN, 
            reinterpret_cast<int *>(&buf_len[i])
        );
    }

    // Fetch rows
    ret = pkodev::pointer::SQLFetch(hstmt);

    // Check SQLFetch() result
    if ( (ret != 0) && (ret != 1) )
    {
        // Close cursor
        pkodev::pointer::SQLFreeStmt(hstmt, 2);

        // Free query handle
        pkodev::pointer::SQLFreeHandle(3, hstmt);

        // SQLFetch() failed!
        return false;
    }

    // Close cursor
    pkodev::pointer::SQLFreeStmt(hstmt, 2);

    // Free handle
    pkodev::pointer::SQLFreeHandle(3, hstmt);

    // Get raw data
    std::string raw = pkodev::utils::string::trim(std::string(buf[0], buf_len[0]));

    // Check that reward streak was made
    if (raw.length() > 0)
    {
        data.from_string(raw);
    }

    // Return result
    return true;
}

// Save award data in database
bool UpdateRoleRewardDB(void* role, const pkodev::reward& data)
{
    // Buffer for SQL-query
    char sql[128]{ 0x00 };

    // Build SQL query
    sprintf_s( sql,  sizeof(sql), "UPDATE character SET reward = '%s' WHERE cha_id = %d",  data.to_string().c_str(), GetRoleID(role) );

    // Trying execute the query
    short int ret = pkodev::pointer::cfl_rs__exec_sql_direct(
        reinterpret_cast<void*>(
            *reinterpret_cast<unsigned int*>(
                pkodev::address::MOD_EXE_VERSION::CGameDB + 0x3C
            )
        ),
        sql,
        5
    );

    return (ret == 0);
}

// Get item list for a next 7 days
void CreateRoleReward(void* role, unsigned long long time, pkodev::reward& data)
{
    // Set 1st day
    data.day = 1;

    // Set current time
    data.time = time;

    // Call user-defined LUA function
    int ret = pkodev::pointer::CParser__DoString(
        reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CParser),
        "GetRewardArrayAdapter",
        pkodev::enumSCRIPT_RETURN_NUMBER,
        14,
        pkodev::enumSCRIPT_PARAM_LIGHTUSERDATA,
        1,
        GetMainCha(role),
        pkodev::DOSTRING_PARAM_END
    );

    // Check result
    if (ret != 0)
    {
        // Fill item list
        for (unsigned int i = 0; i < pkodev::reward::max_days; ++i)
        {
            // Get item ID
            data.items[i].id = pkodev::pointer::CParser__GetReturnNumber(
                reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CParser),
                (i * 2)
            );

            // Get item number
            data.items[i].number = pkodev::pointer::CParser__GetReturnNumber(
                reinterpret_cast<void*>(pkodev::address::MOD_EXE_VERSION::CParser),
                (i * 2) + 1
            );
        }
    }
    else
    {
        // Set empty item list
        for (unsigned int i = 0; i < pkodev::reward::max_days; ++i)
        {
            data.items[i] = { 0, 0 };
        }
    }
}

// Send packet with daily award data to the player
void SyncRoleReward(void* role, const pkodev::reward& data)
{
    // Initialize a packet
    char packet[0x38]{ 0x00 };
    pkodev::pointer::TcpCommApp__GetWPacket(
        reinterpret_cast<void*>(*reinterpret_cast<unsigned int*>(pkodev::address::MOD_EXE_VERSION::TcpCommApp)),
        reinterpret_cast<void*>(packet)
    );

    // Write packet ID
    pkodev::pointer::WPacket__WriteCmd(reinterpret_cast<void* >(packet), 999);

    // Write day
    pkodev::pointer::WPacket__WriteLong(reinterpret_cast<void*>(packet), data.day);

    // Write items
    for (unsigned int i = 0; i < data.day; ++i)
    {
        pkodev::pointer::WPacket__WriteLong(reinterpret_cast<void*>(packet), data.items[i].id);
        pkodev::pointer::WPacket__WriteLong(reinterpret_cast<void*>(packet), data.items[i].number);
    }

    // Send packet
    pkodev::pointer::CCharacter__ReflectINFof(
        role,
        role,
        *reinterpret_cast<int*>(packet),
        *reinterpret_cast<int*>(packet + 4),
        *reinterpret_cast<int*>(packet + 8),
        *reinterpret_cast<int*>(packet + 12),
        *reinterpret_cast<int*>(packet + 16),
        *reinterpret_cast<int*>(packet + 20),
        *reinterpret_cast<int*>(packet + 24),
        *reinterpret_cast<int*>(packet + 28),
        *reinterpret_cast<int*>(packet + 32),
        *reinterpret_cast<int*>(packet + 36),
        *reinterpret_cast<int*>(packet + 40),
        *reinterpret_cast<int*>(packet + 44),
        *reinterpret_cast<int*>(packet + 48),
        *reinterpret_cast<int*>(packet + 52)
    );
}

// bool CCharacter::Cmd_EnterMap(cChar* l_map, Long lMapCopyNO, uLong l_x, uLong l_y, Char chLogin)
bool __fastcall  pkodev::hook::CCharacter__Cmd_EnterMap(void* This, void* NotUsed,
    const char* mapname, int copyno, int x, int y, bool logged)
{
    // Call original function CCharacter::Cmd_EnterMap()
    bool ret = pkodev::pointer::CCharacter__Cmd_EnterMap(This, mapname, copyno, x, y, logged);

    // Check result
    if (ret == true)
    {
        // Check that player has entered the game from character selection scene
        if (logged == false)
        {
            // Reward data structure
            pkodev::reward reward;

            // Get reward data from database
            bool sqlret = SelectRoleRewardDB(This, reward);

            // Check that reward data successfully loaded from database
            if (sqlret == true)
            {
                // Get current server time
                unsigned long long timestamp = static_cast<unsigned long long>(std::time(nullptr));

                // Check that the list of items was created for the next 7 days
                if (reward.day == 0)
                {
                    // Make new item list
                    CreateRoleReward(This, timestamp, reward);

                    // Update reward data in database
                    UpdateRoleRewardDB(This,  reward);
                }
                else
                {
                    // Calculate time delta in seconds
                    unsigned long long delta = (timestamp - reward.time);

                    // Check if it's time to reward
                    if (delta >= pkodev::reward::interval)
                    {
                        // Check that the reward time has not expired
                        if ( delta > (2 * pkodev::reward::interval) )
                        {
                            // Make new item list
                            CreateRoleReward(This, 0, reward);

                            // Update reward data in database
                            UpdateRoleRewardDB(This, reward);
                        }

                        // Show reward form at client side
                        SyncRoleReward(This, reward);
                    }
                }
            }
        }
    }

    return ret;
}

// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
void __fastcall pkodev::hook::CCharacter__ProcessPacket(void* This, void* NotUsed,
    unsigned short int usCmd, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
    int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
    // Build RPacket object from stack
    char rpacket[0x40]{ 0x00 };
    *reinterpret_cast<int*>(rpacket)      = a1;
    *reinterpret_cast<int*>(rpacket + 4)  = a2;
    *reinterpret_cast<int*>(rpacket + 8)  = a3;
    *reinterpret_cast<int*>(rpacket + 12) = a4;
    *reinterpret_cast<int*>(rpacket + 16) = a5;
    *reinterpret_cast<int*>(rpacket + 20) = a6;
    *reinterpret_cast<int*>(rpacket + 24) = a7;
    *reinterpret_cast<int*>(rpacket + 28) = a8;
    *reinterpret_cast<int*>(rpacket + 32) = a9;
    *reinterpret_cast<int*>(rpacket + 36) = a10;
    *reinterpret_cast<int*>(rpacket + 40) = a11;
    *reinterpret_cast<int*>(rpacket + 44) = a12;
    *reinterpret_cast<int*>(rpacket + 48) = a13;
    *reinterpret_cast<int*>(rpacket + 52) = a14;
    *reinterpret_cast<int*>(rpacket + 56) = a15;
    *reinterpret_cast<int*>(rpacket + 60) = a16;
    
    // Check ID of reward apply packet
    if (usCmd == 499)
    {
        // Reward data structure
        pkodev::reward reward;

        // Get reward data from database
        bool sqlret = SelectRoleRewardDB(This, reward);

        // Check that reward data successfully loaded from database
        if (sqlret == true)
        {
            // Get current server time
            unsigned long long timestamp = static_cast<unsigned long long>(std::time(nullptr));

            // Calculate time delta in seconds
            unsigned long long delta = (timestamp - reward.time);

            // Check if it's time to reward
            if (delta >= pkodev::reward::interval)
            {
                // Get item slot index
                unsigned int index = (reward.day - 1);

                // Check the index
                if (index < pkodev::reward::max_days)
                {
                    // Get item slot
                    const pkodev::reward::slot& slot = reward.items[ index ];

                    // System name
                    const char* name = "[Daily Reward]";

                    // Get free cells in character's inventory
                    unsigned short int free =
                    (
                        pkodev::pointer::CKitbag__GetCapacity(
                            reinterpret_cast<void*>(  reinterpret_cast<unsigned int>(This) + 0x4D20  )
                        ) -
                        pkodev::pointer::CKitbag__GetUseGridNum(
                            reinterpret_cast<void*>( reinterpret_cast<unsigned int>(This) + 0x4D20  ),
                            0
                        )
                    );

                    // Check that charater's inventory has free slots
                    if (free > 0)
                    {
                        // Add item to character's inventory
                        pkodev::pointer::CCharacter__AddItem( GetMainCha(This), slot.id, slot.number, name, 3, 7 );
                    }
                    else
                    {
                        // Add item to character's temporary bag
                        pkodev::pointer::CCharacter__AddItem2KitbagTemp( GetMainCha(This), slot.id, slot.number, name, 3, 7 );
                    }
                }

                // Check current day
                if (reward.day == reward::max_days)
                {
                    // Make new item list
                    CreateRoleReward(This, timestamp, reward);
                }
                else
                {
                    // Increase day
                    reward.day++;

                    // Update last reward time
                    reward.time = timestamp;
                }

                // Update reward data in database
                UpdateRoleRewardDB(This, reward);
            }
        }
    }
    else
    {
        // Call original function CCharacter::ProcessPacket()
        pkodev::pointer::CCharacter__ProcessPacket(This, usCmd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
    }
}