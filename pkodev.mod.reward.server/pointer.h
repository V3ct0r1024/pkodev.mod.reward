#pragma once
#include "address.h"

namespace pkodev
{
	namespace pointer
	{
		// WPacket TcpCommApp::GetWPacket() const
		typedef int (__thiscall* TcpCommApp__GetWPacket__Ptr)(void*, void*);
		TcpCommApp__GetWPacket__Ptr TcpCommApp__GetWPacket = (TcpCommApp__GetWPacket__Ptr)(void*)(address::MOD_EXE_VERSION::TcpCommApp__GetWPacket);

		// WPacket::WPacket
		typedef void*(__thiscall* WPacket__WPacket__Ptr)(void*, void*);
		WPacket__WPacket__Ptr WPacket__WPacket = (WPacket__WPacket__Ptr)(void*)(address::MOD_EXE_VERSION::WPacket__WPacket);

		// bool WPacket::WriteCmd(uShort cmd)
		typedef bool (__thiscall* WPacket__WriteCmd__Ptr)(void*, unsigned short int);
		WPacket__WriteCmd__Ptr WPacket__WriteCmd = (WPacket__WriteCmd__Ptr)(void*)(address::MOD_EXE_VERSION::WPacket__WriteCmd);

		// bool WPacket::WriteShort(uShort sh)
		typedef bool(__thiscall* WPacket__WriteShort__Ptr)(void*, unsigned short int);
		WPacket__WriteShort__Ptr WPacket__WriteShort = (WPacket__WriteShort__Ptr)(void*)(address::MOD_EXE_VERSION::WPacket__WriteShort);

		// bool WPacket::WriteLong(uLong lo)
		typedef bool(__thiscall* WPacket__WriteLong__Ptr)(void*, unsigned int);
		WPacket__WriteLong__Ptr WPacket__WriteLong = (WPacket__WriteLong__Ptr)(void*)(address::MOD_EXE_VERSION::WPacket__WriteLong);

		// bool WPacket::WriteString(cChar *str)
		typedef bool(__thiscall* WPacket__WriteString__Ptr)(void*, const char*);
		WPacket__WriteString__Ptr WPacket__WriteString = (WPacket__WriteString__Ptr)(void*)(address::MOD_EXE_VERSION::WPacket__WriteString);

		// uShort RPacket::ReadShort()
		typedef unsigned short int(__thiscall* RPacket__ReadShort__Ptr)(void*);
		RPacket__ReadShort__Ptr RPacket__ReadShort = (RPacket__ReadShort__Ptr)(void*)(address::MOD_EXE_VERSION::RPacket__ReadShort);

		// uLong RPacket::ReadLong()
		typedef unsigned int(__thiscall* RPacket__ReadLong__Ptr)(void*);
		RPacket__ReadLong__Ptr RPacket__ReadLong = (RPacket__ReadLong__Ptr)(void*)(address::MOD_EXE_VERSION::RPacket__ReadLong);
		
		// cChar RPacket::ReadString()
		typedef const char *(__thiscall* RPacket__ReadString__Ptr)(void*, unsigned short int *);
		RPacket__ReadString__Ptr RPacket__ReadString = (RPacket__ReadString__Ptr)(void*)(address::MOD_EXE_VERSION::RPacket__ReadString);

		// void CCharacter::ReflectINFof(Entity *srcent, WPACKET chginf)
		typedef void(__thiscall* CCharacter__ReflectINFof__Ptr)(void*, void*, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
		CCharacter__ReflectINFof__Ptr CCharacter__ReflectINFof = (CCharacter__ReflectINFof__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__ReflectINFof);

		// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
		typedef void(__thiscall* CCharacter__ProcessPacket__Ptr)(void*, unsigned short int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
		CCharacter__ProcessPacket__Ptr CCharacter__ProcessPacket = (CCharacter__ProcessPacket__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__ProcessPacket);

		// bool CCharacter::Cmd_EnterMap(cChar* l_map, Long lMapCopyNO, uLong l_x, uLong l_y, Char chLogin)
		typedef bool(__thiscall* CCharacter__Cmd_EnterMap__Ptr)(void*, const char *, int, int, int, bool);
		CCharacter__Cmd_EnterMap__Ptr CCharacter__Cmd_EnterMap = (CCharacter__Cmd_EnterMap__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__Cmd_EnterMap);

		// BOOL CCharacter::AddItem( USHORT sItemID, USHORT sCount, const char szName[], BYTE byAddType, BYTE bySoundType )
		typedef bool(__thiscall* CCharacter__AddItem__Ptr)(void*, unsigned short int, unsigned short int, const char*, char, char);
		CCharacter__AddItem__Ptr CCharacter__AddItem = (CCharacter__AddItem__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__AddItem);

		// AddItem2KitbagTemp( USHORT sItemID, USHORT sCount, const char szName[], BYTE byAddType = enumITEM_INST_TASK, BYTE bySoundType = enumSYN_KITBAG_FROM_NPC )
		typedef bool(__thiscall* CCharacter__AddItem2KitbagTemp__Ptr)(void*, unsigned short int, unsigned short int, const char*, char, char);
		CCharacter__AddItem2KitbagTemp__Ptr CCharacter__AddItem2KitbagTemp = (CCharacter__AddItem2KitbagTemp__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__AddItem2KitbagTemp);

		// short CKitbag::GetCapacity()
		typedef unsigned short int(__thiscall* CKitbag__GetCapacity__Ptr)(void*);
		CKitbag__GetCapacity__Ptr CKitbag__GetCapacity = (CKitbag__GetCapacity__Ptr)(void*)(address::MOD_EXE_VERSION::CKitbag__GetCapacity);

		// short CKitbag::GetUseGridNum(short sType)
		typedef unsigned short int(__thiscall* CKitbag__GetUseGridNum__Ptr)(void*, short int);
		CKitbag__GetUseGridNum__Ptr CKitbag__GetUseGridNum = (CKitbag__GetUseGridNum__Ptr)(void*)(address::MOD_EXE_VERSION::CKitbag__GetUseGridNum);

		// SQLRETURN __stdcall SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
		typedef short int(__stdcall* SQLAllocHandle__Ptr)(int, int, int*);
		SQLAllocHandle__Ptr SQLAllocHandle = (SQLAllocHandle__Ptr)(void*)(address::MOD_EXE_VERSION::SQLAllocHandle);

		// SQLRETURN __stdcall SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
		typedef short int(__stdcall* SQLExecDirect__Ptr)(int, const char*, int);
		SQLExecDirect__Ptr SQLExecDirect = (SQLExecDirect__Ptr)(void*)(address::MOD_EXE_VERSION::SQLExecDirect);

		// SQLRETURN __stdcall SQLNumResultCols(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount)
		typedef short int(__stdcall* SQLNumResultCols__Ptr)(int, int*);
		SQLNumResultCols__Ptr SQLNumResultCols = (SQLNumResultCols__Ptr)(void*)(address::MOD_EXE_VERSION::SQLNumResultCols);

		// SQLRETURN __stdcall SQLBindCol(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType, SQLPOINTER TargetValue, SQLINTEGER BufferLength, SQLINTEGER *StrLen_or_Ind)
		typedef short int(__stdcall* SQLBindCol__Ptr)(int, int, int, int, int, int*);
		SQLBindCol__Ptr SQLBindCol = (SQLBindCol__Ptr)(void*)(address::MOD_EXE_VERSION::SQLBindCol);

		// SQLRETURN __stdcall SQLFetch(SQLHSTMT StatementHandle)
		typedef short int(__stdcall* SQLFetch__Ptr)(int);
		SQLFetch__Ptr SQLFetch = (SQLFetch__Ptr)(void*)(address::MOD_EXE_VERSION::SQLFetch);

		// SQLRETURN __stdcall SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option)
		typedef short int(__stdcall* SQLFreeStmt__Ptr)(int, int);
		SQLFreeStmt__Ptr SQLFreeStmt = (SQLFreeStmt__Ptr)(void*)(address::MOD_EXE_VERSION::SQLFreeStmt);

		// SQLRETURN __stdcall SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
		typedef short int(__stdcall* SQLFreeHandle__Ptr)(int, int);
		SQLFreeHandle__Ptr SQLFreeHandle = (SQLFreeHandle__Ptr)(void*)(address::MOD_EXE_VERSION::SQLFreeHandle);

		// SQLRETURN cfl_rs::exec_sql_direct(char const* sql, unsigned short timeout /* = 5 */)
		typedef short int(__thiscall* cfl_rs__exec_sql_direct__Ptr)(void*, const char*, unsigned short);
		cfl_rs__exec_sql_direct__Ptr cfl_rs__exec_sql_direct = (cfl_rs__exec_sql_direct__Ptr)(void*)(address::MOD_EXE_VERSION::cfl_rs__exec_sql_direct);

		// int CParser::DoString(const char *csString, char chRetType, int nRetNum, ...)
		typedef int(__cdecl* CParser__DoString__Ptr)(void*, const char*, char, int, ...);
		CParser__DoString__Ptr CParser__DoString = (CParser__DoString__Ptr)(void*)(address::MOD_EXE_VERSION::CParser__DoString);

		// int CParser::GetReturnNumber(char chID)
		typedef int(__thiscall* CParser__GetReturnNumber__Ptr)(void*, int);
		CParser__GetReturnNumber__Ptr CParser__GetReturnNumber = (CParser__GetReturnNumber__Ptr)(void*)(address::MOD_EXE_VERSION::CParser__GetReturnNumber);
	}
}