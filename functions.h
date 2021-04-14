#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")



namespace LogT
{
	void printAndSave(std::string message)
	{
		//chgecking that would not delete previuos logs


		std::ifstream logFile;
		logFile.open("Log.txt");
		std::string oneLine;
		int linesCounted = 0;
		std::vector<std::string> previuosLogs;



		if (logFile.is_open())
		{
			while (std::getline(logFile, oneLine))
			{

				previuosLogs.push_back(oneLine);
				linesCounted++;
			}
		}
		logFile.close();

		//adding another trace

		std::ofstream logFileOut;
		logFileOut.open("Log.txt");

		for (int i = 0; i < linesCounted; i++)
		{
			logFileOut << previuosLogs[i] << std::endl;
		}

		logFileOut << message << std::endl;


		std::cout << message << "\n" << std::endl;
	}
}

namespace LogTCP
{
	void printAndTCP(std::string Message)
	{

		std::cout << Message << std::endl;

		std::string ipAddress = "111.0.0.1";		//ip adress
		int port = 54000;						//listenint port # server

		WSAData data;
		WORD ver = MAKEWORD(2, 2);
		int wsResult = WSAStartup(ver, &data);
		if (wsResult != 0)					   //checking if connected
		{
			std::cout << "not connected to server" << std::endl;
			return;
		}

		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == INVALID_SOCKET)				 //checking if socet were created
		{
			std::cout << "SOCKET CANT BE CREATED" << std::endl;
			WSACleanup();
			return;
		}

		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

		int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
		if (connResult == SOCKET_ERROR)
		{
			std::cout << "ERROR CONNECTING TO SERVER" << std::endl;
			closesocket(sock);
			WSACleanup();
			return;
		}
		char buf[4096];

		do
		{
			int sendResult = send(sock, Message.c_str(), Message.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				ZeroMemory(buf, 4096);
				int bytesRecieved = recv(sock, buf, 4096, 0);
			}
		} while (Message.size() > 0);

		closesocket(sock);
		WSACleanup();
	}

}