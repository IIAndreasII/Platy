#ifndef PCH_H
#define PCH_H

#define DEBUG 1

// Window constants
constexpr unsigned RNG_SEED = 123456;

constexpr unsigned DEFAULT_WINDOW_WIDTH  = 1600;
constexpr unsigned DEFAULT_WINDOW_HEIGHT = 900;
constexpr unsigned DEFAULT_FRAMERATE = 144;
constexpr bool VSYNC = false;

#include <random>

#if DEBUG
#include <iostream>
#endif

template<typename C>
inline void SafeDelete(C*& aPtrToDelete)
{
	delete aPtrToDelete;
	aPtrToDelete = nullptr;
}

#endif