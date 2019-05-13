#include "Renderer2D.h"
#include "Bullet.h"
#include <vector>

class Asteroid_small
{
public:
	Asteroid_small();

	~Asteroid_small();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture*		m_asteroid;
	float m_timer = 0;
	float positionX = 650;
	float positionY = 500;

	//degrees
	float rotation_sml = 0; 
	float rotation_med = 0;
	float rotation_lrg = 0;

	// 0 = right, 1 = left
	int asteroidRotation_sml = 0; 
	int asteroidRotation_med = 0; 
	int asteroidRotation_lrg = 0; 

	int screenWidth = 1280;
	int screenHeight = 720;
};

