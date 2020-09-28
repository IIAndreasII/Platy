#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#include <string>
#include <fstream>


namespace Platy
{
	namespace PlatyLog
	{
		namespace IO
		{
			class IOManager
			{
			public:
				~IOManager();

				static void Init();

				/// <summary>
				/// 
				/// </summary>
				static void Dispose();

				/// <summary>
				/// Writes line to current file stream
				/// </summary>
				/// <param name="line">Line to write</param>
				static void WriteToFile(const std::string& line);

			private:
				static std::string myFileName;
				static std::ofstream myFileStream;
			};
		}
	}
}
#endif
