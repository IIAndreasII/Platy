#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <time.h>

namespace Platy
{
	namespace Util
	{	
		static std::string GetTime()
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

		template<typename C>
		static inline void SafeDelete(C*& aPtrToDelete)
		{
			delete aPtrToDelete;
			aPtrToDelete = nullptr;
		}
	};
}
#endif