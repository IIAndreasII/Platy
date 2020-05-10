#ifndef DICE_MANAGER_H
#define DICE_MANAGER_H


enum class EDice;

class DiceManager
{
public:
	~DiceManager();

	inline const unsigned RollDie(const EDice aDie, const unsigned short& aModifier = 0);
	const unsigned RollDice(const EDice aDie, const unsigned aCount, const unsigned short& aModifier = 0);

private:
	DiceManager();


};

#endif