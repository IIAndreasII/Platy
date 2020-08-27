#include "Util.h"

Platy::Core::Util::~Util()
{
}

std::string Platy::Core::Util::GetTime()
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[44];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H-%M-%S", &timeinfo);
	std::string str(buffer);
	return str;
}

void Platy::Core::Util::ToLowerCase(std::string& aString)
{
	std::transform(aString.begin(), aString.end(), aString.begin(), [](unsigned char c) {return std::tolower(c); });
}

int Platy::Core::Util::RandInt(const int min, const int max)
{
	return std::rand() % max + min;
}

float Platy::Core::Util::RandFloat(const float min, const float max)
{
	return min + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

void Platy::Core::Util::ClampDeg(float& anAngle)
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

//template<typename C>
//void Platy::Core::Util::SafeDelete(C*& aPtrToDelete)
//{
//	delete aPtrToDelete;
//	aPtrToDelete = nullptr;
//}

template<typename T>
inline T Platy::Core::Util::Clamp(const T min, const T max, T& value)
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
