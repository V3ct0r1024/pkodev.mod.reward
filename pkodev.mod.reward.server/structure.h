#pragma once
#include <string>
#include <vector>
#include "utils.h"

namespace pkodev
{
	// Parameters ending flag for CParser::DoString() call
	const unsigned int DOSTRING_PARAM_END = 999999999;

	// Parameters types for CParser::DoString() call
	enum EScriptParamType
	{
		enumSCRIPT_PARAM_NUMBER = 1,
		enumSCRIPT_PARAM_NUMBER_UNSIGNED,
		enumSCRIPT_PARAM_LIGHTUSERDATA,
		enumSCRIPT_PARAM_STRING,
		enumSCRIPT_PARAM_NUMBER_LONG64,
	};

	// Returns types for CParser::DoString() call
	enum EScriptReturnType
	{
		enumSCRIPT_RETURN_NONE,
		enumSCRIPT_RETURN_NUMBER,
		enumSCRIPT_RETURN_STRING,
	};

	// Daily reward data structure
	struct reward final
	{
		// Reward interval in seconds
		static const unsigned int interval{ 8 /* * 24 * 60 * 60 */}; // 24 hours

		// Max days in a streak
		static const unsigned short int max_days{ 7 };

		// Current day (1 - 7, 0 = uninitialized)
		unsigned short int day;

		// Reward time
		unsigned long long time;

		// Item slot structure
		struct slot final
		{
			// Item ID
			unsigned int id;

			// Amount
			unsigned int number;

			// Constructor 
			slot() :
				id(0), number(0) { }

			// Constructor
			slot(unsigned int id_, unsigned int number_) :
				id(id_), number(number_) { }
		} 
		items[max_days];

		// Constructor
		reward() :
			day(0), 
			time(0)
		{
		
		}

		// Convert struct reward to std::string
		std::string to_string() const
		{
			// Temporary buffer
			char buf[128]{ 0x00 };

			// Build reward data string
			sprintf_s(
				buf,
				sizeof(buf),
				"%d;%I64u;%d,%d;%d,%d;%d,%d;%d,%d;%d,%d;%d,%d;%d,%d",
				day,
				time,
				items[0].id, items[0].number,	// Day 1
				items[1].id, items[1].number,	// Day 2
				items[2].id, items[2].number,	// Day 3
				items[3].id, items[3].number,	// Day 4
				items[4].id, items[4].number,	// Day 5
				items[5].id, items[5].number,	// Day 6
				items[6].id, items[6].number	// Day 7
			);

			// Return string
			return std::string(buf);
		}

		// Convert std::string to struct reward
		void from_string(const std::string& str)
		{
			// Split string by ';'
			std::vector<std::string> data = pkodev::utils::string::explode(str, ';');

			// Check that substrings number is 9
			if (data.size() == 9)
			{
				// Helper lambda function to get item id and amount from string "id,amount"
				auto str2item = [](const std::string& raw) -> slot
				{
					// Search comma
					std::size_t pos = raw.find(',');

					// Check that comma is found
					if (pos != std::string::npos)
					{
						// Get item ID and amount from string
						unsigned int id = std::stoul(raw.substr(0, pos));
						unsigned int number = std::stoul(raw.substr(pos + 1, raw.length()));

						// Return item
						return { id, number };
					}

					// Return empty item
					return slot();
				};

				// Parse day
				day = static_cast<unsigned short int>(std::stoul(data[0]));

				// Parse time
				time = std::stoull(data[1]);

				// Parse items
				for (unsigned int i = 0; i < max_days; ++i)
				{
					items[i] = str2item(data[i + 2]);
				}
			}
		}
	};
}