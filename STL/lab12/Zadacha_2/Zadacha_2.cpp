#include <iostream>
#include <map>
#include <time.h>
#include "Time.h"
using namespace std;

typedef map<int, Time> TMap;//определяем тип для работы со словарем
typedef TMap::iterator it;//итератор

//функция для формирования словаря
TMap make_map(int n)
{
	srand(time(NULL));
	TMap m;//пустой словарь
	Time t;
	for (int i = 0; i < n; i++)
	{
		//генерируем рандомные числа
		int a = 0 + rand() % 59;
		int b = 0 + rand() % 59;
		Time t(a, b);
		//создаем пару и добавляем ее в словарь
		m.insert(make_pair(i, t));
	}
	return m;//возвращаем словарь как результат работы функции
}
//функция для печати словаря
void print_map(TMap m)
{
	//печатаем содержимое словаря с помощью итератора
	for (it it2 = m.begin(); it2 != m.end(); it2++)
	{
		cout << "<" << it2->first << ": " << it2->second << ">  ";
	}
	cout << endl;
}

//поиск макисмального элемента
Time find_max(TMap m)
{
	it it2 = m.begin();
	Time t = it2->second;
	for (it2 = m.begin(); it2 != m.end(); it2++)
	{
		if (it2->second > t)
			t = it2->second;
	}
	return t;
}

//вычисление среднего значения
Time find_mean(TMap m)
{
	Time sum(0, 0);
	for (it it2 = m.begin(); it2 != m.end(); it2++)
	{
		sum = sum + it2->second;
	}
	return(sum / m.size());
}

//вставка на заданную позицию
void add_map(TMap &m, Time item, int pos)
{
	m.insert(make_pair(pos, item));
}

//удаление элементов
void delete_from_map(TMap &m, Time item)
{
	it current, j; //создаём два итератора
	j = m.begin(); //начало словаря
	int k = m.size(); //размер словаря
	for (int i = 0; i < k; i++) //в цикле работаем с итераторами
	{
		current = j; //сохраняем в current указатель на текущий элемент
		j++; //переставляем j на следующий элемент
		if ((current->second) == item) //если нашли тот, который надо удалить, то удаляем.
			m.erase(current);			//этим достигли того, что не теряем указатель. 
		//Иначе удалили бы элемент и потеряли итератор
	}
}

//прибавление ко всем элементам
void add(TMap &m, Time item)
{
	for (it it2 = m.begin(); it2 != m.end(); it2++)
		it2->second = it2->second + item;
}

void main()
{
	int n;
	cout << "N: ";
	cin >> n;//количество элементов
	TMap m = make_map(n);//создать словарь
	print_map(m);//напечатать словарь
	cout << endl;

	//добавление максимального элемента в конец контейнера
	Time maxItem = find_max(m);
	cout << "Max: " << maxItem << endl;
	//вставляем на позицию, равную размеру словаря, чтобы при автоматической сортировке словаря элемент оказался в конце
	add_map(m, maxItem, m.size());
	cout << "Result: ";
	print_map(m);
	cout << endl;

	//удаление элементов с заданным значением
	Time key;
	cout << "Time for delete:" << endl;
	cin >> key;
	delete_from_map(m, key);
	cout << "Result: ";
	print_map(m);
	cout << endl;

	//добавление к каждому элементу среднего арифметического
	Time srednee = find_mean(m);
	cout << "Srednee: " << srednee << endl;
	add(m, srednee);
	cout << "Result: ";
	print_map(m);
	cout << endl;
	system("pause");
}