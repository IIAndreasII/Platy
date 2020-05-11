#include "CharacterSheet.h"
#include "Enum.h"


CharacterSheet::CharacterSheet(
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
	const mod_t& someWisdom)
	:
	myClass(aClass),
	myName(aName),
	myCanLevelUp(canLevelUp),
	myHasInspiration(hasInspiration),
	myLevel(aLevel),
	myExperience(someExperience),
	myRequiredExperience(someRequiredExperience),
	myHitPoints(someHitPoints),
	myHitPointMaximum(someHitPointMaximum),
	myAC(someAC),
	mySpeed(someSpeed),
	myStrength(someStrength),
	myDexterity(someDexterity),
	myConstitution(someConstitution),
	myIntelligence(someIntelligence),
	myWisdom(someWisdom)
{
}

CharacterSheet::~CharacterSheet()
{
}

void CharacterSheet::IncreaseTraitValue(const ECharacterTrait aTrait, const mod_t aValue)
{
	mod_t* tempTrait = NULL;
	switch (aTrait)
	{
	case ECharacterTrait::CONSTITUION:
		tempTrait = &myConstitution;
		break;
	case ECharacterTrait::DEXTERITY:
		tempTrait = &myDexterity;
		break;
	case ECharacterTrait::INTELLIGENCE:
		tempTrait = &myIntelligence;
		break;
	case ECharacterTrait::STRENGTH:
		tempTrait = &myStrength;
		break;
	case ECharacterTrait::WISDOM:
		tempTrait = &myWisdom;
		break;
	default:
		break;
	}
	*tempTrait = *tempTrait + aValue > 20 ? 20 : *tempTrait + aValue;
}

const short CharacterSheet::GetModifier(const ECharacterTrait aTrait)
{
	short tempValue = 0;
	switch (aTrait)
	{
	case ECharacterTrait::CONSTITUION:
		tempValue = myConstitution;
		break;
	case ECharacterTrait::DEXTERITY:
		tempValue = myDexterity;
		break;
	case ECharacterTrait::INTELLIGENCE:
		tempValue = myIntelligence;
		break;
	case ECharacterTrait::STRENGTH:
		tempValue = myStrength;
		break;
	case ECharacterTrait::WISDOM:
		tempValue = myWisdom;
		break;
	default:
		break;
	}
	if (tempValue >= 10)
	{
		return (tempValue - 10) / 2;
	}
	return (tempValue - 10) / 2 - 1;
}

const ECharacterClass& CharacterSheet::GetClass() const
{
	return myClass;
}

const bool CharacterSheet::IsAlive() const
{
	return myHitPoints != 0;
}

const bool& CharacterSheet::HasInspiration() const
{
	return myHasInspiration;
}

const std::string& CharacterSheet::GetName() const
{
	return myName;
}

const unsigned& CharacterSheet::GetHitPoints() const
{
	return myHitPoints;
}

const unsigned& CharacterSheet::GetHitPointMaximum() const
{
	return myHitPointMaximum;
}

const unsigned short& CharacterSheet::GetAC() const
{
	return myAC;
}

const unsigned short& CharacterSheet::GetSpeed() const
{
	return mySpeed;
}

const unsigned short& CharacterSheet::GetStrength() const
{
	return myStrength;
}

const unsigned short& CharacterSheet::GetDexterity() const
{
	return myDexterity;
}

const unsigned short& CharacterSheet::GetConstituiton() const
{
	return myConstitution;
}

const unsigned short& CharacterSheet::GetIntelligence() const
{
	return myIntelligence;
}

const unsigned short& CharacterSheet::GetWisdom() const
{
	return myWisdom;
}

const unsigned short CharacterSheet::GetProficiencyBonus() const
{
	return myLevel % 4 + 2;
}

void CharacterSheet::AddExperience(const unsigned someExperience)
{
	myExperience += someExperience;
	if (myExperience >= myRequiredExperience)
	{
		myRequiredExperience *= 3;
		myCanLevelUp = true;
	}
}
