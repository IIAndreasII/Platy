#ifndef CHARACTER_SHEET_H
#define CHARACTER_SHEET_H

enum class ECharacterClass;
enum class ECharacterTrait;

#include <string>

typedef unsigned short mod_t;

// TODO: Make constructor!
class CharacterSheet
{
public:
	CharacterSheet(
		const ECharacterClass& aClass, 
		const std::string& aName,
		const bool& canLevelUp,
		const bool& hasInspiration,
		const unsigned& aLevel,
		const unsigned& someExperience,
		const unsigned& someRequiredExperience,
		const unsigned& someHitPoints,
		const unsigned& someHitPointMaximum,
		const mod_t& someAC,
		const mod_t& someSpeed,
		const mod_t& someStrength,
		const mod_t& someDexterity,
		const mod_t& someConstitution,
		const mod_t& someIntelligence,
		const mod_t& someWisdom);
	~CharacterSheet();


    void AddExperience(const unsigned someExperience);
	void IncreaseTraitValue(const ECharacterTrait aTrait, const mod_t aValue = 1);

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

	const mod_t& GetAC() const;
	const mod_t& GetSpeed() const;
	const mod_t& GetStrength() const;
	const mod_t& GetDexterity() const;
	const mod_t& GetConstituiton() const;
	const mod_t& GetIntelligence() const;
	const mod_t& GetWisdom() const;
	const mod_t GetProficiencyBonus() const;


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

	mod_t myAC;
	mod_t mySpeed;
	mod_t myStrength;
	mod_t myDexterity;
	mod_t myConstitution;
	mod_t myIntelligence;
	mod_t myWisdom;

};

#endif