#ifndef UTIL_H
#define UTIL_H

#include <string>

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
			template <typename C>
			static void SafeDelete(C*& aPtrToDelete)
			{
				delete aPtrToDelete;
				aPtrToDelete = nullptr;
			}

			static void ToLowerCase(std::string& aString);

			static int RandInt(int min, int max);

			static float RandFloat(float min, float max);

			static void ClampDeg(float& anAngle);

			template <typename T>
			static T Clamp(T min, T max, T& value);
		};
	}
}
#endif
