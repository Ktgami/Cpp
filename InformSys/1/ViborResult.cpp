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

			cout << "����� ���� ������ �����: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 2:
			enter_two();
			raznost();
			CalculationDrob();
			cout << "�������� ���� ������ �����: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 3:
			enter_two();
			proizvedenie();
			CalculationDrob();
			cout << "����������� ���� ������ �����: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 4:
			enter_two();
			delenie();
			CalculationDrob();
			cout << "������� �� ������� ���� ������ �����: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 5:
			enter_one();
			power();
			stepen();
			cout << "����� � ������� �����: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 6:
			enter_one(); 
			obratnya();
			CalculationDrob();
			cout << "�������� ����� �����: " << Getk() << "  " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 7:
			enter_one();
			Socratit();
			CalculationDrob();
			cout << "����: " << Gete() << '/' << Getf() << endl;
			break;
		case 8:
			enter_one();
			smena_znaka();
			CalculationDrob();
			cout << "����� ����� ����� �����: " << Gete() << '/' << Getf() << endl;
			cout << endl;
			break;
		case 9:
			clearning();
			break;
		default:
			cout << "������" << endl;
			cout << endl;
		}
	
}

void ViborResult::setVibor(int n)
{
	vibor = n;
}
