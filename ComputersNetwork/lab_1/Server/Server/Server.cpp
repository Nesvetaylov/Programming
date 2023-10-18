#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Person
{
	char name[25];	 //имя 
	int height;		 //рост
	int weight;		 //вес
}B;
int answer;//хранит ответ сервера на запрос клиента
long size_pred;//хранит текущую позицию сервера в файле запросов
int main() {
	ifstream fR;//открыть существующий файл запросов
	ofstream fA;//создать файл ответов
	setlocale(LC_ALL, "rus");
	const char* nameR = "C:/Users/Администратор/Desktop/Client/Client/REQUEST.bin"; //путь к файлу запросов клиентов
	const char* nameA = "C:/Users/Администратор/Desktop/Client/Client/ANSWER.bin"; //путь к файлу ответов сервера
	cout << "server is working" << endl;
	// начальные установки
	fR.open(nameR, ios::binary); //открытие бинарного файла REQUEST 
	fR.seekg(0, ios::end);//перемещение файлового указателя в конец
	size_pred = fR.tellg(); //текущая позиция сервера в файле REQUEST
	fR.close();

	// начало работы сервера
	while (true)
	{
		fR.open(nameR, ios::binary); //открытие бинарного файла REQUEST
		fR.seekg(0, ios::end);//перемещение файлового указателя в конец
		// есть новые запросы от клиентов? 
		while (size_pred >= fR.tellg())//текущая позиция сервера в файле REQUEST
		{
			Sleep(100); fR.seekg(0, ios::end);//задержка на 100милисек
			//и перемещение файлового указателя в конец
		}
		// если получен новый запрос 
		fR.seekg(size_pred, ios::beg); //перемещение файлового указателя к началу полученного запроса
		fR.read((char*)&B, sizeof(B)); //считывание данных клиента
		size_pred = fR.tellg(); //Обновление переменной sizepred до текущей позиции указателя файла.
		fR.close();
		// определение индекса массы	
		double IMT = B.weight / (0.01 * B.height) / (0.01 * B.height);
		if (18.5 <= IMT && IMT < 25) answer = 1;//нормальная масса
		if (18.5 > IMT) answer = 0;//недостаточная масса тела
		if (IMT >= 25)answer = 2;//избыточная масса тела

		// передача ответа клиенту
		fA.open(nameA, ios::binary | ios::app); //открытие файла ANSWER  с опцией добавления записей в конец файла
		fA.write((char*)&answer, sizeof(answer)); //Запись значения переменной answer в файл ответов
		fA.close();
	}// while
}
