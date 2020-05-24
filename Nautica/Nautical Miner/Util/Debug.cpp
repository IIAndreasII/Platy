#include "..\pch.h"
#include "..\Util\Debug.h"
#include <fstream>
#include <ctime>

std::vector<std::string> Debug::myLogEntries;

Debug::~Debug()
{
}

void Debug::Init()
{
	myLogEntries = std::vector<std::string>();
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
	std::cout << "Debug session finished. Log written to \"" << tempPath << "\"" << std::endl;
#endif
}

void Debug::Log(const std::string entry, const bool success)
{
#ifdef DEBUG
	std::string msg;
	if (success)
	{
		std::cout << GetTime() << ": -OK- " << entry << std::endl;
		msg = "-OK- ";
	}
	else
	{
		std::cout << GetTime() << ": -ERROR- " << entry << std::endl;
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
