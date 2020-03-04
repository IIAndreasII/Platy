#ifndef PCH_H
#define PCH_H

#define DEBUG

// Window constants
constexpr unsigned RNG_SEED = 123456;

constexpr unsigned DEFAULT_WINDOW_WIDTH  = 800;
constexpr unsigned DEFAULT_WINDOW_HEIGHT = 1000;
constexpr bool VSYNC = false;

#include <random>

template<typename C> inline void SafeDelete(C*& aPtrToDelete)
{
	delete aPtrToDelete;
	aPtrToDelete = nullptr;
}

inline float RandomInt(const int min, const int max) 
{
	return std::rand() % min + max;
}

#endif