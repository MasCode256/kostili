#include "kostili.hpp"

int main()
{
	std::setlocale(LC_ALL, "");

	kostili::lang_switcher::wstream log(1);
	log.println(vector<wstring>{L"Creating and encoding vexor...", L"Создание вексора..."});

	kostili::vexors::vexor vex(vector<wstring>{L"Привет, ", L"мир!"});
	vex.append(L"Всё работает!");
	vector<wstring> decoded = vex.vec();

	log.print(vector<wstring>{L"vex = " + vex.str});
	log.println(vector<wstring>{L". Decoding...", L". Декодирование..."});

	for (int i = 0; i < decoded.size() - 1; i++)
	{
		wcout << L"[iteration " << i << L"] " << decoded[i] << endl;
	}

	wcout << vex[2];
	return 0;
}
