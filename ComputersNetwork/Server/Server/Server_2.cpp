#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;
struct Person
{
	char name[25];// поле имени
	int grade[4];// поле оценок
}B;

struct Client
{
	string name;//поле для имени
	int size;//размер файла подключений
};
int answer;// храненит ответ сервера
long size_pred;//храненит текущую позицию сервера в файле запросов

void Print()//выводит информацию о запросе 
{
	cout << endl << "Запрос получен: " << B.name << " ";
	for (int i = 0; i < 5; i++)
		cout << B.grade[i] << " ";
	cout << endl;
}
int Stipendia()//определяет стипендию в зависимости от оценок
{
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 2)//оценка=2
		{
			cout << "1" << endl;
			return 1;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 3)//оценка 3
		{
			cout << "2" << endl;
			return 2;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 4)//оценка 4
		{
			cout << "3" << endl;
			return 3;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 5)//оценка 5
		{
			cout << "4" << endl;
			return 4;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	long size_of_Connections;// храненит размер файла подключений

	ofstream out_of_Information;//выходной поток
	ifstream in_Information;//входной поток
	ifstream newClientFile;

	string path = "F:/ComputersNetwork/Information/";
	string infFile = path + "information.bin";
	string newClientName;

	out_of_Information.open(infFile, ios::binary | ios::app); // создадим выходной поток для открытия файла information.bin в режиме бинарного чтения
	out_of_Information.close();

	in_Information.open(infFile, ios::binary); //создадим входной поток для открытия файла information.bin в режиме бинарного чтения
	in_Information.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
	size_of_Connections = in_Information.tellg();//считывает размер текущей позиции файла
	in_Information.close();

	vector<Client> client;

	cout << "Сервер работает" << endl;
	cout << "Размер файла подключений: " << size_of_Connections << endl;

	while (true) // начало работы сервера
	{   // проверка наличия новых клиентов
		in_Information.open(infFile, ios::binary); //открытие файла information.bin
		in_Information.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
		if (size_of_Connections < in_Information.tellg()) // Сравнение размера файла подключений с текущей позицией файла tellg().
			//Если размер меньше, значит найден новый клиент.
		{
			in_Information.seekg(size_of_Connections, ios::beg);//устанавливаем файловый указатель в начало файла
			in_Information.read((char*)&newClientName, sizeof(newClientName));//Чтение имени нового клиента из файла

			Client newClientData;//создание структуры и заполнение полей
			newClientFile.open(path + newClientName + ".bin");// Открытие файла нового клиента в режиме бинарного чтения.
			newClientFile.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
			newClientData.name = newClientName;// значение переменной newClientName будет сохранено в поле name структуры newClientData.
			newClientData.size = newClientFile.tellg();//Чтение значения текущей позиции файла
			//и присвоение его полю size структуры newClientData.
			client.push_back(newClientData);//Добавление структуры newClientData в вектор client.
			newClientFile.close();

			in_Information.seekg(0, ios::end);//устанавливаем файловый указатель в конец файла
			size_of_Connections = in_Information.tellg();// Чтение значения текущей позиции файла и присвоение его переменной size_of_Connections.

			cout << endl << "Новый клиент: " << newClientName << endl;
			cout << "Размер файла подключений: " << size_of_Connections << endl;
		}
		in_Information.close();

		// Обход текущих клиентов
		bool haveNewInput = false;
		int answer = 9;
		ofstream outFile;
		ifstream inFile;//Создание входного потока inFile для открытия файла клиента в режиме бинарного чтения.
		for (int i = 0; i < client.size(); i++)
		{
			inFile.open(path + client[i].name + ".bin", ios::binary);//открытие соответствующего файла клиента для последующего чтения данных.
			//Очистка ошибок состояния и позиционирование в конец файла с помощью функций clear() и seekg().
			inFile.clear();
			inFile.seekg(0, ios::end);
			if (client[i].size < inFile.tellg())//Сравнение размера клиента в векторе client с текущей позицией файла tellg().
				//Если размер меньше, значит есть новый ввод.
			{
				inFile.seekg(client[i].size, ios::beg);//устанавливаем файловый указатель в начало файла
				inFile.read((char*)&B, sizeof(B));//Чтение структуры Person из файла с помощью функции read().
				haveNewInput = true;//Установка флага haveNewInput в true.
				Print();//вывод информации
			}
			inFile.close();

			if (haveNewInput)//если true
			{
				cout << "Ответ отправлен: ";
				outFile.open(path + client[i].name + ".bin", ios::app | ios::binary);//Создание выходного потока outFile для открытия файла клиента в режиме добавления записей.
				answer = Stipendia();//Вызов функции Stipendia() для определения стипендии.
				outFile.write((char*)&answer, sizeof(answer));//Запись ответа в файл с помощью функции write().
				outFile.seekp(0, ios::end);//Установка позиции в конец файла
				client[i].size = outFile.tellp();// Обновление значения размера клиента в векторе client.
				outFile.close();
			}
			haveNewInput = false;
		}
		Sleep(100);//Ожидание в течение 100 миллисекунд
	}
}
