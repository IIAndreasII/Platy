#ifndef ANIMATOR_2D_H
#define ANIMATOR_2D_H

#include "Spritesheet.h"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics/Drawable.hpp"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			constexpr float DEFAULT_ANIM_SCALE = 4;

			class Animator final : public sf::Drawable
			{
			public:
				explicit Animator(const SpriteSheet& aSpriteSheet, float aScale = DEFAULT_ANIM_SCALE,
				                  bool shouldLoop = true);
				~Animator() override;

				void Update(const float& someDeltaTime, const sf::Vector2f& aPosition);

				void SetAnim(const SpriteSheet& aSpriteSheet);

				void Flip();
				void SetFacingDirection(int aDir);
				void TogglePlaying();
				void ToggleLooping();

				const sf::Sprite& GetCurrentFrame() const;

				void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			private:

				SpriteSheet mySpriteSheet;
				sf::Sprite mySprite;

				bool myIsPlaying;
				bool myIsLooping;

				float myCurrentFrame;
				float myScale;
			};
		}
	}
}
#endif
