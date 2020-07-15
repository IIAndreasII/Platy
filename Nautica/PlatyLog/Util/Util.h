#ifndef UTIL_H
#define UTIL_H

#include <string>

namespace PlatyLog
{
	class Util
	{
	public:
		~Util();

		static std::string GetTime();

	private:
		Util();

	};
}
#endif