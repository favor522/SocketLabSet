#include <iostream>
#pragma comment(lib,"wsock32.lib")
#include <string>
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;
#pragma warning(disable: 4996)

int main() {
	SOCKADDR_IN address;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(27015);
	address.sin_family = AF_INET;
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		cout << "WSAStartup failed with error: " << result << endl;
		return 1;
	}
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connect(Connection, (SOCKADDR*)&address, sizeof(address)) != 0) {
		cout << "Connection failed" << "\n";
		return 1;
	}
		cout << "Connection success";
		char text = recv(Connection, msg, sizeof(msg), NULL);
		cout << text << "\n";
	return 0;
}