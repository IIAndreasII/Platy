#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <string>


namespace PlatyLog
{
	namespace IO
	{
		class IOManager
		{
		public:
			~IOManager();

			static void Init();
		private:
			IOManager();

			static void WriteToFile(const std::string line);
			

			static std::string myFileName;
			static std::ofstream myFileStream;
		};
	}
}
#endif