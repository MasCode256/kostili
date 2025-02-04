#include "../kostili.hpp"

int main()
{
	std::setlocale(LC_ALL, "");

	kostili::lang_switcher::wstream log(RUSSIAN);
	log.println(vector<wstring>{L"Creating and encoding vexor...", L"Создание вексора..."});

	kostili::vexors::wvexor vex(vector<wstring>{L"Эту строку никто не увидит..."});
	vex.encode(vector<wstring>{L"Привет, ", L"мир!"});
	vex.append(L"Всё работает!");

	wcout << vex << endl;
	for (auto &&c : vex.decode())
	{
		wcout << c;
	}

	wcout << vex[2];
	return 0;
}
