#include "Util.h"
#include <time.h>


std::string PlatyLog::Util::GetTime()
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H-%M-%S", &timeinfo);
	std::string str(buffer);
	return str;
}