#pragma once

namespace pkodev
{
	// Maxmimum nubmer ofdays in a chain
	const unsigned int MAX_DAYS = 7;

	// Item data
	struct item
	{
		// ID
		unsigned int id;

		// Amount
		unsigned int number;

		// Constructor
		item() :
			id(9999), number(0) { }

		// Constructor
		item(unsigned int id_, unsigned int number_) :
			id(id_), number(number_) { }
	};

	// Daily award form data
	struct reward_data
	{
		// Day
		unsigned int day;

		// Days
		item items[MAX_DAYS];

		// Constructor
		reward_data() :
			day(0) { }
	};
}