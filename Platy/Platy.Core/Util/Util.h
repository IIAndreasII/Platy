#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <time.h>
#include <algorithm>

namespace Platy
{
	namespace Core
	{
		class Util
		{
		public:
			~Util();

			/// <summary>
			/// Gets current time in a d-m-y h-m-s format
			/// </summary>
			static std::string GetTime();

			/// <summary>
			/// Safely deletes a pointer
			/// </summary>
			template<typename C>
			static inline void SafeDelete(C*& aPtrToDelete)
			{
				delete aPtrToDelete;
				aPtrToDelete = nullptr;
			}

			static void ToLowerCase(std::string& aString);

			static int RandInt(const int min, const int max);

			static float RandFloat(const float min, const float max);

			static void ClampDeg(float& anAngle);

			template<typename T>
			static inline T Clamp(const T min, const T max, T& value);
		private:
			Util();
		};
	}
}
#endif