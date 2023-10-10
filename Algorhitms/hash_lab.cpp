#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;






const int MAX_SIZE = 2000;//макс размер табл

struct HashTable
{
	int table[MAX_SIZE];//храним элем
	int size;//текущ размер хеш-табл
};
int h(int x, int N)
{
	return x % N;
}

void initHashTable(HashTable& hashTable) {
	hashTable.size = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		hashTable.table[i] = -1;//инициализация массива значением -1

	}
}

void insertObj(HashTable& hashTable, int object)
{
	int index = h(object, MAX_SIZE);
	int k = 0;

	while (hashTable.table[index] != -1)
	{
		index = (index + 1) % MAX_SIZE;//Линейное рехеширование
	}
	hashTable.table[index] = object;//вставка объекта в хеш-табл
	hashTable.size++;
}
int gen_obj()
{
	return rand();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	HashTable hashTable;
	initHashTable(hashTable);
	float a; //заданный уровень загруженности
	cout << "Введите уровень загруженности хеш-таблицы (от 0 до 1): ";
	cin >> a;
	int k = 0;//число уже занятых строк в таблице
	while (k < a * MAX_SIZE)
	{
		int object = gen_obj();
		insertObj(hashTable, object);
		k++;
	}

	cout << "Хеш-таблица заполнена на: " << a << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (hashTable.table[i] != -1)
		{
			cout << "Хеш-таблица [" << i << "]: " << hashTable.table[i] << endl;
		}
	}
	return 0;

}


