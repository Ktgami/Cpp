#include <iostream>
#include "Droby.h"
#include <Windows.h>


using namespace std;

//���� �����
	void Droby::enter_one()
	{
		cout << "������� �����:" << endl;
		cout << "��������� �����:" << endl;
		cin >> a;
		cout << "����������� �����:" << endl;
		cin >> b;
		cout << endl;
	}
	//��������� ����� ���� ������
	void Droby::enter_two()
	{
		cout << "������� ��� �����:" << endl;
		cout << "��������� ������ �����:" << endl;
		cin >> a;
		cout << "����������� ������ �����:" << endl;
		cin >> b;
		cout << "��������� ������ �����:" << endl;
		cin >> c;
		cout << "����������� ������ �����:" << endl;
		cin >> d;
		cout << endl;
		
	}

	//��������� ����� ���������� ������� ��� �����
	void Droby::power()
	{
		cout << "������� ���������� �������:" << endl;
		cin >> q;
		cout << endl;
	}
	//��������� ���������� ����� ������
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
	//��������� ���������� �������� ������
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
	//��������� ���������� ������������ ������
	void Droby::proizvedenie()
	{
		e = a * c;
		f = b * d;
	}
	//��������� ���������� �������� �� ������� ������
	void Droby::delenie()
	{
		e = a * d;
		f = b * c;
	}
	//��������� ���������� ������� �����
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
	//��������� ����������� �������� �����
	void Droby::obratnya()
	{
		e = b;
		f = a;
	}
	//��������� ���������� ����� �����
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
	//��������� ����� ����� �����
	void Droby::smena_znaka()
	{
		e = -a;
		f = b;
	}
	//��������� �������� ������
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
		cout << "���������� �������" << endl;
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
	//��������� ����� ����������� �����
	void Droby::Socratit()
	{
		e = a;
		f = b;
		k = 0;
	}
//};


