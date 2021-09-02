#include <iostream>
#include <Windows.h>
#include "ViborResult.h"
#include "Droby.h"

using namespace std;

void ViborResult::Result()
{
	
	
		switch (vibor)
		{
		case 1:
			enter_two();
			summa();
			CalculationDrob();

			cout << "Сумма двух дробей равна: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 2:
			enter_two();
			raznost();
			CalculationDrob();
			cout << "Разность двух дробей равна: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 3:
			enter_two();
			proizvedenie();
			CalculationDrob();
			cout << "Призведение двух дробей равна: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 4:
			enter_two();
			delenie();
			CalculationDrob();
			cout << "Частное от деления двух дробей равна: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 5:
			enter_one();
			power();
			stepen();
			cout << "Дробь в степени равна: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 6:
			enter_one(); 
			obratnya();
			CalculationDrob();
			cout << "Обратная дробь равна: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 7:
			enter_one();
			Socratit();
			CalculationDrob();
			cout << "Итог: " << Gete() << '/' << Getf() << endl;
			break;
		case 8:
			enter_one();
			smena_znaka();
			CalculationDrob();
			cout << "Дробь после смены знака: " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 9:
			clearning();
			break;
		default:
			cout << "Ошибка" << endl;
			cout << endl;
		}
	
}

void ViborResult::setVibor(int n)
{
	vibor = n;
}
