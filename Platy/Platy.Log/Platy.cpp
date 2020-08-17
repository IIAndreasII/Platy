#include "Log.h"

using namespace Platy;

int main()
{
	PlatyLog::Log::Init();

	PlatyLog::Log::Debug("Test msg");
	PlatyLog::Log::Warning("Test msg");
	PlatyLog::Log::Critical("Test msg");
	PlatyLog::Log::Critical(std::exception("Test exception"), "Test exception was thrown!");
	PlatyLog::Log::Information("Test msg");

	PlatyLog::Log::Dispose();

	return 0;
}