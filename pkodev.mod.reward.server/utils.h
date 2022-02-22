#pragma once
#include <string>
#include <vector>

namespace pkodev
{
	namespace utils
	{
		// Helper functions for working with strings
		class string
		{
			public:
				// Remove leading whitespace from a string
				static std::string left_trim(const std::string& str, const std::string& whitespace = " \t");

				// Remove trailing whitespace from a string
				static std::string right_trim(const std::string& str, const std::string& whitespace = " \t");

				// Remove leading and trailing whitespace from a string
				static std::string trim(const std::string& str, const std::string& whitespace = " \t");

				// Split a string by a delimiter
				static std::vector<std::string> explode(const std::string& str, char delim);

		};
	}

}

