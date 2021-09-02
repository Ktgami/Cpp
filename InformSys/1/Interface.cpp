#include <iostream>
#include "Interface.h"
#include <Windows.h>

using namespace std;

void Interface::Menu()
{
	cout << "Сложение дробей-введите 1" << endl;
	cout << "Вычитание дробей-введите 2" << endl;
	cout << "Произведение дробей-введите 3" << endl;
	cout << "Деление дробей-введите 4" << endl;
	cout << "Возведение дроби в степень-введите 5" << endl;
	cout << "Обращение дроби-введите 6" << endl;
	cout << "Сокращение дроби-введите 7" << endl;
	cout << "Смена знака дроби-введите 8" << endl;
	cout << "Сброс переменных-введите 9" << endl;
	cout << endl;
	cin >> n;
	cout << endl;
}
