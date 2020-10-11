#include "Log.h"

#include <iostream>

#include "IO/IOManager.h"
#include "Util/Util.h"

constexpr auto CONSOLE_RED = 12;
constexpr auto CONSOLE_YELLOW = 14;
constexpr auto CONSOLE_GREEN = 10;
constexpr auto CONSOLE_GREY = 8;
constexpr auto CONSOLE_WHITE = 15;

namespace Platy
{
	HANDLE Log::myConsoleHandle;

	Log::~Log()
	{
	}

	void Log::Init()
	{
		myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(myConsoleHandle, CONSOLE_WHITE);
		IO::IOManager::Init();
	}

	void Log::Dispose()
	{
		IO::IOManager::Dispose();
	}

	void Log::Debug(const std::string& msg)
	{
		WriteLogMsg(ELogHeader::DEBUG, msg);
	}

	void Log::Warning(const std::string& msg)
	{
		WriteLogMsg(ELogHeader::WARNING, msg);
	}

	void Log::Warning(const std::exception& e, const std::string& msg)
	{
		WriteLogMsg(ELogHeader::WARNING, msg + ": " + e.what());
	}

	void Log::Critical(const std::string& msg)
	{
		WriteLogMsg(ELogHeader::CRITICAL, msg);
	}

	void Log::Critical(const std::exception& e, const std::string& msg)
	{
		WriteLogMsg(ELogHeader::CRITICAL, msg + ": " + e.what());
	}

	void Log::Information(const std::string& msg)
	{
		WriteLogMsg(ELogHeader::INFORMATION, msg);
	}

	Log::Log() = default;

	uint16_t Log::HeaderToColour(const ELogHeader& head)
	{
		switch (head)
		{
		case ELogHeader::DEBUG:
			return CONSOLE_GREY;
		case ELogHeader::INFORMATION:
			return CONSOLE_GREEN;
		case ELogHeader::WARNING:
			return CONSOLE_YELLOW;
		case ELogHeader::CRITICAL:
			return CONSOLE_RED;
		}
		return 0;
	}

	std::string Log::HeaderToString(const ELogHeader& head)
	{
		switch (head)
		{
		case ELogHeader::DEBUG:
			return "DBG ";
		case ELogHeader::INFORMATION:
			return "INFO";
		case ELogHeader::WARNING:
			return "WARN";
		case ELogHeader::CRITICAL:
			return "CRIT";
		}
		return "UNDEFINED";
	}

	void Log::WriteInColour(const ELogHeader& head, const std::string& str)
	{
		SetConsoleTextAttribute(myConsoleHandle, HeaderToColour(head));
		std::cout << str;
		SetConsoleTextAttribute(myConsoleHandle, CONSOLE_WHITE);
	}

	void Log::WriteLogMsg(const ELogHeader head, const std::string& msg)
	{
		const auto time = Core::Util::GetTime();
		const auto headString = HeaderToString(head);
		const auto line = "[" + time + "] [" + headString + "] " + msg;

		IO::IOManager::WriteToFile(line);

		std::cout << "[" << time << "] [";
		WriteInColour(head, headString);
		std::cout << "] " << msg << std::endl;
	}
}
