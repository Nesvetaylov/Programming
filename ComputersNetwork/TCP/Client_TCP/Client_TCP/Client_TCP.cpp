#include <iostream>  
#define _WINSOCK_DEPRECATED_NO_WARNINGS  
// подавление предупреждений библиотеки winsock2
#include <winsock2.h> 
#include <string>
#include <windows.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma warning(disable: 4996)  // подавление предупреждения 4996 
using namespace std;
#define SRV_HOST "localhost"  
#define SRV_PORT 1234 // пароль для сервера
#define CLNT_PORT 1235  // пароль для клиента
#define BUF_SIZE 64  //память для попадания сообщения
char TXT_ANSW[] = "I am your student\n";
int main() 
{
	char buff[1024]; //объявляет массив символов buff размером 1024.
	if (WSAStartup(0x0202/*версия*/, (WSADATA*)&buff[0]/*по этому адресу*/))
		//вызывает функцию WSAStartup, которая инициализирует использование библиотеки Winsock.
		//0x0202 - версия Winsock, которую мы хотим использовать.
		//(WSADATA*)&buff[0] - указатель на структуру WSADATA, которая будет заполнена информацией о версии Winsock.
	{
		cout << "Error WSAStartup \n" << WSAGetLastError();  // Ошибка!
		return -1;
	}
	SOCKET s;
	int from_len; //храненит размер структуры клиента
	char buf[BUF_SIZE]={0};//память для передачи реплик
	hostent * hp;//структура для использования функий библ сокетов
	sockaddr_in clnt_sin/*информация для сокета клиента*/, srv_sin/*информация для сокета сервера*/;
	s = socket(AF_INET, SOCK_STREAM, 0);
	clnt_sin.sin_family = AF_INET; //Установка семейства адресов для клиента
	clnt_sin.sin_addr.s_addr = 0; //Установка адреса текущего компьютера для клиента
	clnt_sin.sin_port = htons(CLNT_PORT);// Установка порта для клиента
	bind(s, (sockaddr*)&clnt_sin, sizeof(clnt_sin)); //Привязка сокета клиента к адресу и порту
	hp = gethostbyname(SRV_HOST); //получили числовой формат адреса
	srv_sin.sin_port = htons(SRV_PORT); //Установка порта для сервера
	srv_sin.sin_family = AF_INET; //Установка семейства адресов для сервера
	((unsigned long*)&srv_sin.sin_addr)[0] = ((unsigned long**)hp->h_addr_list)[0][0]; //Установка адреса сервера
	connect(s, (sockaddr*)&srv_sin, sizeof(srv_sin)); //клиент связывается с сервером
	string mst;
	do {
		from_len = recv(s, (char*)&buf, BUF_SIZE, 0); //Получение сообщения от сервера с помощью функции recv
		buf[from_len] = 0; // Добавление нулевого символа в конец полученного сообщения.
		cout << buf << endl;
		//send (s, (char *)&TXT_ANSW, sizeof(TXT_ANSW),0); 
		getline(cin, mst);//считалии ответ клиента
		int msg_size = mst.size();//узнали размер ответа
		send(s, (char*)&mst[0], msg_size, 0); //посылаем серверу
	} while (mst != "Bye"); //условие завершения работы сервера
	cout << "exit to infinity" << endl;//ушли в бесконечность
	cin.get();//задержка    closesocket (s); //разрыв соединения
	return 0;
}

