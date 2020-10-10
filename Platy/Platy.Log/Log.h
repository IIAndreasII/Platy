#ifndef PLATY_LOG_H
#define PLATY_LOG_H

#include <string>
#include <exception>
#include <Windows.h>

namespace Platy
{
	/// <summary>
	/// Singleton class for logging and debugging
	/// </summary>
	class Log
	{
	public:
		Log() = delete;
		~Log() = default;

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
		static void Debug(const std::string& msg);
#pragma endregion Warning

#pragma region Warning
		/// <summary>
		/// Logs warning
		/// </summary>
		/// <param name="msg">Message</param>
		static void Warning(const std::string& msg);

		/// <summary>
		/// Logs warning
		/// </summary>
		/// <param name="e">Any thrown exception</param>
		/// <param name="msg">Message</param>
		static void Warning(const std::exception& e,
		                    const std::string& msg);
#pragma endregion Warning

#pragma region Critical

		/// <summary>
		/// Logs critical error
		/// </summary>
		/// <param name="msg">Message</param>
		static void Critical(const std::string& msg);

		/// <summary>
		/// Logs critical error
		/// </summary>
		/// <param name="e">Any thrown exception</param>
		/// <param name="msg">Message</param>
		static void Critical(const std::exception& e,
		                     const std::string& msg);
#pragma endregion Critical

#pragma region Information
		/// <summary>
		/// Logs information
		/// </summary>
		/// <param name="msg">Message</param>
		static void Information(const std::string& msg);
#pragma endregion Information

	private:

		static HANDLE myConsoleHandle;

		enum class ELogHeader
		{
			CRITICAL,
			DEBUG,
			INFORMATION,
			WARNING,
		};

#pragma region Helper Classes


#pragma endregion Helper Classes

#pragma region Private Helpers Methods

		static uint16_t HeaderToColour(const ELogHeader& head);
		static std::string HeaderToString(const ELogHeader& head);

		static void WriteInColour(const ELogHeader& head, const std::string& str);

		static void WriteLogMsg(ELogHeader head, const std::string& msg);

#pragma endregion Private Helper Methods
	};
}
#endif
