#include <iostream>
#pragma comment(lib,"wsock32.lib")
#include <string>
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;
#pragma warning(disable: 4996)

int main(){
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
	int sizeofaddr = sizeof(addr);
	SOCKET Connection[5];
	int Count = 0;

	SOCKET sock = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock, (SOCKADDR*)&addr, sizeof(addr));
	listen(sock, 5);

	SOCKET NewConnection;
	for(int i = 0; i < 5; i++){
		NewConnection = accept(sock, (SOCKADDR*)&addr, &sizeofaddr);

		if (NewConnection == 0) {
			cout << "Connection error!" << "\n";
		}
		cout << "Connection to server success!" << "\n";
		char msg[256] = "Server connected succesefully! Welcome! Your position is:";
		send(NewConnection, msg, sizeof(msg), NULL);
		char pos[256] = Count;
		send(NewConnection, pos, sizeof(pos), NULL);
		Connection[i] = NewConnection;
		Count++;
		system("pause");
		return 0;
	}
}