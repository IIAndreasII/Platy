#ifndef PLATYLOG_H
#define PLATYLOG_H

#include <string>
#include <exception>
#include <Windows.h>

namespace Platy
{
	namespace PlatyLog
	{
		class Log
		{
		public:
			~Log();

			/// <summary>
			///	Initializes logger. Should only be called once in a program
			/// </summary>
			static void Init();

			/// <summary>
			/// Disposes logger. Should be called at end of program
			/// </summary>
			static void Dispose();

#pragma region Debug
			/// <summary>
			/// Logs debug message
			/// </summary>
			/// <param name="msg">Message</param>
			static void LogDebug(const std::string& msg);
#pragma endregion Warning

#pragma region Warning
			/// <summary>
			/// Logs warning
			/// </summary>
			/// <param name="msg">Message</param>
			static void LogWarning(const std::string& msg);

			/// <summary>
			/// Logs warning
			/// </summary>
			/// <param name="e">Any thrown exception</param>
			/// <param name="msg">Message</param>
			static void LogWarning(const std::exception& e,
				const std::string& msg);
#pragma endregion Warning

#pragma region Critical

			/// <summary>
			/// Logs critical error
			/// </summary>
			/// <param name="msg">Message</param>
			static void LogCritical(const std::string& msg);

			/// <summary>
			/// Logs critical error
			/// </summary>
			/// <param name="e">Any thrown exception</param>
			/// <param name="msg">Message</param>
			static void LogCritical(const std::exception& e,
				const std::string& msg);
#pragma endregion Critical

#pragma region Information
			/// <summary>
			/// Logs information
			/// </summary>
			/// <param name="msg">Message</param>
			static void LogInformation(const std::string& msg);
#pragma endregion Information

		private:
			Log();

			static HANDLE myConsoleHandle;

			enum class LogHeader
			{
				CRITICAL,
				DEBUG,
				INFORMATION,
				WARNING,
			};

#pragma region Private Helpers Methods

			static const int HeaderToColour(const LogHeader& head);
			static const std::string HeaderToString(const LogHeader& head);

			static void WriteInColour(const LogHeader& head, const std::string& str);

			static void WriteLogMsg(const LogHeader head, const std::string& msg);

#pragma endregion Private Helper Methods
		};
	}
}
#endif
