// Words.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

string words[167], list[167];
bool can = true;

int lexicon(string p)
{
	setlocale(LC_ALL, "RUS");
	int k = 0;
	for (int i = 0; i < 167; i++)
	{
		k = 0;
		if (list[i] == p)
		{
			list[i] = "-";
			k++;
			continue;
		}
	}
	return k;
}

string answer (string s)
{
	setlocale(LC_ALL, "RUS");
	string ans;
	for (int i = 0; i < 167; i++)
	{
		if (words[i][0] == s[s.size() - 1])
		{
			ans = words[i];
			break;
		}
	}
	return ans;
}

int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	ifstream file1("example.txt");
	for (int i = 0; !file1.eof(); i++)
	{
		file1>>list[i];
	}
	file1.close();
	ifstream file("example.txt");
	for (int i = 0; !file.eof(); i++)
	{
		getline(file, words[i]);
	}
	file.close();
	string w;
	cin >> w;
	while (can == true)
	{
		if (lexicon(w) == 1)
		{
			cout << "Такой город уже был";
			cin >> w;
			continue;
		}
		else
		{
			cout<<answer(w);
			cin >> w;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
