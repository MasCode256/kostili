#ifndef VEXOR_H
#define VEXOR_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "parser.hpp"

using namespace std;
using namespace kostili;

namespace kostili
{
	namespace vexors
	{
		// "Вексор" - строка (конкретно эта - расширенная), которая может быть закодирована и декодирована в линейный вектор подстрок в формате длина_подстроки:подстрока.
		//
		// Полезно при работе с бинарной информацией, где нужна экономия памяти, но бессмысленно во всех остальных случаях
		class wvexor
		{
		public:
			// vexor в формате строки (не функция)
			wstring str = L"";

			// Конструктор, принимающий начальный вектор, который будет записан в vexor
			inline wvexor(const vector<wstring> &v)
			{
				append(v);
			}

			// Добавляет строку в конец vexor
			inline void append(const wstring &n)
			{
				str += kostili::parser::unum_to_wstr(n.length()) + L":" + n;
			}

			// Добавляет вектор в конец vexor
			inline void append(const vector<wstring> &v)
			{
				for (auto &&c : v)
				{
					str += kostili::parser::unum_to_wstr(c.length()) + L":" + c;
				}
			}

			// vector в vexor (заменяет vexor вектором)
			inline void encode(const vector<wstring> &v)
			{
				str = L"";
				append(v);
			}

			// Возвращает элемент по индексу
			inline wstring operator[](int i)
			{
				vector<wstring> v = decode();
				if (i >= 0 && i < v.size())
				{
					return v[i];
				}
				else
				{
					// Обработка ошибки: индекс вне границ
					std::wcerr << L"Ошибка: Индекс за пределами вектора в vexor::operator[]" << std::endl;
					return L""; // Или бросьте исключение
				}
			}

			// Кодирует vexor в std::vector
			const vector<wstring> decode() const
			{
				vector<wstring> temp;

				for (size_t i = 0; i < str.length();) // Изменено условие цикла
				{
					wstring len_as_str = kostili::parser::get_substring_before_delimiter(str.substr(i), L':'); // Берем подстроку из str, начиная с текущей позиции i.
					size_t len = kostili::parser::wstr_to_unum(len_as_str);

					size_t start_pos = i + len_as_str.length() + 1; // Вычисляем начальную позицию подстроки в str

					if (start_pos + len > str.length())
					{ // Проверка выхода за границы str
						// Обработка ошибки: строка имеет неверный формат
						std::wcerr << L"Ошибка: Неверный формат строки vexor. Длина подстроки превышает длину строки." << std::endl;
						return {}; // Возвращаем пустой вектор, чтобы обозначить ошибку
					}

					temp.push_back(str.substr(start_pos, len)); // Используем start_pos и len для извлечения подстроки
					i = start_pos + len;						// Перемещаем i к началу следующей подстроки
				}

				return temp;
			}
		};

		// "Вексор" - строка (конкретно эта - расширенная), которая может быть закодирована и декодирована в линейный вектор подстрок в формате длина_подстроки:подстрока.
		//
		// Полезно при работе с бинарной информацией, где нужна экономия памяти, но бессмысленно во всех остальных случаях
		class vexor
		{
		public:
			// vexor в формате строки (не функция)
			string str = "";

			// Конструктор, принимающий начальный вектор, который будет записан в vexor
			inline vexor(const vector<string> &v)
			{
				append(v);
			}

			// Добавляет строку в конец vexor
			inline void append(const string &n)
			{
				str += kostili::parser::unum_to_str(n.length()) + ":" + n;
			}

			// Добавляет вектор в конец vexor
			inline void append(const vector<string> &v)
			{
				for (auto &&c : v)
				{
					str += kostili::parser::unum_to_str(c.length()) + ":" + c;
				}
			}

			// vector в vexor (заменяет vexor вектором)
			inline void encode(const vector<string> &v)
			{
				str = "";
				append(v);
			}

			// Возвращает элемент по индексу
			inline string operator[](int i)
			{
				vector<string> v = decode();
				if (i >= 0 && i < v.size())
				{
					return v[i];
				}
				else
				{
					// Обработка ошибки: индекс вне границ
					std::cerr << "Ошибка: Индекс за пределами вектора в vexor::operator[]" << std::endl;
					return ""; // Или бросьте исключение
				}
			}

			// Кодирует vexor в std::vector
			const vector<string> decode() const
			{
				vector<string> temp;

				for (size_t i = 0; i < str.length();) // Изменено условие цикла
				{
					string len_as_str = kostili::parser::get_substring_before_delimiter(str.substr(i), L':'); // Берем подстроку из str, начиная с текущей позиции i.
					size_t len = kostili::parser::str_to_unum(len_as_str);

					size_t start_pos = i + len_as_str.length() + 1; // Вычисляем начальную позицию подстроки в str

					if (start_pos + len > str.length())
					{ // Проверка выхода за границы str
						// Обработка ошибки: строка имеет неверный формат
						std::wcerr << "Ошибка: Неверный формат строки vexor. Длина подстроки превышает длину строки." << std::endl;
						return {}; // Возвращаем пустой вектор, чтобы обозначить ошибку
					}

					temp.push_back(str.substr(start_pos, len)); // Используем start_pos и len для извлечения подстроки
					i = start_pos + len;						// Перемещаем i к началу следующей подстроки
				}

				return temp;
			}
		};
	}
}

// Перегрузка оператора << для класса wvexor и std::wostream
std::wostream &operator<<(std::wostream &os, const kostili::vexors::wvexor &obj)
{
	os << obj.str;
	return os;
}

// Перегрузка оператора << для класса wvexor и std::ostream
std::ostream &operator<<(std::ostream &os, const kostili::vexors::wvexor &obj)
{
	os << obj.str.c_str();
	return os;
}

// Перегрузка оператора << для класса vexor и std::ostream
std::ostream &operator<<(std::ostream &os, const kostili::vexors::vexor &obj)
{
	os << obj.str;
	return os;
}

#endif