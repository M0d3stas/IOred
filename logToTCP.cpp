#include "logToTCP.h"

logToTCP::logToTCP()
{
	_IPProvided = false;
	_PortProvided = false;
}

logToTCP::logToTCP(std::string ip, int port)
{
	this->_IP = ip;
	_IPProvided = true;
	this->_port = port;
	_PortProvided = true;
}

logToTCP::~logToTCP()
{
	closesocket(sock);
	WSACleanup();
}

std::string logToTCP::ReturnIP()
{
	if (_IPProvided == true)
	{
		return _IP;
	}
	else
	{
		return  "0";
	}
}

int logToTCP::returnPort()
{
	if (_PortProvided == true)
	{
		return _port;
	}
	else
	{
		return 0;
	}
}

void logToTCP::setIP(std::string ip)
{
	this->_IP = ip;
	_IPProvided = true;
}

void logToTCP::setPort(int port)
{
	this->_port = port;
}

void logToTCP::init()
{
	if (_IPProvided && _PortProvided)
	{
		initWinSock();
		createSocket();
		fillHintStruct();
		connectToServ();
	}
}

void logToTCP::initWinSock()
{

	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)					   //checking if connected
	{
		std::cout << "not connected to server" << std::endl;
		return;
	}
}

void logToTCP::createSocket()
{

	if (sock == INVALID_SOCKET)				 //checking if socet were created
	{
		std::cout << "SOCKET CANT BE CREATED" << std::endl;
		WSACleanup();
		return;
	}
}

void logToTCP::fillHintStruct()
{
	hint.sin_family = AF_INET;
	hint.sin_port = htons(_port);
	inet_pton(AF_INET, _IP.c_str(), &hint.sin_addr);

}

void logToTCP::connectToServ()
{
	if (connResult == SOCKET_ERROR)
	{
		std::cout << "ERROR CONNECTING TO SERVER" << std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
}

void logToTCP::sendData(std::string log)
{
	char buf[4096];

	do
	{
		int sendResult = send(sock, log.c_str(), log.size() + 1, 0);
		if (sendResult != SOCKET_ERROR)
		{
			ZeroMemory(buf, 4096);
			int bytesRecieved = recv(sock, buf, 4096, 0);
		}
	} while (log.size() > 0);
	std::cout << log  <<std::endl;
}
