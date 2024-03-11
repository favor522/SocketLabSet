#include <iostream>
#include <string>
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;

int main() {
	const char* address = "127.0.0.1";
	const char* port = "27015";
	int domain = AF_UNIX;
	int type = SOCK_STREAM;
	int protocol = 0;
	int socket(domain, type, protocol);
	int connect(int csockfd, const struct sockaddr* address, size_t add_len);
	return 0;
}