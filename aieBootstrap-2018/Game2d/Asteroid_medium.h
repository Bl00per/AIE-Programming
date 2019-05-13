#include "Renderer2D.h"
#include "Bullet.h"
#include <vector>

class Asteroid_medium
{
public:
	Asteroid_medium();
	~Asteroid_medium();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture*		m_asteroid;
	float m_timer = 0;
	float positionX = 900;
	float positionY = 500;

	//degrees
	float rotation_med = 0;

	// 0 = right, 1 = left
	int asteroidRotation_med = 0;

	int screenWidth = 1280;
	int screenHeight = 720;
};

