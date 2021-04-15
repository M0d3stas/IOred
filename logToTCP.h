#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class logToTCP
{
   public:
   logToTCP();
   logToTCP(std::string ip, int port);
   ~logToTCP();
   void init();

   //getters setters
    std::string ReturnIP();
    int returnPort();

    void setIP(std::string ip);
    void setPort(int port);

   private:
    bool _IPProvided;
    bool _PortProvided;
    std::string _IP;
    int _port;
    //for in Socket
    WSAData data;
    WORD ver = MAKEWORD(2, 2);
    //create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    //fill hint struct
    sockaddr_in hint;
    //connect to server
    int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));


   void initWinSock();
   void createSocket();
   void fillHintStruct();
   void connectToServ();

   void sendData(std::string log);
 
};

