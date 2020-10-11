#include "GameSettings.h"

float GameSettings::myGamePadAxisDeadZone;


void GameSettings::Init()
{
	myGamePadAxisDeadZone = 25;
	// Load settings
}

void GameSettings::SetGamePadDeadZone(const float& aValue)
{
	myGamePadAxisDeadZone = aValue;
}

const float& GameSettings::GetGamePadDeadZone()
{
	return myGamePadAxisDeadZone;
}
