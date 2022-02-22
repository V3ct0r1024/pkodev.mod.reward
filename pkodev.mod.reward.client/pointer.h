#pragma once
#include "address.h"

namespace pkodev
{
	namespace pointer
	{
		// CForm* CUIInterface::_FindForm(const char * frmName)
		typedef void* (__thiscall* CUIInterface___FindForm__Ptr)(void*, const char*);
		CUIInterface___FindForm__Ptr CUIInterface___FindForm = (CUIInterface___FindForm__Ptr)(void*)(address::MOD_EXE_VERSION::CUIInterface___FindForm);

		// void CForm::Show()
		typedef void(__thiscall* CForm__Show__Ptr)(void*);
		CForm__Show__Ptr CForm__Show = (CForm__Show__Ptr)(void*)(address::MOD_EXE_VERSION::CForm__Show);

		// void CForm::ShowModal()
		typedef void(__thiscall* CForm__ShowModal__Ptr)(void*);
		CForm__ShowModal__Ptr CForm__ShowModal = (CForm__ShowModal__Ptr)(void*)(address::MOD_EXE_VERSION::CForm__ShowModal);

		// void CForm::Hide()
		typedef void(__thiscall* CForm__Hide__Ptr)(void*);
		CForm__Hide__Ptr CForm__Hide = (CForm__Hide__Ptr)(void*)(address::MOD_EXE_VERSION::CForm__Hide);

		// CCompent* CForm::Find( const char* str )
		typedef void* (__thiscall* CForm__Find__Ptr)(void*, const char*);
		CForm__Find__Ptr CForm__Find = (CForm__Find__Ptr)(void*)(address::MOD_EXE_VERSION::CForm__Find);

		// inline CItemRecord* GetItemRecordInfo( int nTypeID )
		typedef void* (__cdecl* GetItemRecordInfo__Ptr)(int);
		GetItemRecordInfo__Ptr GetItemRecordInfo = (GetItemRecordInfo__Ptr)(void*)(address::MOD_EXE_VERSION::GetItemRecordInfo);
		
		// CItemCommand::CItemCommand(CItemRecord* pItem)
		typedef void (__thiscall* CItemCommand__CItemCommand__Ptr)(void *, void *);
		CItemCommand__CItemCommand__Ptr CItemCommand__CItemCommand = (CItemCommand__CItemCommand__Ptr)(void*)(address::MOD_EXE_VERSION::CItemCommand__CItemCommand);

		// void CItemCommand::SetTotalNum(int num)
		typedef void(__thiscall* CItemCommand__SetTotalNum__Ptr)(void*, int);
		CItemCommand__SetTotalNum__Ptr CItemCommand__SetTotalNum = (CItemCommand__SetTotalNum__Ptr)(void*)(address::MOD_EXE_VERSION::CItemCommand__SetTotalNum);

		// inline void CItemCommand::SetIsSolid( bool v ) 
		typedef void(__thiscall* CItemCommand__SetIsSolid__Ptr)(void*, bool);
		CItemCommand__SetIsSolid__Ptr CItemCommand__SetIsSolid = (CItemCommand__SetIsSolid__Ptr)(void*)(address::MOD_EXE_VERSION::CItemCommand__SetIsSolid);

		// void CItemCommand::Render(int x, int y)
		typedef void(__thiscall* CItemCommand__Render__Ptr)(void*, int, int);
		CItemCommand__Render__Ptr CItemCommand__Render = (CItemCommand__Render__Ptr)(void*)(address::MOD_EXE_VERSION::CItemCommand__Render);

		// void COneCommand::AddCommand( CCommandObj* p )  
		typedef void(__thiscall* COneCommand__AddCommand__Ptr)(void*, void*);
		COneCommand__AddCommand__Ptr COneCommand__AddCommand = (COneCommand__AddCommand__Ptr)(void*)(address::MOD_EXE_VERSION::COneCommand__AddCommand);

		// void COneCommand::DelCommand() 
		typedef void(__thiscall* COneCommand__DelCommand__Ptr)(void*);
		pointer::COneCommand__DelCommand__Ptr COneCommand__DelCommand = (pointer::COneCommand__DelCommand__Ptr)(void*)(address::MOD_EXE_VERSION::COneCommand__DelCommand);

		// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
		typedef void(__thiscall* CGuiPic__CGuiPic__Ptr)(void*, void*, unsigned int);
		CGuiPic__CGuiPic__Ptr CGuiPic__CGuiPic = (CGuiPic__CGuiPic__Ptr)(void*)(address::MOD_EXE_VERSION::CGuiPic__CGuiPic);

		// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
		typedef bool(__thiscall* CGuiPic__LoadImage__Ptr)(void*, const char*, int, int, int, int, int, float, float);
		CGuiPic__LoadImage__Ptr CGuiPic__LoadImage = (CGuiPic__LoadImage__Ptr)(void*)(address::MOD_EXE_VERSION::CGuiPic__LoadImage);

		// inline void CGuiPic::Render( int x, int y )
		typedef void(__thiscall* CGuiPic__Render__Ptr)(void*, int, int, int);
		CGuiPic__Render__Ptr CGuiPic__Render = (CGuiPic__Render__Ptr)(void*)(address::MOD_EXE_VERSION::CGuiPic__Render);
	
		// BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
		typedef bool(__thiscall* NetIF__HandlePacketMessage__Ptr)(void *, void *, void *);
		NetIF__HandlePacketMessage__Ptr NetIF__HandlePacketMessage = (NetIF__HandlePacketMessage__Ptr)(void*)(address::MOD_EXE_VERSION::NetIF__HandlePacketMessage);
		
		// uShort RPacket::ReadCmd()
		typedef unsigned short int(__thiscall* RPacket__ReadCmd__Ptr)(void*);
		RPacket__ReadCmd__Ptr RPacket__ReadCmd = (RPacket__ReadCmd__Ptr)(void*)(address::MOD_EXE_VERSION::RPacket__ReadCmd);

		// uLong RPacket::ReadLong()
		typedef unsigned int(__thiscall* RPacket__ReadLong__Ptr)(void*);
		RPacket__ReadLong__Ptr RPacket__ReadLong = (RPacket__ReadLong__Ptr)(void*)(address::MOD_EXE_VERSION::RPacket__ReadLong);
	
		// void *__cdecl operator new(size_t)
		typedef void* (__cdecl* operator__new__Ptr)(unsigned int);
		operator__new__Ptr operator__new = (operator__new__Ptr)(void*)(address::MOD_EXE_VERSION::operator__new);

		// WPacket TcpCommApp::GetWPacket() const
		typedef int(__thiscall* TcpCommApp__GetWPacket__Ptr)(void*, void*);
		TcpCommApp__GetWPacket__Ptr TcpCommApp__GetWPacket = (TcpCommApp__GetWPacket__Ptr)(void*)(address::MOD_EXE_VERSION::TcpCommApp__GetWPacket);

		// bool WPacket::WriteCmd(uShort cmd)
		typedef bool(__thiscall* WPacket__WriteCmd__Ptr)(void*, unsigned short int);
		WPacket__WriteCmd__Ptr WPacket__WriteCmd = (WPacket__WriteCmd__Ptr)(void*)(address::MOD_EXE_VERSION::WPacket__WriteCmd);

		// void NetIF::SendPacketMessage(LPWPACKET pk)
		typedef void(__thiscall* NetIF__SendPacketMessage__Ptr)(void*, void *);
		NetIF__SendPacketMessage__Ptr NetIF__SendPacketMessage = (NetIF__SendPacketMessage__Ptr)(void*)(address::MOD_EXE_VERSION::NetIF__SendPacketMessage);
	}
}