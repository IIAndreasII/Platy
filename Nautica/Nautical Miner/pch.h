#ifndef PCH_H
#define PCH_H

#define DEBUG 1
#define ASYNC 1
#define WORKSTATION 1
// Constants
constexpr bool VSYNC = false;


constexpr unsigned DEFAULT_WINDOW_WIDTH  = 1600;
constexpr unsigned DEFAULT_WINDOW_HEIGHT =  900;
#if WORKSTATION
constexpr unsigned DEFAULT_FRAMERATE     =  144;
#else
constexpr unsigned DEFAULT_FRAMERATE     =   60;
#endif

#if DEBUG
constexpr unsigned RNG_SEED = 123456;
#include <iostream>
#endif

template<typename C>
inline void SafeDelete(C*& aPtrToDelete)
{
	delete aPtrToDelete;
	aPtrToDelete = nullptr;
}

#endif