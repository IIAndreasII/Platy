#ifndef TC_H
#define TC_H

#include <vector>
#include "SFML/Graphics/Texture.hpp"

typedef sf::Texture* TexturePtr;

class TextureContainer
{
public:
	~TextureContainer();

	static void Init();

	static TexturePtr GetTextureAt(const unsigned index);

private:
	TextureContainer();

	static void LoadTextures();

	static std::vector<TexturePtr> myTexturePtrs;

};

#endif
