#include "LogToText.h"

LogToText::LogToText()
{
	fileName = 	 "Log.txt";
	logFile.open(fileName);
}

LogToText::LogToText(std::string fileName)
{
	this->fileName = fileName;
	logFile.open(this->fileName);
}

LogToText::~LogToText()
{
}

void LogToText::sendLog(std::string log)
{
	if (logFile.is_open())
	{
		while (std::getline(logFile, oneLine))
		{

			previuosLogs.push_back(oneLine);
			linesCounted++;
		}
	}
	logFile.close();

	//adding another log

	std::ofstream logFileOut;
	logFileOut.open(fileName);

	for (int i = 0; i < linesCounted; i++)
	{
		logFileOut << previuosLogs[i] << std::endl;
	}

	logFileOut << log << std::endl;


	std::cout << log << "\n" << std::endl;
}

