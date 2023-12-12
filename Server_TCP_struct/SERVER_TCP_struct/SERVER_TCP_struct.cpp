// SERVER TCP 
#include <iostream>  
#include <winsock2.h> 
#include <windows.h> 
#include <string> 
#pragma comment (lib, "Ws2_32.lib")  
using namespace std;
#define SRV_PORT 1234  
#define BUF_SIZE 64  
struct Person
{
	string name;  //имя
	int grades[4];  //оценки
}B;
const string QUEST = "Enter the data\n"; //первый вопрос для клиента, чтобы начать диалог
int answer;
int main() {
	setlocale(LC_ALL, "rus");
	char buff[1024];
	if (WSAStartup(0x0202, (WSADATA*)&buff[0]))
	{
		cout << "Error WSAStartup \n" << WSAGetLastError();   // Ошибка!
		return -1;
	}
	SOCKET s_serv/*сокет сервера*/, s_client/*сокет клиента*/;
	int from_len;//храненит размер структуры клиента
	char buf[BUF_SIZE] = { 0 };//структура сокета и клиента с которым он связался, инициализированная нулями
	sockaddr_in sin, from_sin;//хранит инфу о клиенте и сервере
	s_serv = socket(AF_INET, SOCK_STREAM, 0);//создает серв
	sin.sin_family = AF_INET;//устанавливает семейство адресов для сокета
	sin.sin_addr.s_addr = 0;//устанавливает IP-адрес текущего компьютера
	sin.sin_port = htons(SRV_PORT);//устанавливает порт для сокета сервера
	bind(s_serv, (sockaddr*)&sin, sizeof(sin));//связывает сокет с адресом и портом
	string msg, msg1;//хранят сообщения
	listen(s_serv, 3);//создание очереди для принятия клиентов(до 3х)
	while (1) {//начало работы сервера    
		from_len = sizeof(from_sin);//Получение размера структуры с информацией о клиенте
		s_client = accept(s_serv, (sockaddr*)&from_sin, &from_len);//извлекает очередного клиента, инфа по памяти берется из from_sin
		cout << "Новый клиент! " << endl;
		msg = QUEST;//основной вопрос 
		while (1) {
			send(s_client, (char*)&msg[0], msg.size(), 0);//Отправка сообщения клиенту
			recv(s_client, (char*)&B, sizeof(B), 0);//Получение сообщения от клиента

			if (B.grades[0] == 2 || B.grades[1] == 2 || B.grades[2] == 2 || B.grades[3] == 2) answer = 2; //задолжность	
			else if (B.grades[0] == 3 || B.grades[1] == 3 || B.grades[2] == 3 || B.grades[3] == 3) answer = 3; //нет степендии
			else if (B.grades[0] == 4 || B.grades[1] == 4 || B.grades[2] == 4 || B.grades[3] == 4) answer = 4; //обычная стеендия
			else answer = 5;

			send(s_client, (char*)&answer, sizeof(answer), 0);
		}
		cout << "клиент потерян :(";
		closesocket(s_client);
	}
	return 0;
}