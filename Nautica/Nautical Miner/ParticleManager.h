#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"

class ParticleEmitter;
typedef ParticleEmitter* ParticleEmitterPtr;


class ParticleManager
{
public:
	~ParticleManager();

	static void Init();

	static void Update(float& deltaTime);
	static void Draw(sf::RenderWindow& aWindow);
	static void AddEmitter(ParticleEmitterPtr anEmitter);

private:
	ParticleManager();

	static std::vector<ParticleEmitterPtr> myParticleEmitters;
};

#endif