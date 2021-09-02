#include "Schedule.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>



std::fstream F, FS;
std::fstream clear_file;
std::string line, line_1, line_2;

using namespace std;

struct Trains
{
	char number[128];
	char station_departure[128];
	char station_arrival[128];
	int time_H, time_M;
};


	//��������� ����� ������ � �������
	void Schedule::trains_input()
	{
		Trains  train;
		cout << "������� ����� ������ ";
		cin >> train.number;
		cout << endl;
		cout << "������� ������� ����������� ";
		cin >> train.station_departure;
		cout << endl;
		cout << "������� ������� �������� ";
		cin >> train.station_arrival;
		cout << endl;
		cout << "������� ����� ����������� (����) ";
		cin >> train.time_H;
		cout << endl;
		cout << "������� ����� ����������� (������) ";
		cin >> train.time_M;
		cout << endl;
		F.open("trains.txt", ios::app);
		FS.open("stations.txt", ios::app);
		F << "Train Number " << train.number << endl;
		F << "Station Departure  " << train.station_departure << endl;
		F << "Station Arrival " << train.station_arrival << endl;
		F << "Time of Departure: " << train.time_H << ':' << train.time_M << endl;
		F << endl;
		FS << "Station Arrival " << train.station_arrival << endl;
		FS << "Train Number " << train.number << endl;
		FS << "Station Departure " << train.station_departure << endl;
		FS << "Time of departure: " << train.time_H << ':' << train.time_M << endl;
		FS << endl;

		F.close();
		FS.close();
	}
	//��������� ������ ������ �� ������ ������
	void Schedule::trains_output()
	{
		std::string number_searching, string;

		cout << "������� ����� ������: ";
		cin >> number_searching;
		cout << endl;
		cout << "���������� � ������: " << endl;
		cout << endl;
		F.open("trains.txt", ios_base::in);

		std::string helping_val = "Train Number " + number_searching; // Train Number 18
		int k = 0;
		getline(F, line_1);
		if (!F.eof())
		{
			while (line_1 != helping_val and !F.eof())
			{
				getline(F, line_1);
			}
			if (line_1 == helping_val)
			{
				while (k < 4)  // ����� 4 ���� � ������
				{
					cout << line_1 << endl;
					getline(F, line_1);
					k++;
				}
				cout << endl;
				F.close();
			}
			if (F.eof())
			{
				F.close();
				cout << "������� ������ ��� � ���� ������" << endl;
				cout << endl;
			}
		}
		else
		{
			F.close();
			cout << "������� ������ ��� � ���� ������" << endl;
			cout << endl;
		}

	}
	//��������� ������ ������ �� �������� �������
	void Schedule::stations_output()
	{
		std::string station_searching, string;

		cout << "������� �������� ������: ";
		cin >> station_searching;
		cout << endl;
		cout << "���������� � �������: " << endl;
		cout << endl;

		F.open("stations.txt", ios_base::in);
		std::string helping_val_1 = "Station Arrival " + station_searching;
		int d = 0;
		int e = 0;

		getline(F, line_2);
		while (!F.eof())
		{
			if (line_2 == helping_val_1)
			{
				while (d < 4)
				{
					cout << line_2 << endl;
					getline(F, line_2);
					d++;
				}
				cout << endl;
				e++;
			}
			d = 0;
			getline(F, line_2);
		}
		if (F.eof())
		{
			F.close();
			if (e == 0)
			{
				cout << "� ������ ����� ��� �������" << endl;
				cout << endl;
			}
		}
		F.close();
	}
	//��������� ������ ���� ������ �� ���� ������ 
	void Schedule::read_all()
	{
		cout << "��� ������:" << endl;
		cout << endl;
		F.open("trains.txt", ios::in);
		if (F.is_open())
			while (getline(F, line))
			{
				cout << line << endl;
			}
		F.close();
	}
	//��������� �������� ������ �� ���� ������
	void Schedule::clear()
	{
		cout << "�� ������ ������� ��� ������?" << endl;
		cout << "Y-��, N-���" << endl;
		cout << endl;
		cin >> m;
		cout << endl;
		if (m == 'Y' or m == 'y')
		{
			fstream F("trains.txt", ios::out);
			F.close();
			fstream FS("stations.txt", ios::out);
			FS.close();
		}
	}


