
#include<iostream>

#define SCK_VERSION2 0x0202
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include<stdio.h>

using namespace std;


int main(int argc, const char** argv)
{
	WSAData wsadata;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsadata) != 0)
	{
		MessageBoxA(NULL, "winsock startup failed", "erorr", MB_OK | MB_ICONERROR);
		exit(1);
	}
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("179.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen);
	
		if (newConnection==0) {

			cout << "failed to accept the client." << endl;
			
		}
		else
		{
			cout << "client connected" << endl;
			char MOTD[256] = "welcome";
			send(newConnection, MOTD, sizeof(MOTD), NULL);

		}
		system("pause");
	
	return 0;
}