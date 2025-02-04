#include "kostili.hpp"

int main()
{
	std::setlocale(LC_ALL, "");

	kostili::lang_switcher::wstream log(RUSSIAN);
	log.println(vector<wstring>{L"Creating and encoding vexor...", L"Создание вексора..."});

	kostili::vexors::vexor vex(vector<wstring>{L"Привет, ", L"мир!"});
	vex.append(L"Всё работает!");
	vector<wstring> decoded = vex.vec();

	wcout << vex << endl;

	for (int i = 0; i < decoded.size() - 1; i++)
	{
		wcout << L"[iteration " << i << L"] " << decoded[i] << endl;
	}

	wcout << vex[2];
	return 0;
}
