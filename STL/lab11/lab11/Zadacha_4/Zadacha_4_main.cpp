#include <iostream>
#include <C:\Users\Kostya\Desktop\lab\lab11\lab11\Zadacha_2\Time.h>
#include <queue>
#include <vector>
using namespace std;

typedef queue<Time> Que;
typedef vector<Time> Vec;

Que make_queue(int n)
{
	Que q;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//ввод переменной
		q.push(t); //добавление в очередь
	}
	return q;//вернуть очередь как результат функции
}

//копирует очередь в вектор
Vec copy_queue_to_vector(Que q)
{
	Vec v;
	while (!q.empty())//пока очередь не пустая
	{
		//добавить в вектор элемент из вершиы очереди
		v.push_back(q.front());
		q.pop();
	}
	return v; //вернуть вектор как результат функции
}

//копирует вектор в очередь
Que copy_vector_to_queue(Vec v)
{
	Que q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);//добавить в очередь элемент вектора
	}
	return q; //вернуть очередь как результат функции
}

void print_queue(Que q)
{
	Vec v;
	v = copy_queue_to_vector(q);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	q = copy_vector_to_queue(v);
}

//определение максимального элемента
Time find_max(Que q)
{
	Vec v = copy_queue_to_vector(q);
	Time max(0, 0);
	for (int i = 0; i < v.size(); i++)
		if (v[i] > max)
			max = v[i];
	q = copy_vector_to_queue(v);
	return max;
}

//определение среднего арифметического
Time find_srednee(Que q)
{
	Time m(0, 0);
	Vec v = copy_queue_to_vector(q);
	for (int i = 0; i < v.size(); i++)
		m = m + v[i];
	q = copy_vector_to_queue(v);
	return m / q.size();
}

void del(Que &q, Time el)
{
	Vec v = copy_queue_to_vector(q);
	Que newQ;
	for (int i = 0; i < v.size(); i++)
		if (!(v[i] == el))
			newQ.push(v[i]);
	q = newQ;
}

void add(Que &q, Time m)
{
	Vec v = copy_queue_to_vector(q);
	Que newQ;
	for (int i = 0; i < v.size(); i++)
		newQ.push(v[i] + m);
	q = newQ;
}

void main()
{
	Que Que;
	int n;
	cout << "N: ";
	cin >> n;
	Que = make_queue(n);
	cout << endl;
	print_queue(Que);
	cout << endl;

	Time max_el = find_max(Que);
	cout << "Max: " << max_el << endl;
	Que.push(max_el);
	cout << "Result: ";
	print_queue(Que);
	cout << endl;

	cout << "Key to delete: ";
	Time key;
	cin >> key;
	del(Que, key);
	cout << "Result: ";
	print_queue(Que);
	cout << endl;

	Time sred_el = find_srednee(Que);
	cout << "Srednee: " << sred_el << endl;
	add(Que, sred_el);
	cout << "Result: ";
	print_queue(Que);
	cout << endl;
	system("pause");
}