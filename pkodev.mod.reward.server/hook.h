#pragma once

namespace pkodev
{
	namespace hook
	{
		// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
		void __fastcall CCharacter__ProcessPacket(void* This, void* NotUsed, unsigned short int usCmd, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16);

		// bool CCharacter::Cmd_EnterMap(cChar* l_map, Long lMapCopyNO, uLong l_x, uLong l_y, Char chLogin)
		bool __fastcall CCharacter__Cmd_EnterMap(void* This, void* NotUsed, const char* mapname, int copyno, int x, int y, bool logged);
	}
}