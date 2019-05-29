#include <ctime>
#include <iostream>
#include "Asteroid_small.h"
#include "Input.h"
#include "Texture.h"


Asteroid_small::Asteroid_small()
{
	m_asteroid = new aie::Texture("../bin/textures/rock_large.png"); // Medium sized
	srand(time(NULL));
	asteroidRotation_sml = rand() % 2 + 0;
	std::cout << asteroidRotation_sml << std::endl;
}

Asteroid_small::~Asteroid_small()
{
}

void Asteroid_small::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	m_timer += deltaTime;
	
	// Small asteroid roation
	if (asteroidRotation_sml == 0)
		rotation_sml += deltaTime;
	else if (asteroidRotation_sml == 1)
		rotation_sml -= deltaTime;









	// Cannot pass screen width
	//if (positionX <= 0)
	//	positionX = 0;
	//else if (positionX >= screenWidth)
	//	positionX = screenWidth;

	// Cannot pass screen height
	//if (positionY <= 0)
	//	positionY = 0;
	//else if (positionY >= screenHeight)
	//	positionY = screenHeight;
}

void Asteroid_small::draw(aie::Renderer2D* m_2dRenderer) {
	aie::Input* input = aie::Input::getInstance();

	// Position and draw the asteroids
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);

	// Small sized
	m_2dRenderer->drawSprite(m_asteroid, positionX, tan(m_timer * 1) * -100 + 720, 0, 0, rotation_sml, 0.8);
}