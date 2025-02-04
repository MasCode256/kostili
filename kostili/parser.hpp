#ifndef PARSER_H
#define PARSER_H

#include <sstream>
#include <string>

using namespace std;

namespace kostili
{
	namespace parser
	{
		std::wstring get_substring_before_delimiter(const std::wstring &str, wchar_t delimiter)
		{
			// Находим позицию первого вхождения разделителя
			size_t pos = str.find(delimiter);

			// Если разделитель не найден, возвращаем всю строку
			if (pos == std::wstring::npos)
			{
				return str;
			}

			// Иначе, возвращаем подстроку от начала строки до разделителя
			return str.substr(0, pos);
		}

		size_t str_to_num(const wstring &str)
		{
			size_t ret;
			wstringstream s;
			s << str;
			s >> ret;
			return ret;
		}

		const wstring num_to_str(size_t num)
		{
			wstring ret;
			wstringstream s;
			s << num;
			s >> ret;
			return ret;
		}
	}
}

#endif