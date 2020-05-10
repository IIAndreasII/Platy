#ifndef CHARACTER_SHEET_H
#define CHARACTER_SHEET_H

enum class ECharacterClass;
enum class ECharacterTrait;

#include <string>

// TODO: Make constructor!
class CharacterSheet
{
public:
	CharacterSheet(const );
	~CharacterSheet();


    inline void AddExperience(const unsigned someExperience);
	void IncreaseTraitValue(const ECharacterTrait aTrait, const unsigned short aValue = 1);

	///////////////////////////////////////////////////////
    // Get
	///////////////////////////////////////////////////////
	const ECharacterClass& GetClass() const;

	const std::string& GetName() const;

	const bool IsAlive() const;
	const bool& HasInspiration() const;

	const short GetModifier(const ECharacterTrait aTrait);

	const unsigned& GetHitPoints() const;
	const unsigned& GetHitPointMaximum() const;

	const unsigned short& GetAC() const;
	const unsigned short& GetSpeed() const;
	const unsigned short& GetStrength() const;
	const unsigned short& GetDexterity() const;
	const unsigned short& GetConstituiton() const;
	const unsigned short& GetIntelligence() const;
	const unsigned short& GetWisdom() const;
	const unsigned short GetProficiencyBonus() const;


private:
	const ECharacterClass myClass;

	std::string myName;

	bool myCanLevelUp;
	bool myHasInspiration;

	unsigned myLevel;
	unsigned myExperience;
	unsigned myRequiredExperience;
	unsigned myHitPoints;
	unsigned myHitPointMaximum;

	unsigned short myAC;
	unsigned short mySpeed;
	unsigned short myStrength;
	unsigned short myDexterity;
	unsigned short myConstitution;
	unsigned short myIntelligence;
	unsigned short myWisdom;

};

#endif