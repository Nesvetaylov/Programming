#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;






const int MAX_SIZE = 2000;//���� ������ ����

struct HashTable
{
	int table[MAX_SIZE];//������ ����
	int size;//����� ������ ���-����
};
int h(int x, int N)
{
	return x % N;
}

void initHashTable(HashTable& hashTable) {
	hashTable.size = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		hashTable.table[i] = -1;//������������� ������� ��������� -1

	}
}

void insertObj(HashTable& hashTable, int object)
{
	int index = h(object, MAX_SIZE);
	int k = 0;

	while (hashTable.table[index] != -1)
	{
		index = (index + 1) % MAX_SIZE;//�������� �������������
	}
	hashTable.table[index] = object;//������� ������� � ���-����
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
	float a; //�������� ������� �������������
	cout << "������� ������� ������������� ���-������� (�� 0 �� 1): ";
	cin >> a;
	int k = 0;//����� ��� ������� ����� � �������
	while (k < a * MAX_SIZE)
	{
		int object = gen_obj();
		insertObj(hashTable, object);
		k++;
	}

	cout << "���-������� ��������� ��: " << a << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (hashTable.table[i] != -1)
		{
			cout << "���-������� [" << i << "]: " << hashTable.table[i] << endl;
		}
	}
	return 0;

}


