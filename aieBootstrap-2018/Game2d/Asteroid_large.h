#include "Renderer2D.h"
#include "Bullet.h"
#include <vector>

class Asteroid_large
{
public:
	Asteroid_large();
	~Asteroid_large();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

	float getAsteroidPosX();
	float getAsteroidPosY();
	float getAsteroidRadius();

protected:
	aie::Texture*		m_asteroid;
	float m_timer = 0;
	float positionX = 330;
	float positionY = 500;
	float m_radius = 86.0f;

	//degrees
	float rotation_lrg = 0;

	// 0 = right, 1 = left
	int asteroidRotation_lrg = 0;

	int screenWidth = 1280;
	int screenHeight = 720;
};

