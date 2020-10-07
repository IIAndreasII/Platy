#ifndef GRAPHICS_ENUM_H
#define GRAPHICS_ENUM_H

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			enum class EParticleEmitterType
			{
				FOUNTAIN,
				EXPLOSION,
				FOUNTAIN_BURST,
				SHOWER,
				CLOUD
			};

			enum class EOrientation : int
			{
				DOWN = 180,
				UP = 360,
				RIGHT = 90,
				LEFT = 270
			};

			enum class EParticleShape
			{
				RECTANGLE,
				CIRCLE
			};
		}
	}
}
#endif
