#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

// TODO: Add suitable settings
// TODO: Load settings from file somewhere

class GameSettings
{
public:
	GameSettings() = delete;
	~GameSettings() = default;

	static void Init();

	/////////////////
	// Setters
	/////////////////
	static void SetGamePadDeadZone(const float& aValue);


	/////////////////
	// Getters
	/////////////////
	static const float& GetGamePadDeadZone();


private:

	static float myGamePadAxisDeadZone;
};

#endif
