#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Person // структура данных запроса клиента
{
	char name[25];  //имя
	int grade[4];   //оценка
} A;

void main() {
	setlocale(LC_ALL, "rus");

	int seed = time(NULL);//Генерируем случайное значение "seed" с помощью функции "time(NULL)"
	srand(time(NULL));//используем time(NULL) для инициализации генератора случайных чисел с помощью функции "srand()".

	bool isWaiting = false;//ожидает ли клиент ответ от сервера 
	long fileSize = 0;//переменная для хранения размера файла
	int answer = 0;//переменная для хранения ответа от сервера

	string path = "F:/ComputersNetwork/Information/";//"path" - строка, содержащая путь к папке "Information".
	string registrationFile = path + "information.bin";//registrationFile" - строка, содержащая полный путь к файлу "information.bin".
	string clientName = to_string(rand() * (int)(sin(time(NULL)) + 2)); //"clientName" - строка, содержащая имя клиента, сгенерированное на основе случайного числа и текущего времени.

	ofstream outConnect;
	ofstream outFile;
	ifstream inFile;

	outFile.open(path + clientName + ".bin", ios::app | ios::binary);//открыли файл для записи в бинарном режиме
	outFile.close();

	outConnect.open(registrationFile, ios::app | ios::binary); //Открываем файл "registrationFile" для записи в двоичном режиме
	outConnect.write((char*)&clientName, sizeof(clientName)); //затем записываем в него значение "clientName" (отписался серверу для подключения)
	outConnect.close();
	cout << "client name: " << (clientName) << endl;

	cout << "Файл создан" << endl;
	cout << "Начало работы" << endl;
	while (true)//начало работы
	{
		if (isWaiting == false) // если не в режиме ожидания, то отправляем запрос
		{
			cout << "Введите ФИО и 4 оценки студента:" << endl;
			cin >> A.name >> A.grade[0] >> A.grade[1] >> A.grade[2] >> A.grade[3]; // Ввод

			outFile.open(path + clientName + ".bin", ios::app | ios::binary);//открываем "clientName.bin" для записи в двоичном режиме
			outFile.write((char*)&A, sizeof(A));//записываем в него структуру "A"
			outFile.seekp(0, ios::end);//перемещаем указатель записи в конец файла
			fileSize = outFile.tellp();//получаем текущий размер файла
			outFile.close();
			isWaiting = true;
		}
		else // иначе ожидаем ответ
		{
			inFile.open(path + clientName + ".bin", ios::binary);//открываем файл "clientName.bin" для чтения в двоичном режиме,
			inFile.seekg(fileSize, ios::beg);//перемещаем указатель чтения на позицию "fileSize"
			inFile.read((char*)&answer, sizeof(answer));//читаем значение "answer" из файла
			fileSize = inFile.tellg();//получаем новый размер файла
			inFile.close();
			switch (answer)
			{
			case 1:
				cout << "У " << A.name << " имеется задолжность!" << endl;
				break;
			case 2:
				cout << "У " << A.name << " нет стипендии!" << endl;
				break;
			case 3:
				cout << "У " << A.name << " обычная стипендия!" << endl;
				break;
			case 4:
				cout << "У " << A.name << " повышенная стипендия!" << endl;
				break;
			default:
				cout << "Ошибка! Недопустимый ответ сервера: " << answer << endl;
				break;
			}
			cout << endl;
			isWaiting = false;
		}
		Sleep(100);
	}
}
