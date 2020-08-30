#ifndef PCH_H
#define PCH_H

#define MAIN_PC 1

constexpr unsigned int DEFAULT_WINDOW_WIDTH = 1280;
constexpr unsigned int DEFAULT_WINDOW_HEIGHT = 720;

#if MAIN_PC
constexpr unsigned int TARGET_FRAME_RATE = 144;
#else
constexpr unsigned int TARGET_FRAME_RATE = 60;
#endif



#endif
