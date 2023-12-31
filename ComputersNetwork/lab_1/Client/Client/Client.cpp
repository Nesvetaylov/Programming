﻿#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
// структура данных запроса клиента
struct Person
{
	char name[25];  //имя
	int height;		//рост
	int weight;		//вес
} A;
void main() {
	setlocale(LC_ALL, "rus");

	const char* nameR = "C:/Users/Администратор/Desktop/KUBSU files/lab_1/Client/Client/REQUEST.bin"; //путь к файлу запросов клиентов
	const char* nameA = "C:/Users/Администратор/Desktop/KUBSU files/lab_1/Client/Client/ANSWER.bin"; //путь к файлу ответов сервера
	ofstream f_REQ;//создать файл запросов
	ifstream f_ANS;//открыть файл ответов
	long pred_size;//храненим размер предыдущего ответа сервера
	int answer;//храненит ответ сервера на запрос клиента
	while (true)//начало работы клиента
	{
		// передача данных от клиента серверу
		cout << "Введите запрос: Фамилия Рост Вес" << endl;
		cin >> A.name >> A.height >> A.weight;
		f_REQ.open(nameR, ios::app | ios::binary); //открытие файла REQUEST в режиме добавления записей в конец
		f_REQ.write((char*)&A, sizeof(A)); //запись запроса в файл REQUEST
		f_REQ.close();

		// поступил ответ от сервера?
		f_ANS.open(nameA, ios::binary); //открытие файла ANSWER
		f_ANS.seekg(0, ios::end); //Перемещение указателя файла в конец
		pred_size = f_ANS.tellg();//сохранили новый размер файла
		while (pred_size >= f_ANS.tellg())//Цикл ожидания нового ответа от сервера
		{
			Sleep(100); // ждем и переходим в конец файла ANSWER
			f_ANS.seekg(0, ios::end);
		}
		// получение ответа от сервера	
		f_ANS.seekg(pred_size, ios::beg); // на начало нового ответа
		f_ANS.read((char*)&answer, sizeof(answer)); // Считывание ответа сервера из файла ответов в переменную answer
		f_ANS.close();
		// расшифровка ответа
		switch (answer) {
		case 0: {cout << "Недостаток веса\n"; break; }
		case 1: {cout << "Норма веса\n"; break; }
		case 2: {cout << "Избыток веса\n"; break; }
		}
	} 
}