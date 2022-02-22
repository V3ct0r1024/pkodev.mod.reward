#pragma once

namespace pkodev
{
	namespace address
	{
		// GameServer.exe 1.36
		namespace GAMESERVER_136
		{
			// dbc::TcpCommApp
			const unsigned int TcpCommApp = 0x0076D8FC;

			// WPacket TcpCommApp::GetWPacket() const
			const unsigned int TcpCommApp__GetWPacket = 0x00520950;

			// WPacket::WPacket
			const unsigned int WPacket__WPacket = 0x0041C950;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x0051A6B0;

			// bool WPacket::WriteShort(uShort sh)
			const unsigned int WPacket__WriteShort = 0x0051B7A0;

			// bool WPacket::WriteLong(uLong lo)
			const unsigned int WPacket__WriteLong = 0x0051B8B0;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0051BAD0;

			// uShort RPacket::ReadShort()
			const unsigned int RPacket__ReadShort = 0x0051A870;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x0051A8F0;

			// cChar *RPacket::ReadString(uShort *len)
			const unsigned int RPacket__ReadString = 0x0051A9C0;

			// void CCharacter::ReflectINFof(Entity *srcent, WPACKET chginf)
			const unsigned int CCharacter__ReflectINFof = 0x004BCFF0;

			// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
			const unsigned int CCharacter__ProcessPacket = 0x004DDC50;

			// bool CCharacter::Cmd_EnterMap(cChar* l_map, Long lMapCopyNO, uLong l_x, uLong l_y, Char chLogin)
			const unsigned int CCharacter__Cmd_EnterMap = 0x004D39C0;

			// BOOL CCharacter::AddItem( USHORT sItemID, USHORT sCount, const char szName[], BYTE byAddType, BYTE bySoundType )
			const unsigned int CCharacter__AddItem = 0x004C7510;

			// BOOL CCharacter::AddItem2KitbagTemp( USHORT sItemID, USHORT sCount, const char szName[], BYTE byAddType = enumITEM_INST_TASK, BYTE bySoundType = enumSYN_KITBAG_FROM_NPC )
			const unsigned  int CCharacter__AddItem2KitbagTemp = 0x004C77F0;

			// short CKitbag::GetCapacity()
			const unsigned int CKitbag__GetCapacity = 0x00415E50;

			// short CKitbag::GetUseGridNum(short sType)
			const unsigned int CKitbag__GetUseGridNum = 0x00415D00;

			// CGameDB
			const unsigned int CGameDB = 0x70FA28;

			// SQLRETURN __stdcall SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
			const unsigned int SQLAllocHandle = 0x0055E1FA;

			// SQLRETURN __stdcall SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
			const unsigned int SQLExecDirect = 0x0055E1F4;

			// SQLRETURN __stdcall SQLNumResultCols(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount)
			const unsigned int SQLNumResultCols = 0x0055E1EE;

			// SQLRETURN __stdcall SQLBindCol(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType, SQLPOINTER TargetValue, SQLINTEGER BufferLength, SQLINTEGER *StrLen_or_Ind)
			const unsigned int SQLBindCol = 0x0055E1E8;

			// SQLRETURN __stdcall SQLFetch(SQLHSTMT StatementHandle)
			const unsigned int SQLFetch = 0x0055E1E2;

			// SQLRETURN __stdcall SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option)
			const unsigned int SQLFreeStmt = 0x0055E1DC;

			// SQLRETURN __stdcall SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
			const unsigned int SQLFreeHandle = 0x0055E1D6;

			// SQLRETURN cfl_rs::exec_sql_direct(char const* sql, unsigned short timeout /* = 5 */)
			const unsigned int cfl_rs__exec_sql_direct = 0x00538300;

			// CParser
			const unsigned int CParser = 0x00604378;

			// int CParser::DoString(const char *csString, char chRetType, int nRetNum, ...)
			const unsigned int CParser__DoString = 0x004553D0;

			// int CParser::GetReturnNumber(char chID)
			const unsigned int CParser__GetReturnNumber = 0x00492780;
		}

		// GameServer.exe 1.38
		namespace GAMESERVER_138
		{
			// dbc::TcpCommApp
			const unsigned int TcpCommApp = 0x0077984C;

			// WPacket TcpCommApp::GetWPacket() const
			const unsigned int TcpCommApp__GetWPacket = 0x00529CE0;

			// WPacket::WPacket
			const unsigned int WPacket__WPacket = 0x0041DBD0;

			// bool WPacket::WriteCmd(uShort cmd)
			const unsigned int WPacket__WriteCmd = 0x00523A40;

			// bool WPacket::WriteShort(uShort sh)
			const unsigned int WPacket__WriteShort = 0x00524B30;

			// bool WPacket::WriteLong(uLong lo)
			const unsigned int WPacket__WriteLong = 0x00524C40;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x00524E60;

			// uShort RPacket::ReadShort()
			const unsigned int RPacket__ReadShort = 0x00523C00;

			// uLong RPacket::ReadLong()
			const unsigned int RPacket__ReadLong = 0x00523C80;

			// cChar *RPacket::ReadString(uShort *len)
			const unsigned int RPacket__ReadString = 0x00523D50;

			// void CCharacter::ReflectINFof(Entity *srcent, WPACKET chginf)
			const unsigned int CCharacter__ReflectINFof = 0x004C4580;

			// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
			const unsigned int CCharacter__ProcessPacket = 0x004E62A0;

			// bool CCharacter::Cmd_EnterMap(cChar* l_map, Long lMapCopyNO, uLong l_x, uLong l_y, Char chLogin)
			const unsigned int CCharacter__Cmd_EnterMap = 0x004DB730;

			// BOOL CCharacter::AddItem( USHORT sItemID, USHORT sCount, const char szName[], BYTE byAddType, BYTE bySoundType )
			const unsigned int CCharacter__AddItem = 0x004CEC80;

			// BOOL CCharacter::AddItem2KitbagTemp( USHORT sItemID, USHORT sCount, const char szName[], BYTE byAddType = enumITEM_INST_TASK, BYTE bySoundType = enumSYN_KITBAG_FROM_NPC )
			const unsigned  int CCharacter__AddItem2KitbagTemp = 0x004CEFB0;

			// short CKitbag::GetCapacity()
			const unsigned int CKitbag__GetCapacity = 0x00417070;

			// short CKitbag::GetUseGridNum(short sType)
			const unsigned int CKitbag__GetUseGridNum = 0x00416F20;

			// CGameDB
			const unsigned int CGameDB = 0x0071B848;

			// SQLRETURN __stdcall SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
			const unsigned int SQLAllocHandle = 0x0056A60C;

			// SQLRETURN __stdcall SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
			const unsigned int SQLExecDirect = 0x0056A606;

			// SQLRETURN __stdcall SQLNumResultCols(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount)
			const unsigned int SQLNumResultCols = 0x0056A600;

			// SQLRETURN __stdcall SQLBindCol(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType, SQLPOINTER TargetValue, SQLINTEGER BufferLength, SQLINTEGER *StrLen_or_Ind)
			const unsigned int SQLBindCol = 0x0056A5FA;

			// SQLRETURN __stdcall SQLFetch(SQLHSTMT StatementHandle)
			const unsigned int SQLFetch = 0x0056A5F4;

			// SQLRETURN __stdcall SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option)
			const unsigned int SQLFreeStmt = 0x0056A5EE;

			// SQLRETURN __stdcall SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
			const unsigned int SQLFreeHandle = 0x0056A5E8;

			// SQLRETURN cfl_rs::exec_sql_direct(char const* sql, unsigned short timeout /* = 5 */)
			const unsigned int cfl_rs__exec_sql_direct = 0x005453F0;

			// CParser
			const unsigned int CParser = 0x00610198;

			// int CParser::DoString(const char *csString, char chRetType, int nRetNum, ...)
			const unsigned int CParser__DoString = 0x00457E60;

			// int CParser::GetReturnNumber(char chID)
			const unsigned int CParser__GetReturnNumber = 0x00499C60;
		}
	}
}