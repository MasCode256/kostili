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
		// "Вексор" - строка, которая может быть закодирована и декодирована в линейный вектор подстрок в формате длина_подстроки:подстрока.
		//
		// Полезно при работе с бинарной информацией, где нужна экономия памяти, но бессмысленно во всех остальных случаях
		class vexor
		{
		public:
			// vexor в формате строки (не функция)
			wstring str = L"";

			// Конструктор, принимающий начальный вектор, который будет записан в vexor
			vexor(const vector<wstring> &v)
			{
				for (auto &&c : v)
				{
					str += kostili::parser::num_to_str(c.length()) + L":" + c;
				}
			}

			// Добавляет строку в конец vexor
			void append(const wstring &n)
			{
				str += kostili::parser::num_to_str(n.length()) + L":" + n;
			}

			// Возвращает элемент по индексу
			wstring operator[](int i)
			{
				vector<wstring> decoded = vec();
				if (i >= 0 && i < decoded.size())
				{
					return decoded[i];
				}
				else
				{
					// Обработка ошибки: индекс вне границ
					std::wcerr << L"Ошибка: Индекс за пределами вектора в vexor::operator[]" << std::endl;
					return L""; // Или бросьте исключение
				}
			}

			// Кодирует vexor в std::vector
			const vector<wstring> vec() const
			{
				vector<wstring> temp;

				for (size_t i = 0; i < str.length();) // Изменено условие цикла
				{
					wstring len_as_str = kostili::parser::get_substring_before_delimiter(str.substr(i), L':'); // Берем подстроку из str, начиная с текущей позиции i.
					size_t len = kostili::parser::str_to_num(len_as_str);

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
	}
}

// Перегрузка оператора << для класса vexor и std::wostream
std::wostream &operator<<(std::wostream &os, const kostili::vexors::vexor &obj)
{
	os << obj.str;
	return os;
}

// Перегрузка оператора << для класса vexor и std::wostream
std::ostream &operator<<(std::ostream &os, const kostili::vexors::vexor &obj)
{
	os << obj.str.c_str();
	return os;
}

#endif