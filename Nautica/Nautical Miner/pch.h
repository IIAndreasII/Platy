#ifndef PCH_H
#define PCH_H

#define DEBUG

// Window constants
constexpr unsigned DEFAULT_WINDOW_WIDTH  = 800;
constexpr unsigned DEFAULT_WINDOW_HEIGHT = 800;
constexpr bool VSYNC = false;

template<typename C> inline void SafeDelete(C*& aPtrToDelete)
{
	delete (aPtrToDelete);
	aPtrToDelete = nullptr;
}

#endif