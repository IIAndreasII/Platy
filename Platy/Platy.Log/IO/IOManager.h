#ifndef IOMANAGER_H
#define IOMANAGER_H

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
				/// Writes line to current filestream
				/// </summary>
				/// <param name="line">Line to write</param>
				static void WriteToFile(const std::string line);

			private:
				IOManager();

				static std::string myFileName;
				static std::ofstream myFileStream;
			};
		}
	}
}
#endif