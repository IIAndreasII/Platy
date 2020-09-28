#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

constexpr int DEFAULT_TILE_SIZE = 32;


class Tile : public sf::Drawable
{
public:
	Tile(sf::Vector2i aPos);
	~Tile() override;

	struct RevealInfo
	{
		RevealInfo(const bool& mine, const uint8_t& aCloseMineCount) :
			isMine(mine),
			closeMineCount(aCloseMineCount)
		{
		}

		~RevealInfo() = default;
		const bool isMine;
		const uint8_t closeMineCount;
	};

	enum class EState
	{
		Checked,
		Unchecked,
		Flagged,
		Questioned,
	};

	RevealInfo Reveal();

	void AddCloseMine();

	void ToggleState();

	void Explode();

	/////////////////
	// SET
	/////////////////
	void SetState(EState aNewState);

	/// <summary>
	/// Use only during minefield creation!
	/// </summary>
	void PlaceMine();

	/////////////////
	// GET
	/////////////////
	const EState& GetState() const;

	const uint8_t& GetCloseMineCount() const;

	const sf::Vector2i& GetPosition() const;

	const bool& HasMine() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

	sf::Sprite mySprite;

	sf::Vector2i myPos;

	uint8_t myCloseMineCount = 0;

	bool myHasMine;

	EState myState = EState::Unchecked;
};

#endif
