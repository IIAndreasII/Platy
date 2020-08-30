#include "IOManager.h"
#include "Util/Util.h"
#include <iostream>
#include <Windows.h>
#include <io.h>

namespace Platy
{
	namespace PlatyLog
	{
		namespace IO
		{
			std::string IOManager::myFileName;
			std::ofstream IOManager::myFileStream;

			IOManager::~IOManager()
			{
				if (myFileStream && myFileStream.is_open())
				{
					myFileStream.close();
				}
			}

			void IOManager::Init()
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

			void IOManager::Dispose()
			{
				if (myFileStream && myFileStream.is_open())
				{
					myFileStream.close();
					std::cout << "\nLog saved to: " << myFileName << std::endl;
				}
			}

			void IOManager::WriteToFile(const std::string line)
			{
				if (myFileStream.is_open())
				{
					myFileStream << line << std::endl;
				}
			}
		}
	}
}
