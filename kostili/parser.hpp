#ifndef PARSER_H
#define PARSER_H

#include <sstream>
#include <string>

using namespace std;

namespace kostili
{
	// Всякая парсерная дичь, без которой нельзя жить
	namespace parser
	{
		// Например, "Илья, косарь, крять" вернет "Илья"
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
		
		// Например, "Илья, косарь, крять" вернет "Илья"
		std::string get_substring_before_delimiter(const std::string &str, wchar_t delimiter)
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

		// L"3" в 3
		size_t wstr_to_unum(const wstring &str)
		{
			size_t ret;
			wstringstream s;
			s << str;
			s >> ret;
			return ret;
		}

		// 3 в L"3"
		const wstring unum_to_wstr(size_t num)
		{
			wstring ret;
			wstringstream s;
			s << num;
			s >> ret;
			return ret;
		}

		// L"3" в 3 (спасибо, кэп)
		int wstr_to_num(const wstring &str)
		{
			size_t ret;
			wstringstream s;
			s << str;
			s >> ret;
			return ret;
		}

		// 3 в L"3" (неожиданно)
		const wstring num_to_wstr(int num)
		{
			wstring ret;
			wstringstream s;
			s << num;
			s >> ret;
			return ret;
		}

		// "3" в 3
		size_t str_to_unum(const string &str)
		{
			size_t ret;
			stringstream s;
			s << str;
			s >> ret;
			return ret;
		}

		// 3 в L"3"
		const string unum_to_str(size_t num)
		{
			string ret;
			stringstream s;
			s << num;
			s >> ret;
			return ret;
		}

		// "3" в 3
		size_t str_to_num(const string &str)
		{
			int ret;
			stringstream s;
			s << str;
			s >> ret;
			return ret;
		}

		// 3 в "3" (может обрабатывать отрицательные числа, но 0 +- 2 147 483 649 не может (зависит от ОС))
		const string num_to_str(int num)
		{
			string ret;
			stringstream s;
			s << num;
			s >> ret;
			return ret;
		}
	}
}

#endif