#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class LogToText
{
	public:
	LogToText();
	LogToText(std::string fileName);
	~LogToText();

	void sendLog(std::string log);
	void loadLogFile();
	void addToLog(std::string log);

	private:
	std::string fileName;
	std::string oneLine;
	std::ifstream logFile;
	int linesCounted;
	std::vector<std::string> previuosLogs;



};

