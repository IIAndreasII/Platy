#include "IOManager.h"
#include "Util/Util.h"
#include <iostream>
#include <string>
#include <fstream>

std::string PlatyLog::IO::IOManager::myFileName;
std::ofstream PlatyLog::IO::IOManager::myFileStream;

PlatyLog::IO::IOManager::~IOManager()
{
	myFileStream.close();
}

void PlatyLog::IO::IOManager::Init()
{	
	myFileName = "Logs\\" + Util::GetTime() + ".txt";
	myFileStream = std::ofstream(myFileName);
}

void PlatyLog::IO::IOManager::WriteToFile(const std::string line)
{
	if (myFileStream.is_open())
	{
		myFileStream << line << std::endl;
	}
}
