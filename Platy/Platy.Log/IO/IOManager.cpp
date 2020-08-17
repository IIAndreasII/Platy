#include "IOManager.h"
#include "Util/Util.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <io.h>

std::string Platy::PlatyLog::IO::IOManager::myFileName;
std::ofstream Platy::PlatyLog::IO::IOManager::myFileStream;


Platy::PlatyLog::IO::IOManager::~IOManager()
{
	if (myFileStream && myFileStream.is_open())
	{
		myFileStream.close();
	}
}

void Platy::PlatyLog::IO::IOManager::Init()
{	
	if (CreateDirectoryA("Logs", NULL) != ERROR_PATH_NOT_FOUND)
	{
		myFileName = "Logs\\" + Core::Util::GetTime() + ".txt";
		myFileStream = std::ofstream(myFileName);
	}
	else
	{
		std::cout << "Could not create directory. Invalid path" << std::endl;
	}
}

void Platy::PlatyLog::IO::IOManager::Dispose()
{
	myFileStream.close();
	std::cout << "\nLog file saved to: " << myFileName << std::endl;
}

void Platy::PlatyLog::IO::IOManager::WriteToFile(const std::string line)
{
	if (myFileStream.is_open())
	{
		myFileStream << line << std::endl;
	}
}
