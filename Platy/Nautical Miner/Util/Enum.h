#ifndef ENUM_H
#define ENUM_H

enum class ECharacterClass
{
	CLERIC,
	KNIGHT,
	RANGER,
	WIZARD
};

enum class ECharacterTrait
{
	STRENGTH,
	CONSTITUION,
	INTELLIGENCE,
	DEXTERITY,
	WISDOM
};

enum class EDice
{
	d4 = 4,
	d6 = 6,
	d8 = 8,
	d10 = 10,
	d12 = 12,
	d20 = 20
};

enum class EGameState
{
	PLAYING,
	MAIN_MENU
};

#endif