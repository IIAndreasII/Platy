#include <iostream>

#include "Log.h"

int main()
{
	Platy::PlatyLog::Log::Init();

	Platy::PlatyLog::Log::Debug("Test msg");
	Platy::PlatyLog::Log::Warning("Test msg");
	Platy::PlatyLog::Log::Critical("Test msg");
	Platy::PlatyLog::Log::Critical(std::exception("Test exception"), "Test exception was thrown!");
	Platy::PlatyLog::Log::Information("Test msg");

	Platy::PlatyLog::Log::Dispose();

	return 0;
}
