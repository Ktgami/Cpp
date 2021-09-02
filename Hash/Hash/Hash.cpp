#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iterator>
#include <list>
#include<algorithm>
#include<vector>
using namespace std;

list < string>  *map; 
list < string>  *tmap;
int size,tc;
vector<int> Vcount;
int a, b, c, index, key_1, line_length;
int N, Nc, Nd = 0;
int da, e, f = 0;
int HashTableSize = 100;
int counter = 0;;
int fbool, Tsize;
string answer, otmDel, answer_delete, name_0, name_1, name_2, number, adress, fullname, key_0, reading_data, line, help_line;
string nothing = "Ничего не найдено";
std::fstream F;

struct Data_base
{
	int index_data_base;
	string data;
	int size;
};
Data_base *object_1;

//функция вычисления Хэш адреса
int Hash(int Key, int size)
{
	return Key % size;
}
//Интерфейс программы
void menu()
{
	
	cout << "1.Просмотр данных" << endl;
	cout << "2.Добавление данных" << endl;
	cout << "3.Поиск данных" << endl;
	cout << "4.Удаление данных" << endl;
	cout << "5.Загрузить данные из файла" << endl;
	cout << "6.Сохранить данные в файл" << endl;
	cout << "7.Подсчет коллизий для 40,75,90 элементов" << endl;
	cout << "8.Выход" << endl;
	cout << endl;
	cin >> a;
	cout << endl;
}
//метод ввода данных
void input()
{
	   	 
	cout << "Введите новые данные:" << endl;
	cout << "Фамилия:  ";
	cin >> name_0;
	cout << "Имя:  ";
	cin >> name_1;
	cout << "Отчество:  ";
	cin >> name_2;
	cout << "Введите номер паспорта:  ";
	cin >> number;
	cout << "Введите адрес проживания: ";
	cin >> adress;
	cout << endl;
	key_0 = name_0 + ' ' + name_1 + ' ' + name_2;
	key_1 = key_0.length();
	fullname = "ФИО: " + name_0 + " " + name_1 + " " + name_2 + " Серия и номер паспорта: " + number + " Адрес проживания: " + adress;
	index = Hash(key_1, object_1->size);
	object_1[index].data = fullname;
	map[index].push_front(fullname);
	cout << "Новые данные добавлены " << endl;
	cout << endl;
}
//ПОИСК ПО   ФИО
void output()
{
	cout << "Введите ФИО:  " << endl;
	cout << "Фамилия:  ";
	cin >> name_0;
	cout << "Имя:  ";
	cin >> name_1;
	cout << "Отчество:  ";
	cin >> name_2;
	key_0 = name_0 + ' ' + name_1 + ' ' + name_2;
	key_1 = key_0.length();
	index = Hash(key_1, object_1->size);
	

	int nf = 1;
	for (list <string>::iterator it = map[index].begin(); it != map[index].end(); ++it)
		{
			string temp=*it;
			if (strstr(temp.c_str(),key_0.c_str())) {
				cout << *it << endl;
				
				nf = 0;
			}
			
		}
	if (nf !=0)
	{
		cout << "not found" << endl;
		cout << endl;
	}


}


//полный вывод
void read_all()
{
	/*if (fbool == 1)
	{
		N = 0;
		while (N < object_1->size)
		{
			cout << object_1[N].data << endl;
			N++;
		}
		cout << endl;
		
	}
	else
	{
*/

		for (int i = 0; i < object_1->size; i++)
		{
			cout << i << " :";

			for (list <string>::iterator it = map[i].begin(); it != map[i].end(); ++it)
			{
				cout << *it << " |---> ";


			}

			cout << endl;
		}

	//}
}
//метод удаления
void deleting()
{


	cout << "Введите ФИО на удаление:  " << endl;
	cout << "Фамилия:  ";
	cin >> name_0;
	cout << "Имя:  ";
	cin >> name_1;
	cout << "Отчество:  ";
	cin >> name_2;
	key_0 = name_0 + ' ' + name_1 + ' ' + name_2;
	key_1 = key_0.length();
	index = Hash(key_1, object_1->size);
	list <string>::iterator Deltemp;
	int nf = 1;
	for (list <string>::iterator it = map[index].begin(); it != map[index].end(); ++it)
	{
		string temp = *it;
		if (strstr(temp.c_str(), key_0.c_str())) {
			cout << "Данные удалены" << endl;
			Deltemp = it;
			nf = 0;
		}

	}
	
	if (nf != 0)
	{
		cout << "not found" << endl;
		cout << endl;
	}
	else {
		
		
		tmap = new list <string>[object_1->size];
		tmap[index] = map[index];
		map[index].erase(Deltemp);
	}

	cout << "отменить последнее удаление? Да/Нет" << endl;
	cin >> otmDel;
	if (otmDel == "Да")
	{
		map[index] = tmap[index];
		delete[] tmap;
	}

}
//метод загрузки из файла
void FromFile()
{
	int rf;
	rf = 0;
	string file_contents;
	ifstream F("Hash.txt");
	while (getline(F,line))
	{
		file_contents += line;
		map[rf].push_front(line);
		rf++;
	}


	F.close();
}
//метод сохранения в файл
void ToFile()
{

	F.open("Hash.txt", ios::out);
		
	for (int i = 0; i < object_1->size; i++)
		{
			F << i << " :";

			for (list <string>::iterator it = map[i].begin(); it != map[i].end(); ++it)
			{
				F << *it << " |---> ";
			}
			F << endl;
		}
				
	
	F.close();
	cout << "Данные сохранены в файл" << endl;
	cout << endl;
}
// Подсчет коллизий
int randomt(int t)
{
	Tsize = 0;
	while (e <= t)
	{

		name_0 = rand();
		name_1 = rand();
		name_2 = rand();
		number =rand();
		adress = rand();
		key_1 = rand();
		fullname = "ФИО: " + name_0 + " " + name_1 + " " + name_2 + " Серия и номер паспорта: " + number + " Адрес проживания: " + adress;
		index = Hash(key_1, object_1->size);
		map[index].push_front(fullname);
		Vcount.push_back(index);
		e++;
		object_1[index].data = fullname;
	}
	e = 0;

	for (int i = 0; i < Vcount.size(); i++)
	{
		for (int tc = i + 1; tc < Vcount.size(); tc++)
		{
			if (Vcount[i] == Vcount[tc])
			{
				Tsize = Tsize + 1;
			}
		}


	}

	
	cout << "Число коллизий при "<< t<<" элементах составило: " << Tsize << endl;
	map->clear();
	Vcount.clear();
	
	return 0;
}


//метод выбора интерфейса
void switcher()
{
	switch (a)
	{
	case 1:
		read_all();
		break;
	case 2:
		input();
		
		break;
	case 3:
		output();

				break;
	case 4:
		deleting();
		break;
	case 5:
		FromFile();
		break;
	case 6:
		ToFile();
		break;
	case 7:
		
		randomt(40);
		randomt(75);
		randomt(90);
		
	case 8:
		break;
	default:
		cout << "Ошибка" << endl;
		cout << endl;
		break;
	}
}
void initialization(int size_table_1)
{
	
	da = 0;
	while (da < size_table_1)
	{
		object_1[da].index_data_base = da;
		object_1[da].data = nothing;
		da++;
	}
}
//

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");
	srand(0);
	
	object_1 = new Data_base[HashTableSize];
	object_1->size = 100;
	map = new list <string>[object_1->size];
	initialization(HashTableSize);
label_0:
	menu();
	if (a != 8)
	{
		switcher();
	}
	else
	{
		F.close();
		return 0;
	}
	goto label_0;
}