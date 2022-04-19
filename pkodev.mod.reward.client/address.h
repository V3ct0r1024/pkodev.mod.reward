#pragma once

namespace pkodev
{
	namespace address
	{
		// Game.exe 0 (1222073761)
		namespace GAME_13X_0
		{
			// CUIInterface
			const unsigned int CUIInterface = 0x0066A288;

			// CForm* CUIInterface::_FindForm(const char * frmName)
			const unsigned int CUIInterface___FindForm = 0x0049E390;

			// void CForm::Show()
			const unsigned int CForm__Show = 0x00493FD0;

			// void CForm::ShowModal()
			const unsigned int CForm__ShowModal = 0x00493F50;

			// // void CForm::Hide()
			const unsigned int CForm__Hide = 0x00493430;

			// CCompent* CForm::Find( const char* str )
			const unsigned int CForm__Find = 0x00494040;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			const unsigned int GetItemRecordInfo = 0x0040CE90;

			// CItemCommand::CItemCommand(CItemRecord* pItem)
			const unsigned int CItemCommand__CItemCommand = 0x004898E0;

			// void CItemCommand::SetTotalNum(int num)
			const unsigned int CItemCommand__SetTotalNum = 0x00488280;

			// [7E 08] -> [90 90]
			// JLE SHORT 004883FC -> NOP NOP
			const unsigned int CItemCommand__SetTotalNum__Patch = 0x00488292;

			// inline void CItemCommand::SetIsSolid( bool v )      
			const unsigned int CItemCommand__SetIsSolid = 0x00488B80;

			// void CItemCommand::Render(int x, int y)
			const unsigned int CItemCommand__Render = 0x00488F00;

			// [66 3D 01 00] -> [66 83 F8 00]
			// CMP AX, 1 -> CMP AX,0
			const unsigned int CItemCommand__Render__Patch = 0x00488F43;

			// void COneCommand::AddCommand( CCommandObj* p )  
			const unsigned int COneCommand__AddCommand = 0x00421AC0;

			// void COneCommand::DelCommand() 
			const unsigned int COneCommand__DelCommand = 0x00421AA0;

			// CGuiPic
			const unsigned int CGuiPic = 0x00654000;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			const unsigned int CGuiPic__CGuiPic = 0x0049D640;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			const unsigned int CGuiPic__LoadImage = 0x0049FDC0;

			// inline void CGuiPic::Render( int x, int y )	
			const unsigned int CGuiPic__Render = 0x0049ED60;

			// NetIF
			const unsigned int NetIF = 0x006C2508;

			// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
			const unsigned int NetIF__HandlePacketMessage = 0x00516D30;

			// uShort RPacket::ReadCmd()
			const unsigned int RPacket__ReadCmd = 0x0054F7C0;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0054FA80;

			// void *__cdecl operator new(size_t)
			const unsigned int operator__new = 0x0059C988;

			// TcpCommApp
			const unsigned int TcpCommApp = 0x006C2508;

			// WPacket TcpCommApp::GetWPacket()const
			const unsigned int TcpCommApp__GetWPacket = 0x005515C0;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0054EA40;

			// void NetIF::SendPacketMessage(LPWPACKET pk)
			const unsigned int NetIF__SendPacketMessage = 0x005193E0;
		}

		// Game.exe 1 (1243412597)
		namespace GAME_13X_1
		{
			// CUIInterface
			const unsigned int CUIInterface = 0x0066A288;

			// CForm* CUIInterface::_FindForm(const char * frmName)
			const unsigned int CUIInterface___FindForm = 0x0049E4A0;

			// void CForm::Show()
			const unsigned int CForm__Show = 0x004940E0;

			// void CForm::ShowModal()
			const unsigned int CForm__ShowModal = 0x00494060;

			// // void CForm::Hide()
			const unsigned int CForm__Hide = 0x00493540;

			// CCompent* CForm::Find( const char* str )
			const unsigned int CForm__Find = 0x00494150;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			const unsigned int GetItemRecordInfo = 0x0040CE90;

			// CItemCommand::CItemCommand(CItemRecord* pItem)
			const unsigned int CItemCommand__CItemCommand = 0x004899A0;

			// void CItemCommand::SetTotalNum(int num)
			const unsigned int CItemCommand__SetTotalNum = 0x00488340;

			// [7E 08] -> [90 90]
			// JLE SHORT 004883FC -> NOP NOP
			const unsigned int CItemCommand__SetTotalNum__Patch = 0x00488352;

			// inline void CItemCommand::SetIsSolid( bool v )      
			const unsigned int CItemCommand__SetIsSolid = 0x00488C40;

			// void CItemCommand::Render(int x, int y)
			const unsigned int CItemCommand__Render = 0x00488FC0;

			// [66 3D 01 00] -> [66 83 F8 00]
			// CMP AX, 1 -> CMP AX,0
			const unsigned int CItemCommand__Render__Patch = 0x00489003;

			// void COneCommand::AddCommand( CCommandObj* p )  
			const unsigned int COneCommand__AddCommand = 0x00421AC0;

			// void COneCommand::DelCommand() 
			const unsigned int COneCommand__DelCommand = 0x00421AA0;

			// CGuiPic
			const unsigned int CGuiPic = 0x00654000;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			const unsigned int CGuiPic__CGuiPic = 0x0049D750;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			const unsigned int CGuiPic__LoadImage = 0x0049FED0;

			// inline void CGuiPic::Render( int x, int y )	
			const unsigned int CGuiPic__Render = 0x0049EE70;

			// NetIF
			const unsigned int NetIF = 0x006C25F8;

			// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
			const unsigned int NetIF__HandlePacketMessage = 0x00516E40;

			// uShort RPacket::ReadCmd()
			const unsigned int RPacket__ReadCmd = 0x0054F900;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0054FBC0;

			// void *__cdecl operator new(size_t)
			const unsigned int operator__new = 0x0059CAC8;

			// TcpCommApp
			const unsigned int TcpCommApp = 0x006C25F8;

			// WPacket TcpCommApp::GetWPacket()const
			const unsigned int TcpCommApp__GetWPacket = 0x00551700;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0054EB80;

			// void NetIF::SendPacketMessage(LPWPACKET pk)
			const unsigned int NetIF__SendPacketMessage = 0x005194F0;
		}

		// Game.exe 2 (1252912474)
		namespace GAME_13X_2
		{
			// CUIInterface
			const unsigned int CUIInterface = 0x0066A288;

			// CForm* CUIInterface::_FindForm(const char * frmName)
			const unsigned int CUIInterface___FindForm = 0x0049E540;

			// void CForm::Show()
			const unsigned int CForm__Show = 0x00494180;

			// void CForm::ShowModal()
			const unsigned int CForm__ShowModal = 0x00494100;

			// // void CForm::Hide()
			const unsigned int CForm__Hide = 0x004935E0;

			// CCompent* CForm::Find( const char* str )
			const unsigned int CForm__Find = 0x004941F0;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			const unsigned int GetItemRecordInfo = 0x0040CE90;

			// CItemCommand::CItemCommand(CItemRecord* pItem)
			const unsigned int CItemCommand__CItemCommand = 0x00489A40;

			// void CItemCommand::SetTotalNum(int num)
			const unsigned int CItemCommand__SetTotalNum = 0x004883E0;

			// [7E 08] -> [90 90]
			// JLE SHORT 004883FC -> NOP NOP
			const unsigned int CItemCommand__SetTotalNum__Patch = 0x004883F2;

			// inline void CItemCommand::SetIsSolid( bool v )      
			const unsigned int CItemCommand__SetIsSolid = 0x00488CE0;

			// void CItemCommand::Render(int x, int y)
			const unsigned int CItemCommand__Render = 0x00489060;

			// [66 3D 01 00] -> [66 83 F8 00]
			// CMP AX, 1 -> CMP AX,0
			const unsigned int CItemCommand__Render__Patch = 0x004890A3;

			// void COneCommand::AddCommand( CCommandObj* p )  
			const unsigned int COneCommand__AddCommand = 0x00421AC0;

			// void COneCommand::DelCommand() 
			const unsigned int COneCommand__DelCommand = 0x00421AA0;

			// CGuiPic
			const unsigned int CGuiPic = 0x00654000;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			const unsigned int CGuiPic__CGuiPic = 0x0049D7F0;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			const unsigned int CGuiPic__LoadImage = 0x0049FF70;

			// inline void CGuiPic::Render( int x, int y )	
			const unsigned int CGuiPic__Render = 0x0049EF10;

			// NetIF
			const unsigned int NetIF = 0x006C25F8;

			// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
			const unsigned int NetIF__HandlePacketMessage = 0x00516F10;

			// uShort RPacket::ReadCmd()
			const unsigned int RPacket__ReadCmd = 0x0054F9C0;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0054FC80;

			// void *__cdecl operator new(size_t)
			const unsigned int operator__new = 0x0059CB88;

			// TcpCommApp
			const unsigned int TcpCommApp = 0x006C25F8;

			// WPacket TcpCommApp::GetWPacket()const
			const unsigned int TcpCommApp__GetWPacket = 0x005517C0;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0054EC40;

			// void NetIF::SendPacketMessage(LPWPACKET pk)
			const unsigned int NetIF__SendPacketMessage = 0x005195C0;
		}

		// Game.exe 3 (1244511158)
		namespace GAME_13X_3
		{
			// CUIInterface
			const unsigned int CUIInterface = 0x0066A288;

			// CForm* CUIInterface::_FindForm(const char * frmName)
			const unsigned int CUIInterface___FindForm = 0x0049E530;

			// void CForm::Show()
			const unsigned int CForm__Show = 0x00494170;

			// void CForm::ShowModal()
			const unsigned int CForm__ShowModal = 0x004940F0;

			// // void CForm::Hide()
			const unsigned int CForm__Hide = 0x004935D0;

			// CCompent* CForm::Find( const char* str )
			const unsigned int CForm__Find = 0x004941E0;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			const unsigned int GetItemRecordInfo = 0x0040CE90;

			// CItemCommand::CItemCommand(CItemRecord* pItem)
			const unsigned int CItemCommand__CItemCommand = 0x00489A30;

			// void CItemCommand::SetTotalNum(int num)
			const unsigned int CItemCommand__SetTotalNum = 0x004883D0;

			// [7E 08] -> [90 90]
			// JLE SHORT 004883FC -> NOP NOP
			const unsigned int CItemCommand__SetTotalNum__Patch = 0x004883E2;

			// inline void CItemCommand::SetIsSolid( bool v )      
			const unsigned int CItemCommand__SetIsSolid = 0x00488CD0;

			// void CItemCommand::Render(int x, int y)
			const unsigned int CItemCommand__Render = 0x00489050;

			// [66 3D 01 00] -> [66 83 F8 00]
			// CMP AX, 1 -> CMP AX,0
			const unsigned int CItemCommand__Render__Patch = 0x00489093;

			// void COneCommand::AddCommand( CCommandObj* p )  
			const unsigned int COneCommand__AddCommand = 0x00421AC0;

			// void COneCommand::DelCommand() 
			const unsigned int COneCommand__DelCommand = 0x00421AA0;

			// CGuiPic
			const unsigned int CGuiPic = 0x00654000;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			const unsigned int CGuiPic__CGuiPic = 0x0049D7E0;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			const unsigned int CGuiPic__LoadImage = 0x0049FF60;

			// inline void CGuiPic::Render( int x, int y )	
			const unsigned int CGuiPic__Render = 0x0049EF00;

			// NetIF
			const unsigned int NetIF = 0x006C25F8;

			// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
			const unsigned int NetIF__HandlePacketMessage = 0x00516F00;

			// uShort RPacket::ReadCmd()
			const unsigned int RPacket__ReadCmd = 0x0054F9C0;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0054FC80;

			// void *__cdecl operator new(size_t)
			const unsigned int operator__new = 0x0059CB88;

			// TcpCommApp
			const unsigned int TcpCommApp = 0x006C25F8;

			// WPacket TcpCommApp::GetWPacket()const
			const unsigned int TcpCommApp__GetWPacket = 0x005517C0;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0054EC40;

			// void NetIF::SendPacketMessage(LPWPACKET pk)
			const unsigned int NetIF__SendPacketMessage = 0x005195B0;
		}

		// Game.exe 4 (1585009030)
		namespace GAME_13X_4
		{
			// CUIInterface
			const unsigned int CUIInterface = 0x0066A2A0;

			// CForm* CUIInterface::_FindForm(const char * frmName)
			const unsigned int CUIInterface___FindForm = 0x0049E740;

			// void CForm::Show()
			const unsigned int CForm__Show = 0x00494380;

			// void CForm::ShowModal()
			const unsigned int CForm__ShowModal = 0x00494300;

			// // void CForm::Hide()
			const unsigned int CForm__Hide = 0x004937E0;

			// CCompent* CForm::Find( const char* str )
			const unsigned int CForm__Find = 0x004943F0;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			const unsigned int GetItemRecordInfo = 0x0040CF90;

			// CItemCommand::CItemCommand(CItemRecord* pItem)
			const unsigned int CItemCommand__CItemCommand = 0x00489C30;

			// void CItemCommand::SetTotalNum(int num)
			const unsigned int CItemCommand__SetTotalNum = 0x00488550;

			// [7E 08] -> [90 90]
			// JLE SHORT 004883FC -> NOP NOP
			const unsigned int CItemCommand__SetTotalNum__Patch = 0x00488562;

			// inline void CItemCommand::SetIsSolid( bool v )      
			const unsigned int CItemCommand__SetIsSolid = 0x00488E50;

			// void CItemCommand::Render(int x, int y)
			const unsigned int CItemCommand__Render = 0x00489500;

			// [66 3D 01 00] -> [66 83 F8 00]
			// CMP AX, 1 -> CMP AX,0
			const unsigned int CItemCommand__Render__Patch = 0x00489559;

			// void COneCommand::AddCommand( CCommandObj* p )  
			const unsigned int COneCommand__AddCommand = 0x00421BF0;

			// void COneCommand::DelCommand() 
			const unsigned int COneCommand__DelCommand = 0x00421BD0;

			// CGuiPic
			const unsigned int CGuiPic = 0x00654008;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			const unsigned int CGuiPic__CGuiPic = 0x0049D9F0;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			const unsigned int CGuiPic__LoadImage = 0x004A0230;

			// inline void CGuiPic::Render( int x, int y )	
			const unsigned int CGuiPic__Render = 0x0049F110;

			// NetIF
			const unsigned int NetIF = 0x006C2610;

			// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
			const unsigned int NetIF__HandlePacketMessage = 0x00517130;

			// uShort RPacket::ReadCmd()
			const unsigned int RPacket__ReadCmd = 0x0054FCD0;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0054FF90;

			// void *__cdecl operator new(size_t)
			const unsigned int operator__new = 0x0059CF08;

			// TcpCommApp
			const unsigned int TcpCommApp = 0x006C2610;

			// WPacket TcpCommApp::GetWPacket()const
			const unsigned int TcpCommApp__GetWPacket = 0x00551AD0;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0054EE80;

			// void NetIF::SendPacketMessage(LPWPACKET pk)
			const unsigned int NetIF__SendPacketMessage = 0x005197F0;
		}

		// Game.exe 5 (1207214236)
		namespace GAME_13X_5
		{
			// CUIInterface
			const unsigned int CUIInterface = 0x0066A290;

			// CForm* CUIInterface::_FindForm(const char * frmName)
			const unsigned int CUIInterface___FindForm = 0x0049E190;

			// void CForm::Show()
			const unsigned int CForm__Show = 0x00493DD0;

			// void CForm::ShowModal()
			const unsigned int CForm__ShowModal = 0x00493D50;

			// // void CForm::Hide()
			const unsigned int CForm__Hide = 0x00493230;

			// CCompent* CForm::Find( const char* str )
			const unsigned int CForm__Find = 0x00493E40;

			// inline CItemRecord* GetItemRecordInfo( int nTypeID )
			const unsigned int GetItemRecordInfo = 0x0040CE80;

			// CItemCommand::CItemCommand(CItemRecord* pItem)
			const unsigned int CItemCommand__CItemCommand = 0x004895B0;

			// void CItemCommand::SetTotalNum(int num)
			const unsigned int CItemCommand__SetTotalNum = 0x00487F50;

			// [7E 08] -> [90 90]
			// JLE SHORT 004883FC -> NOP NOP
			const unsigned int CItemCommand__SetTotalNum__Patch = 0x00487F62;

			// inline void CItemCommand::SetIsSolid( bool v )      
			const unsigned int CItemCommand__SetIsSolid = 0x00488850;

			// void CItemCommand::Render(int x, int y)
			const unsigned int CItemCommand__Render = 0x00488BD0;

			// [66 3D 01 00] -> [66 83 F8 00]
			// CMP AX, 1 -> CMP AX,0
			const unsigned int CItemCommand__Render__Patch = 0x00488C13;

			// void COneCommand::AddCommand( CCommandObj* p )  
			const unsigned int COneCommand__AddCommand = 0x00421AB0;

			// void COneCommand::DelCommand() 
			const unsigned int COneCommand__DelCommand = 0x00421A90;

			// CGuiPic
			const unsigned int CGuiPic = 0x00654000;

			// CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
			const unsigned int CGuiPic__CGuiPic = 0x0049D440;

			// bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
			const unsigned int CGuiPic__LoadImage = 0x0049FBC0;

			// inline void CGuiPic::Render( int x, int y )	
			const unsigned int CGuiPic__Render = 0x0049EB60;

			// NetIF
			const unsigned int NetIF = 0x006C2510;

			// BOOL NetIF::HandlePacketMessage(DataSocket *datasock,LPRPACKET pk)
			const unsigned int NetIF__HandlePacketMessage = 0x00516BA0;

			// uShort RPacket::ReadCmd()
			const unsigned int RPacket__ReadCmd = 0x0054F640;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0054F900;

			// void *__cdecl operator new(size_t)
			const unsigned int operator__new = 0x0059C808;

			// TcpCommApp
			const unsigned int TcpCommApp = 0x006C2510;

			// WPacket TcpCommApp::GetWPacket()const
			const unsigned int TcpCommApp__GetWPacket = 0x00551440;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0054E8C0;

			// void NetIF::SendPacketMessage(LPWPACKET pk)
			const unsigned int NetIF__SendPacketMessage = 0x00519250;
		}
	}
}