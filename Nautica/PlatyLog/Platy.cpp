#include "PlatyLog/Log.h"

using namespace Platy;

int main()
{
	PlatyLog::Log::Init();

	PlatyLog::Log::LogDebug("Test msg");
	PlatyLog::Log::LogWarning("Test msg");
	PlatyLog::Log::LogCritical("Test msg");
	PlatyLog::Log::LogCritical(std::exception("Test exception"), "Test exception was thrown!");
	PlatyLog::Log::LogInformation("Test msg");

	PlatyLog::Log::Dispose();

	return 0;
}