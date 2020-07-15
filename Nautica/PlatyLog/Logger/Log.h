#ifndef PLATYLOG_H
#define PLATYLOG_H

#include <string>
#include <exception>
#include <winnt.h>

namespace PlatyLog
{
	enum class SeverityToken
	{
		CRITICAL,
		FATAL
	};

	class Log
	{
	public:
		~Log();

		/// <summary>
		///	Initialize logger. Should only be called once in a program
		/// </summary>
		static void Init();

		// Debug logging
		static void LogDebug(const std::string msg);


		// Warning logging
		static void LogWarning(const std::string msg);
		
		static void LogWarning(const std::exception e, 
							   const std::string msg);

		// Critical logging
		static void LogCritical(const std::string msg, 
								const PlatyLog::SeverityToken st = PlatyLog::SeverityToken::CRITICAL);
		
		static void LogCritical(const std::exception e, 
								const std::string msg, 
								const PlatyLog::SeverityToken st = PlatyLog::SeverityToken::CRITICAL);

		// Information logging
		static void LogInformation(const std::string msg);



	private:
		Log();

		enum class LogHeader
		{
			DEBUG,
			WARNING,
			CRITICAL,
			FATAL,
			INFORMATION
		};

		static const std::string HeaderToString(const LogHeader& head);
		static const int HeaderToColour(const LogHeader& head);

		static void WriteInColour(const LogHeader& head, const std::string& str);

		static void WriteLogMsg(const LogHeader head, const std::string& msg);

		static HANDLE myConsoleHandle;
	};
}
#endif
