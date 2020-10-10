#ifndef MESSAGE_TYPE_H
#define MESSAGE_TYPE_H

namespace Platy
{
	namespace Game
	{
		enum class EMessageType
		{
			////////////////
			// Game related
			////////////////
			GAME_OVER,
			VICTORY,
			TILE_FLAGGED,
			TILE_UN_FLAGGED,
			TOGGLE_PAUSE,

			////////////////
			// Mouse 
			////////////////
			MOUSE_ON_CLICK_LEFT,
			MOUSE_ON_CLICK_RIGHT,
			MOUSE_MOVED,

			////////////////
			// Keyboard
			////////////////
			KEY_A_PRESSED,
			KEY_A_RELEASED,
			KEY_D_PRESSED,
			KEY_D_RELEASED,
			KEY_ESCAPE_PRESSED,
			KEY_ESCAPE_RELEASED,

			////////////////
			// Game pad
			////////////////
			GAME_PAD_A_PRESSED,
			GAME_PAD_B_PRESSED,
			GAME_PAD_X_PRESSED,
			GAME_PAD_Y_PRESSED,
			GAME_PAD_LS_PRESSED,
			GAME_PAD_LB_PRESSED,
			GAME_PAD_RB_PRESSED,
			GAME_PAD_RS_PRESSED,

			GAME_PAD_A_RELEASED,
			GAME_PAD_B_RELEASED,
			GAME_PAD_X_RELEASED,
			GAME_PAD_Y_RELEASED,
			GAME_PAD_LB_RELEASED,
			GAME_PAD_RB_RELEASED,
			GAME_PAD_LS_RELEASED,
			GAME_PAD_RS_RELEASED,

			GAME_PAD_LT_CHANGED,
			GAME_PAD_RT_CHANGED,


			COUNT
		};
	}
}
#endif
