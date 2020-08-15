#include "..\pch.h"
#include "..\Util\Debug.h"
#include <fstream>
#include <ctime>
#include <Windows.h>

std::vector<std::string> Debug::myLogEntries;

Debug::~Debug()
{
}

void Debug::Init()
{
	myLogEntries = std::vector<std::string>();
	std::cout << "Debug session started.\n--------------------------------------------------------------------------------------------" << std::endl;
}

void Debug::FinishSession()
{
#ifdef DEBUG
	std::string tempPath = "Logs/" + GetTime() + ".txt";
	std::ofstream tempLogFile(tempPath); 

	if (tempLogFile)
	{
		for (size_t i = 0; i < myLogEntries.size(); i++)
		{
			tempLogFile << myLogEntries[i] << std::endl;
		}
		tempLogFile.close();
	}
	std::cout << "--------------------------------------------------------------------------------------------\nDebug session finished. Log written to \"" << tempPath << "\"" << std::endl;
#endif
}

void Debug::UpdateDebugElements(const float& deltaTime)
{
}

void Debug::Log(const std::string entry, const bool success)
{
#ifdef DEBUG
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string msg;
	if (success)
	{
		std::cout << GetTime() << ": ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		std::cout << "-OK- ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << entry << std::endl;
		msg = "-OK- ";
	}
	else
	{
		std::cout << GetTime() << ": ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "-ERROR- ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << entry << std::endl;
		msg = "-ERROR- ";
	}
	msg += entry;
	myLogEntries.push_back(msg);
#endif
}

std::string Debug::GetTime()
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H-%M-%S", &timeinfo);
	std::string str(buffer);
	return str;
}
