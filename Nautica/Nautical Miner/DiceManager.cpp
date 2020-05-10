#include "Util.h"
#include "DiceManager.h"
#include "Enum.h"

DiceManager::~DiceManager()
{
}

inline const unsigned DiceManager::RollDie(const EDice aDie, const unsigned short& aModifier)
{
	return Util::RandInt(1, static_cast<int>(aDie)) + aModifier;
}

const unsigned DiceManager::RollDice(const EDice aDie, const unsigned aCount, const unsigned short& aModifier)
{
	unsigned tempSum = 0;
	for (size_t i = 0; i < aCount; i++)
	{
		tempSum += RollDie(aDie);
	}
	return tempSum + aModifier;
}
