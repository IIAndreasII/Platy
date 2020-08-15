#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <time.h>
#include <algorithm>

namespace Platy
{
	namespace Core
	{
		namespace Util
		{
			/// <summary>
			/// Gets current time in a d-m-y h-m-s format
			/// </summary>
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

			/// <summary>
			/// Safely deletes a pointer
			/// </summary>
			template<typename C>
			static inline void SafeDelete(C*& aPtrToDelete)
			{
				delete aPtrToDelete;
				aPtrToDelete = nullptr;
			}

			void ToLowerCase(std::string& aString)
			{
				std::transform(aString.begin(), aString.end(), aString.begin(), [](unsigned char c) {return std::tolower(c); });
			}

			int RandInt(const int min, const int max)
			{
				return std::rand() % min + max;
			}

			float RandFloat(const float min, const float max)
			{
				return min + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (max - min)));
			}

			void ClampDeg(float& anAngle)
			{
				if (anAngle > 360)
				{
					anAngle -= 360;
				}
				else if (anAngle < 0)
				{
					anAngle += 360;
				}
			}

			template<typename T>
			inline T Clamp(const T min, const T max, T& value)
			{
				if (value < min)
				{
					return min;
				}
				if (value > max)
				{
					return max;
				}
				return value;
			}
		};
	}
}
#endif