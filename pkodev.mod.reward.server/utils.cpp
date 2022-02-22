#include "utils.h"

namespace pkodev
{
	namespace utils
	{
		// Remove leading whitespace from a string
		std::string utils::string::left_trim(const std::string& str, const std::string& whitespace)
		{
			// Looking for whitespaces at the beginning of a string
			std::size_t pos = str.find_first_not_of(whitespace);

			// Remove spaces at the beginning of a string
			if (std::string::npos != pos)
			{
				return str.substr(pos);
			}

			return str;
		}

		// Remove trailing whitespace from a string
		std::string utils::string::right_trim(const std::string& str, const std::string& whitespace)
		{
			// Looking for whitespaces at the end of a string
			std::size_t pos = str.find_last_not_of(whitespace);

			// Remove spaces at the end of a string
			if (std::string::npos != pos)
			{
				return str.substr(0, pos + 1);
			}

			return str;
		}

		// Remove leading and trailing whitespace from a string
		std::string utils::string::trim(const std::string& str, const std::string& whitespace)
		{
			return left_trim(right_trim(str, whitespace), whitespace);
		}

		// Split a string by a delimiter
		std::vector<std::string> utils::string::explode(const std::string& str, char delim)
		{
			std::vector<std::string> strings;
			size_t start = 0;
			size_t end = 0;

			while ( ( start = str.find_first_not_of(delim, end) ) != std::string::npos )
			{
				end = str.find(delim, start);
				strings.push_back(str.substr(start, end - start));
			}

			return strings;
		}
	}
}