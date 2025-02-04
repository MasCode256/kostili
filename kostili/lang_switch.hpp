#ifndef LANG_SWITCHER_H
#define LANG_SWITCHER_H

#define ENGLISH 0
#define RUSSIAN 1
#define BELARUSIAN 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace kostili
{
	namespace lang_switcher
	{

		class wstream
		{
		private:
		public:
			wstream()
			{
				std::setlocale(LC_ALL, "");
			}

			wstream(int ind)
			{
				std::setlocale(LC_ALL, "");
				index = ind;
			}

			wstream(unsigned int ind)
			{
				std::setlocale(LC_ALL, "");
				index = ind;
			}

			unsigned int index = 0;

			void println(const vector<wstring> &v)
			{
				if (index < v.size())
				{
					wcout << v[index] << endl;
				}
				else if (v.size() == 1)
				{
					wcout << v[0];
				}
				else
				{
					wcerr << L"Ошибка при выводе текста: индекс вне диапозона. (размер вектора: " << v.size() << L", индекс: " << index << ").";
				}
			}

			void print(const vector<wstring> &v)
			{
				if (index < v.size())
				{
					wcout << v[index];
				}
				else if (v.size() == 1)
				{
					wcout << v[0];
				}
				else
				{
					wcerr << L"Ошибка при выводе текста: индекс вне диапозона. (размер вектора: " << v.size() << L", индекс: " << index << ").";
				}
			}
		};
	}
}

#endif