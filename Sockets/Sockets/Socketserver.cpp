#include <iostream>
#include <string>
#include <sys/types.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;

int main1(){
	int bind(int sockfd, const struct sockaddr* address, size_t add_len);
	int listen(int sockfd, int queue_size);
	int accept(int sockfd, struct sockaddr* address, size_t * add_len);
	return 0;
}