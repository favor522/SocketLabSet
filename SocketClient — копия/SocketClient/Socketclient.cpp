#include <iostream>
#pragma comment(lib,"wsock32.lib")
#include <string>
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;
#pragma warning(disable: 4996)

int main() {
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 1), &wsaData);
	if (result != 0) {
		cout << "WSAStartup failed with error: " << result << endl;
		return 1;
	}
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(27015);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		cout << "Connection failed" << "\n";
		return 1;
	}
		cout << "Connection success" << "\n";
		char msg[256];
		char pos[256];
		recv(Connection, msg, sizeof(msg), NULL);
		cout << msg << "\n";
		recv(Connection, pos, sizeof(pos), NULL);
		cout << "Your position is: " << pos << "\n";
	return 0;
}