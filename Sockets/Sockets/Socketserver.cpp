#include <iostream>
#pragma comment(lib,"wsock32.lib")
#include <string>
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;
#pragma warning(disable: 4996)

int main(){
	SOCKADDR_IN address;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(27015);
	address.sin_family = AF_INET;
	int sizeofaddress = sizeof(address);
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		cout << "WSAStartup failed with error: " << result << endl;
		return 1;
	}
	bind(sock, (SOCKADDR*)&address, sizeof(address));
	listen(sock, SOMAXCONN);
	SOCKET NewConnection;
	NewConnection = accept(sock, (SOCKADDR*)&address, &sizeofaddress);
	 if (NewConnection == 0) {
		cout << "Connection error!" << "\n";
	}
	else {
		cout << "Connection to server success!" << "\n";
		system("pause");
		char msg[256] = "Server connected succesefully! Welcome!";
		send(NewConnection, msg, sizeof(msg), NULL);
	}
	return 0;
}