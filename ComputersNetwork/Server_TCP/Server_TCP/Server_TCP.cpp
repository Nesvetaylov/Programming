// SERVER TCP 

#include <iostream>  
#include <winsock2.h> 
#include <windows.h> 
#include <string> 
#pragma comment (lib, "Ws2_32.lib")  
using namespace std;
#define SRV_PORT 1234 // порт должен совпадать  
#define BUF_SIZE 64  
const string QUEST = "Who are you?\n";  //сообщение сервера при подключении клиента
const string QUEST2 = "Where are you studying?\n";
int main() {
	char buff[1024];
	if (WSAStartup(0x0202, (WSADATA*)&buff[0]))
	{
		cout << "Error WSAStartup \n" << WSAGetLastError();   // Ошибка!
		return -1;
	}
	SOCKET s /*сокет сервера*/, s_new /*сокет клиента*/;
	int from_len;
	char buf[BUF_SIZE] = { 0 };//структура сокета и клиента с которым он связался
	sockaddr_in sin, from_sin;
	s = socket(AF_INET, SOCK_STREAM, 0);//создает серв
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0;//адрес текущего компа
	sin.sin_port = htons(SRV_PORT);
	bind(s, (sockaddr*)&sin, sizeof(sin));
	string msg, msg1, msg2;
	listen(s, 3);//создание очереди для принятия клиентов(до 3х)
	while (1)//начало работы сервера    
	{
		cout << "Server is working!" << endl;
		from_len = sizeof(from_sin);
		s_new = accept(s, (sockaddr*)&from_sin, &from_len);//извлекает очередного клиента, инфа по памяти берется из from_sin
		cout << "new connected client! " << endl;
		msg = QUEST;//основной вопрос 
		msg2 = QUEST2;
		while (1) {
			send(s_new, (char*)&msg[0], msg.size(), 0);// отправить сообщ клиенту
			from_len = recv(s_new, (char*)buf, BUF_SIZE, 0);//получение сообщения от клиента
			buf[from_len] = 0;
			msg1 = (string)buf;
			cout << msg1 << endl;
			if (msg1 == "Bye") break;//условие прерывания цикла
			getline(cin, msg);
		}
		cout << "client is lost";
		closesocket(s_new);
	}
	return 0;
}
