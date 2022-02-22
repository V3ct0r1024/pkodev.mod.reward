#pragma once

namespace pkodev
{
	namespace hook
	{
		// BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
		bool __stdcall NetIF__HandlePacketMessage(void* datasock, void* pk);

		// void CItemCommand::Render(int x, int y)
		void __fastcall CItemCommand__Render(void* This, void* NotUsed, int x, int y);
	}
}