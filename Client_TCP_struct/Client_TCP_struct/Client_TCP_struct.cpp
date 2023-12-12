#include <iostream>  
#define _WINSOCK_DEPRECATED_NO_WARNINGS  
#include <winsock2.h>
#include <string>
#include <windows.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

#define SRV_HOST "127.0.0.1"
#define SRV_PORT 1234 // пароль для сервера
#define CLNT_PORT 1235  // пароль для клиента
#define BUF_SIZE 64  //память для попадания сообщения
char TXT_ANSW[] = "I am your student\n";

struct Person
{
    char name[25];
    int grades[4];
} A;
int answer = -1;
int main() {
    setlocale(LC_ALL, "rus");
    char buff[1024];
    if (WSAStartup(0x0202, (WSADATA*)&buff[0])) {
        cout << "Error WSAStartup \n" << WSAGetLastError();
        return -1;
    }

    SOCKET s;
    int from_len;//храненит размер структуры клиента
    char buf[BUF_SIZE] = { 0 };//память для передачи реплик
    sockaddr_in clnt_sin/*информация для сокета клиента*/, srv_sin/*информация для сокета сервера*/;
    s = socket(AF_INET, SOCK_STREAM, 0);

    clnt_sin.sin_family = AF_INET;//Установка семейства адресов для клиента
    clnt_sin.sin_addr.s_addr = 0;//Установка адреса текущего компьютера для клиента
    clnt_sin.sin_port = htons(CLNT_PORT);// Установка порта для клиента
    bind(s, (sockaddr*)&clnt_sin, sizeof(clnt_sin));//Привязка сокета клиента к адресу и порту

    hostent* hp = gethostbyname(SRV_HOST);//структура для использования функий библ сокетов
    srv_sin.sin_port = htons(SRV_PORT);//Установка порта для сервера
    srv_sin.sin_family = AF_INET;//Установка семейства адресов для сервера
    ((unsigned long*)&srv_sin.sin_addr)[0] = ((unsigned long**)hp->h_addr_list)[0][0];//Установка адреса сервера

    connect(s, (sockaddr*)&srv_sin, sizeof(srv_sin));//клиент связывается с сервером

    string mst;
    do {
        from_len = recv(s, (char*)&buf, BUF_SIZE, 0);//Получение сообщения от сервера с помощью функции recv
        buf[from_len] = 0;// Добавление нулевого символа в конец полученного сообщения.
        cout << buf << endl;
        cout << "you:";
        cin >> A.name;

        if (A.name == "Bye") {
            break;
        }

        for (int i = 0; i < 4; i++)
            cin >> A.grades[i];
        send(s, (char*)&A, sizeof(A), 0);//посылаем серверу
        from_len = recv(s, (char*)&answer, sizeof(answer), 0);
        cout << "server: ";
        switch (answer)
        {
            case 2: {cout << " - имеется задолжность\n"; break; }
            case 3: {cout << " - степендии нет\n"; break; }
            case 4: {cout << " - обычная степендия\n"; break; }
            case 5: {cout << " - повышенная степендия\n"; break; }
            case -1: {cout << "Неверные данные!\n"; }
        }
    } while (true);

    cout << "exit to infinity" << endl;
    cin.get();
    closesocket(s);
    return 0;
}
