#include <iostream>
#include "Log.h"
#include <Util\Util.h>
#include <Windows.h>

enum class PlatyLog::Log::LogHeader;

#define CONSOLE_RED        12
#define CONSOLE_RED_DARK    4
#define CONSOLE_YELLOW     14
#define CONSOLE_GREEN      10
#define CONSOLE_GREEN_DARK  2
#define CONSOLE_GREY        8
#define CONSOLE_WHITE      15

int main()
{
    std::cout << "Hello World!\n";
}

PlatyLog::Log::~Log()
{
}

void PlatyLog::Log::Init()
{
    myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void PlatyLog::Log::LogDebug(const std::string msg)
{
}

void PlatyLog::Log::LogWarning(const std::string msg)
{
}

void PlatyLog::Log::LogWarning(const std::exception e, const std::string msg)
{
}

void PlatyLog::Log::LogCritical(const std::string msg, const PlatyLog::SeverityToken st)
{
}

void PlatyLog::Log::LogCritical(const std::exception e, const std::string msg, const PlatyLog::SeverityToken st)
{
}

void PlatyLog::Log::LogInformation(const std::string msg)
{
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

const int PlatyLog::Log::HeaderToColour(const LogHeader& head)
{
    switch (head)
    {
    case LogHeader::DEBUG:
        return CONSOLE_GREY;
    case LogHeader::INFORMATION:
        return CONSOLE_GREEN_DARK;
    case LogHeader::WARNING:
        return CONSOLE_YELLOW;
    case LogHeader::CRITICAL:
        return CONSOLE_RED;
    case LogHeader::FATAL:
        return CONSOLE_RED_DARK;
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
    std::cout << '[' << PlatyLog::Util::GetTime() << '] [';
    WriteInColour(head, HeaderToString(head));
    std::cout << '] ' << msg << std::endl;
}
