#include "RewardForm.h"
#include "address.h"

#include <cstdio>
#include <memory>

namespace pkodev
{
	namespace gui
	{
		// CForm* CUIInterface::_FindForm(const char * frmName)
		pointer::CUIInterface___FindForm__Ptr CUIInterface___FindForm = (pointer::CUIInterface___FindForm__Ptr)(void*)(address::CUIInterface___FindForm);

		// void CForm::Show()
		pointer::CForm__Show__Ptr CForm__Show = (pointer::CForm__Show__Ptr)(void*)(address::CForm__Show);

		// void CForm::ShowModal()
		pointer::CForm__ShowModal__Ptr CForm__ShowModal = (pointer::CForm__ShowModal__Ptr)(void*)(address::CForm__ShowModal);

		// void CForm::Hide()
		pointer::CForm__Hide__Ptr CForm__Hide = (pointer::CForm__Hide__Ptr)(void*)(address::CForm__Hide);

		// CCompent* CForm::Find( const char* str )
		pointer::CForm__Find__Ptr CForm__Find = (pointer::CForm__Find__Ptr)(void*)(address::CForm__Find);
		
		// inline CItemRecord* GetItemRecordInfo( int nTypeID )
		pointer::GetItemRecordInfo__Ptr GetItemRecordInfo = (pointer::GetItemRecordInfo__Ptr)(void*)(address::GetItemRecordInfo);

		// CItemCommand::CItemCommand(CItemRecord* pItem)
		pointer::CItemCommand__CItemCommand__Ptr CItemCommand__CItemCommand = (pointer::CItemCommand__CItemCommand__Ptr)(void*)(address::CItemCommand__CItemCommand);

		// void CItemCommand::SetData(const SItemGrid& item)
		pointer::CItemCommand__SetData__Ptr CItemCommand__SetData = (pointer::CItemCommand__SetData__Ptr)(void*)(address::CItemCommand__SetData);

		// void CItemCommand::SetTotalNum(int num)
		pointer::CItemCommand__SetTotalNum__Ptr CItemCommand__SetTotalNum = (pointer::CItemCommand__SetTotalNum__Ptr)(void*)(address::CItemCommand__SetTotalNum);

		// inline void CItemCommand::SetIsSolid( bool v ) 
		pointer::CItemCommand__SetIsSolid__Ptr CItemCommand__SetIsSolid = (pointer::CItemCommand__SetIsSolid__Ptr)(void*)(address::CItemCommand__SetIsSolid);

		// void COneCommand::AddCommand( CCommandObj* p )  
		pointer::COneCommand__AddCommand__Ptr COneCommand__AddCommand = (pointer::COneCommand__AddCommand__Ptr)(void*)(address::COneCommand__AddCommand);

		// void COneCommand::DelCommand() 
		pointer::COneCommand__DelCommand__Ptr COneCommand__DelCommand = (pointer::COneCommand__DelCommand__Ptr)(void*)(address::COneCommand__DelCommand);

		// Constructor
		RewardForm::RewardForm() :
			m_frmReward(nullptr),
			m_btnAccept(nullptr),
			m_current_day(0)
		{
			for (unsigned int i = 0; i < MAX_DAYS; ++i)
			{
				m_cmdSlot[i] = nullptr;
				std::memset(reinterpret_cast<void*>(m_cmdItem[i]), 0x00, 0xEC);
			}
		}

		// Destructor
		RewardForm::~RewardForm()
		{

		}

		// Initialize the form
		bool RewardForm::init()
		{
			// Search reward form
			m_frmReward = CUIInterface___FindForm(
				reinterpret_cast<void*>(address::CUIInterface),
				"frmPrize"
			);

			// Check that form is found
			if (m_frmReward == nullptr)
			{
				return false;
			}

			// Load Apply button
			m_btnAccept = CForm__Find(m_frmReward, "btnGetPrize");

			// Check that button is found
			if (m_btnAccept == nullptr)
			{
				return false;
			}

			// Load items slots
			for (unsigned int i = 0; i < MAX_DAYS; ++i)
			{
				// Make a slot name
				char tmp[32]{ 0x00 };
				sprintf_s(tmp, sizeof(tmp), "cmdPrizeIt%d", i);

				// Search slot
				m_cmdSlot[i] = CForm__Find(m_frmReward, tmp);

				// Check that slot is found
				if (m_cmdSlot[i] == nullptr)
				{
					return false;
				}
			}

			// Load border image
			if ( m_pic_border.load("texture\\icon\\border.tga") == false )
			{
				return false;
			}

			// Load sign image
			if ( m_pic_sign.load("texture\\icon\\sign.tga") == false )
			{
				return false;
			}

			// Form is initialized!
			return true;
		}

		// Show the form
		void RewardForm::show(const reward_data& reward)
		{
			// Save current day
			m_current_day = reward.day;

			// Clear item slots
			for (unsigned int i = 0; i < MAX_DAYS; ++i)
			{
				COneCommand__DelCommand(m_cmdSlot[i]);
			}

			// Fill item slots
			for (unsigned int i = 0; (i < reward.day && i < MAX_DAYS); ++i)
			{
				// Get item info
				void* item = GetItemRecordInfo(reward.items[i].id);

				// Check that item is found
				if (item != nullptr)
				{
					// Call CItemCommand::CItemCommand() constructor
					CItemCommand__CItemCommand(reinterpret_cast<void*>(m_cmdItem[i]), item);
				
					// Set item number in the slot
					CItemCommand__SetTotalNum(reinterpret_cast<void*>(m_cmdItem[i]), reward.items[i].number);

					// Shade old rewards
					if ( (i + 1) < reward.day )
					{
						CItemCommand__SetIsSolid(reinterpret_cast<void*>(m_cmdItem[i]), false);
					}

					// Attach item command to slot
					COneCommand__AddCommand(m_cmdSlot[i], reinterpret_cast<void*>(m_cmdItem[i]));
				}
			}

			// Open form
			CForm__Show(m_frmReward);
		}

		// Close the form
		void RewardForm::close()
		{
			// Close form
			CForm__Hide(m_frmReward);
		}

		// Render item slot
		void RewardForm::render_item_slot(void* slot)
		{
			// Get item slot name
			const char* slot = c_str(
				reinterpret_cast<void*>(
					*reinterpret_cast<unsigned int*>(
						reinterpret_cast<unsigned int>(slot) + 0x0C
						)
					)
			);
		}
	}
}