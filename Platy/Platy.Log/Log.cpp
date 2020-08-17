#include <iostream>
#include "Log.h"
#include "IO/IOManager.h"
#include "Util/Util.h"

#define CONSOLE_RED        12
#define CONSOLE_RED_DARK    4
#define CONSOLE_YELLOW     14
#define CONSOLE_GREEN      10
#define CONSOLE_GREEN_DARK  2
#define CONSOLE_GREY        8
#define CONSOLE_WHITE      15

using namespace Platy;

HANDLE PlatyLog::Log::myConsoleHandle;
enum class PlatyLog::Log::LogHeader;

PlatyLog::Log::~Log()
{
}

void PlatyLog::Log::Init()
{
    myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    PlatyLog::IO::IOManager::Init();
}

void PlatyLog::Log::Dispose()
{
    PlatyLog::IO::IOManager::Dispose();
}

void PlatyLog::Log::Debug(const std::string& msg)
{
    WriteLogMsg(PlatyLog::Log::LogHeader::DEBUG, msg);
}

void PlatyLog::Log::Warning(const std::string& msg)
{
    WriteLogMsg(PlatyLog::Log::LogHeader::WARNING, msg);
}

void PlatyLog::Log::Warning(const std::exception& e, const std::string& msg)
{
    WriteLogMsg(PlatyLog::Log::LogHeader::WARNING, msg + ": " + e.what());
}

void PlatyLog::Log::Critical(const std::string& msg)
{
    WriteLogMsg(PlatyLog::Log::LogHeader::CRITICAL, msg);
}

void PlatyLog::Log::Critical(const std::exception& e, const std::string& msg)
{
    WriteLogMsg(PlatyLog::Log::LogHeader::CRITICAL, msg + ": " + e.what());
}

void PlatyLog::Log::Information(const std::string& msg)
{
    WriteLogMsg(PlatyLog::Log::LogHeader::INFORMATION, msg);
}

const int PlatyLog::Log::HeaderToColour(const LogHeader& head)
{
    switch (head)
    {
    case LogHeader::DEBUG:
        return CONSOLE_GREY;
    case LogHeader::INFORMATION:
        return CONSOLE_GREEN;
    case LogHeader::WARNING:
        return CONSOLE_YELLOW;
    case LogHeader::CRITICAL:
        return CONSOLE_RED;
    }
}

const std::string PlatyLog::Log::HeaderToString(const LogHeader& head)
{
    switch (head)
    {
    case LogHeader::DEBUG:
        return "DBG ";
    case LogHeader::INFORMATION:
        return "INFO";
    case LogHeader::WARNING:
        return "WARN";
    case LogHeader::CRITICAL:
        return "CRIT";
    }
}

void PlatyLog::Log::WriteInColour(const LogHeader& head, const std::string& str)
{
    SetConsoleTextAttribute(myConsoleHandle, HeaderToColour(head));
    std::cout << str;
    SetConsoleTextAttribute(myConsoleHandle, CONSOLE_WHITE);
}

void PlatyLog::Log::WriteLogMsg(const LogHeader head, const std::string& msg)
{
    auto time = Core::Util::GetTime();
    std::string headString = HeaderToString(head);
    std::string line = "[" + time + "] [" + headString + "] " + msg;

    PlatyLog::IO::IOManager::WriteToFile(line);

    std::cout << "[" << time << "] [";
    WriteInColour(head, headString);
    std::cout << "] " << msg << std::endl;
}
