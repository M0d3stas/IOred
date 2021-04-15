#include "functions.h"
#include "LogToText.h"

int main()
{
    LogT::printAndSave("My message");

    // not working becasue no connection to server

      //LogTCP::printAndTCP("MY message");

    LogToText coutT("logFile2.txt");
    coutT.sendLog("message");




    return 0;
}