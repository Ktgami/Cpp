#include <iostream>
#include "Droby.h"
#include <Windows.h>


using namespace std;

//ввод дроби
	void Droby::enter_one()
	{
		cout << "Введите дробь:" << endl;
		cout << "Числитель дроби:" << endl;
		cin >> a;
		cout << "Знаменатель дроби:" << endl;
		cin >> b;
		cout << endl;
	}
	//Процедура ввода двух дробей
	void Droby::enter_two()
	{
		cout << "Введите две дроби:" << endl;
		cout << "Числитель первой дроби:" << endl;
		cin >> a;
		cout << "Знаменатель первой дроби:" << endl;
		cin >> b;
		cout << "Числитель второй дроби:" << endl;
		cin >> c;
		cout << "Знаменатель второй дроби:" << endl;
		cin >> d;
		cout << endl;
		
	}

	//Процедура ввода показателя степени для дроби
	void Droby::power()
	{
		cout << "Введите показатель степени:" << endl;
		cin >> q;
		cout << endl;
	}
	//Процедура вычисления суммы дробей
	void Droby::summa()
	{
		if (b == d)
		{
			e = a + c;
			f = b;
		}
		else if (b != d)
		{
			a1 = a * d;
			c1 = c * b;
			e = a1 + c1;
			f = b * d;
		}
	}
	//Процедура вычисления разности дробей
	void Droby::raznost()
	{
		if (b == d)
		{
			e = a - c;
			f = b;
		}
		else if (b != d)
		{
			a1 = a * d;
			c1 = c * b;
			e = a1 - c1;
			f = b * d;
		}
	}
	//Процедура вычисления произведения дробей
	void Droby::proizvedenie()
	{
		e = a * c;
		f = b * d;
	}
	//Процедура вычисления частного от деления дробей
	void Droby::delenie()
	{
		e = a * d;
		f = b * c;
	}
	//Процедура вычисления степени дроби
	void Droby::stepen()
	{
		e = pow(a, q);
		f = pow(b, q);
		if (e%f == 0)
		{
			k = e / f;
			e = 1;
			f = 1;
		}
		if (e%f != 0)
		{
			if (e > f)
			{
				k = e / f;
				e = e - k * f;
			}
		}
	}
	//Процедура определения обратной дроби
	void Droby::obratnya()
	{
		e = b;
		f = a;
	}
	//Процедура вычисления целой части
	void Droby::CalculationDrob()
	{
		if (e%f == 0)
		{
			k = e / f;
			e = 1;
			f = 1;
		}
		if (e%f != 0)
		{
			if (e > f)
			{
				k = e / f;
				e = e - k * f;
			}

			if (e < f)
			{
				for (int l = 32767; l >= 1; l--)
				{
					if (e % l == 0 and f % l == 0)
					{
						e = e / l;
						f = f / l;
					}
				}
			}
		}
	}
	//Процедура смены знака дроби
	void Droby::smena_znaka()
	{
		e = -a;
		f = b;
	}
	//Процедура удаления данных
	void Droby::clearning()
	{
		e1 = e;
		f1 = f;
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		e = 0;
		f = 0;
		cout << "Переменные очищены" << endl;
		cout << endl;
	}
	int Droby::GetA()
	{
		return a;
	}
	int Droby::Getk()
	{
		return k;
	}
	int Droby::Gete()
	{
		return e;
	}
	int Droby::Getf()
	{
		return f;
	}
	//Процедура перед сокращением дроби
	void Droby::Socratit()
	{
		e = a;
		f = b;
		k = 0;
	}
//};


