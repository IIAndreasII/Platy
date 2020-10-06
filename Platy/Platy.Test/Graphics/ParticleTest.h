#ifndef PARTICLE_TEST_H
#define PARTICLE_TEST_H

class ParticleEmitter;

class ParticleTest
{
public:
	ParticleTest();
	~ParticleTest() = default;

	void Update(const float& deltaTime);

private:

	float myExplosionTimer,
	      myExplosionInterval;
};

#endif
