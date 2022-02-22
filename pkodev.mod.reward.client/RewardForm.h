#pragma once
#include "structure.h"
#include "Picture.h"

namespace pkodev
{
	namespace pointer
	{
		// CForm* CUIInterface::_FindForm(const char * frmName)
		typedef void* (__thiscall* CUIInterface___FindForm__Ptr)(void*, const char*);

		// void CForm::Show()
		typedef void(__thiscall* CForm__Show__Ptr)(void*);

		// void CForm::ShowModal()
		typedef void(__thiscall* CForm__ShowModal__Ptr)(void*);

		// void CForm::Hide()
		typedef void(__thiscall* CForm__Hide__Ptr)(void*);

		// CCompent* CForm::Find( const char* str )
		typedef void* (__thiscall* CForm__Find__Ptr)(void*, const char*);

		// inline CItemRecord* GetItemRecordInfo( int nTypeID )
		typedef void* (__cdecl* GetItemRecordInfo__Ptr)(int);

		// CItemCommand::CItemCommand(CItemRecord* pItem)
		typedef void(__thiscall* CItemCommand__CItemCommand__Ptr)(void*, void*);

		// void CItemCommand::SetData(const SItemGrid& item)
		typedef void(__thiscall* CItemCommand__SetData__Ptr)(void*, void*);

		// void CItemCommand::SetTotalNum(int num)
		typedef void(__thiscall* CItemCommand__SetTotalNum__Ptr)(void*, int);

		// inline void CItemCommand::SetIsSolid( bool v ) 
		typedef void(__thiscall* CItemCommand__SetIsSolid__Ptr)(void*, bool);

		// void COneCommand::AddCommand( CCommandObj* p )  
		typedef void(__thiscall* COneCommand__AddCommand__Ptr)(void*, void*);

		// void COneCommand::DelCommand() 
		typedef void(__thiscall* COneCommand__DelCommand__Ptr)(void*);
	}

	namespace gui
	{
		// Reward form
		class RewardForm
		{
			public:

				// Constructor
				RewardForm();

				// Copy constructor
				RewardForm(const RewardForm&) = delete;

				// Move constructor
				RewardForm(RewardForm&&) = delete;

				// Destructor
				~RewardForm();

				// Copy assigment operator
				RewardForm& operator=(const RewardForm&) = delete;

				// Move assigment operator
				RewardForm& operator=(RewardForm&) = delete;

				// Initialize the form
				bool init();

				// Show the form
				void show(const reward_data& reward);

				// Close the form
				void close();

				// Render item slot
				void render_item_slot(void* slot, unsigned int n);

			private:

				// Form
				void* m_frmReward;

				// Accept button
				void* m_btnAccept;

				// Items slots x 7
				void* m_cmdSlot[MAX_DAYS];

				// Item commands x 7
				char m_cmdItem[MAX_DAYS][0xEC];

				// Border image
				Picture m_pic_border;

				// Sign image
				Picture m_pic_sign;

				// Current day
				unsigned int m_current_day;
		};
	}
}
