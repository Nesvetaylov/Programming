#include <iostream>  
#include <winsock2.h> //для работы с сокетами в Windows.
#include <windows.h> //для работы с функциями Windows.
#include <string> 
#pragma comment (lib, "Ws2_32.lib") //казывает компилятору подключить библиотеку Ws2_32.lib,
//которая содержит функции для работы с сокетами в Windows.
using namespace std;

#define SRV_PORT 1234 // порт должен совпадать  
#define BUF_SIZE 64  //память для попадания сообщения 
const string QUEST = "Who are you?\n";  //сообщение сервера при подключении клиента
int main()
{
	char buff[1024]; //объявляет массив символов buff размером 1024.
	if (WSAStartup(0x0202, (WSADATA*)&buff[0])) //вызывает функцию WSAStartup, которая инициализирует использование библиотеки Winsock.
		//0x0202 - версия Winsock, которую мы хотим использовать.
		//(WSADATA*)&buff[0] - указатель на структуру WSADATA, которая будет заполнена информацией о версии Winsock.
	{
		cout << "Error WSAStartup \n" << WSAGetLastError();   // Ошибка!
		return -1; //чтобы указать на ошибку
	}
	SOCKET s_serv/*сокет сервера*/, s_client/*сокет клиента*/;
	int from_len; //храненит размер структуры клиента
	char buf[BUF_SIZE] = { 0 }; //структура сокета и клиента с которым он связался, инициализированная нулями
	sockaddr_in sin, from_sin; //хранит инфу о клиенте и сервере
	s_serv = socket(AF_INET, SOCK_STREAM, 0);//создает серв
	sin.sin_family = AF_INET; //устанавливает семейство адресов для сокета
	sin.sin_addr.s_addr = 0; //устанавливает IP-адрес текущего компьютера
	sin.sin_port = htons(SRV_PORT); //устанавливает порт для сокета сервера
	bind(s_serv, (sockaddr*)&sin, sizeof(sin)); //связывает сокет с адресом и портом
	string msg, msg1; //хранят сообщения
	listen(s_serv, 3); //создание очереди для принятия клиентов(до 3х)
	while (1) //начало работы сервера    
	{
		from_len = sizeof(from_sin); //Получение размера структуры с информацией о клиенте
		s_client = accept(s_serv, (sockaddr*)&from_sin, &from_len);//извлекает очередного клиента, инфа по памяти берется из from_sin
	cout << "new connected client! " << endl;
	msg = QUEST;//основной вопрос 
	while (1) 
	{
		send(s_client, (char*)&msg[0], msg.size(), 0); //Отправка сообщения клиенту
		from_len = recv(s_client, (char*)buf, BUF_SIZE, 0); //Получение сообщения от клиента
		buf[from_len] = 0; //Эта строка добавляет нулевой символ в конец буфера, чтобы преобразовать его в строку
		msg1 = (string)buf; //Эта строка преобразует содержимое буфера buf в строку и сохраняет его в переменную msg1
		cout << msg1 << endl;
		if (msg1 == "Bye") break;//условие прерывания цикла
		getline(cin, msg);
	}
	cout << "client is lost";
	closesocket(s_client);
	}
	return 0;
}