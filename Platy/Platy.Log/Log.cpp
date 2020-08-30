#include "Log.h"

#include <iostream>

#include "IO/IOManager.h"
#include "Util/Util.h"

#define CONSOLE_RED        12
#define CONSOLE_RED_DARK    4
#define CONSOLE_YELLOW     14
#define CONSOLE_GREEN      10
#define CONSOLE_GREEN_DARK  2
#define CONSOLE_GREY        8
#define CONSOLE_WHITE      15


namespace Platy
{
    namespace PlatyLog
    {
        HANDLE Log::myConsoleHandle;

        Log::~Log()
        {
        }

        void Log::Init()
        {
            myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            IO::IOManager::Init();
        }

        void Log::Dispose()
        {
            IO::IOManager::Dispose();
        }

        void Log::Debug(const std::string& msg)
        {
            WriteLogMsg(LogHeader::DEBUG, msg);
        }

        void Log::Warning(const std::string& msg)
        {
            WriteLogMsg(LogHeader::WARNING, msg);
        }

        void Log::Warning(const std::exception& e, const std::string& msg)
        {
            WriteLogMsg(LogHeader::WARNING, msg + ": " + e.what());
        }

        void Log::Critical(const std::string& msg)
        {
            WriteLogMsg(LogHeader::CRITICAL, msg);
        }

        void Log::Critical(const std::exception& e, const std::string& msg)
        {
            WriteLogMsg(LogHeader::CRITICAL, msg + ": " + e.what());
        }

        void Log::Information(const std::string& msg)
        {
            WriteLogMsg(LogHeader::INFORMATION, msg);
        }

        const int Log::HeaderToColour(const LogHeader& head)
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
            default:
                return CONSOLE_WHITE;
            }
        }

        const std::string Log::HeaderToString(const LogHeader& head)
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
            default:
                return "UNDEFINED";
            }
        }

        void Log::WriteInColour(const LogHeader& head, const std::string& str)
        {
            SetConsoleTextAttribute(myConsoleHandle, HeaderToColour(head));
            std::cout << str;
            SetConsoleTextAttribute(myConsoleHandle, CONSOLE_WHITE);
        }

        void Log::WriteLogMsg(const LogHeader head, const std::string& msg)
        {
            std::string time = Core::Util::GetTime();
            std::string headString = HeaderToString(head);
            std::string line = "[" + time + "] [" + headString + "] " + msg;

            PlatyLog::IO::IOManager::WriteToFile(line);

            std::cout << "[" << time << "] [";
            WriteInColour(head, headString);
            std::cout << "] " << msg << std::endl;
        }
    }
}