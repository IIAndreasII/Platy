#ifndef MESSAGE_H
#define MESSAGE_H

#include "SFML/System/Vector2.hpp"


class Message
{
public:

	enum class EType
	{
		GAME_OVER,
		VICTORY,
		TILE_FLAGGED,
		TILE_UN_FLAGGED,
		MOUSE_ON_CLICK_LEFT,
		MOUSE_ON_CLICK_RIGHT,
		MOUSE_MOVED,
		TOGGLE_PAUSE,
		KEY_A_PRESSED,
		KEY_A_RELEASED,
		KEY_D_PRESSED,
		KEY_D_RELEASED,
		KEY_ESCAPE_PRESSED,
		KEY_ESCAPE_RELEASED,
		COUNT
	};

	Message();
	explicit Message(const sf::Vector2i& aPosition);
	Message(const sf::Vector2i& aPosition, int aWidth, int aHeight);
	~Message() = default;

	void SetFloat(float aValue);
	void SetInt(int aValue);
	void SetBool(bool aValue);

	const sf::Vector2i& GetPosition() const;
	sf::Vector2i GetSize() const;
	const int& GetInt() const;
	const float& GetFloat() const;
	const bool& GetBool() const;

private:

	sf::Vector2i myPosition;
	float myFloat;
	int myInt,
	    myWidth,
	    myHeight;
	bool myBool;
};


#endif
