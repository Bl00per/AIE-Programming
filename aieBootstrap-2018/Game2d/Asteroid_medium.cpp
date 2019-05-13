#include <ctime>
#include <iostream>
#include "Asteroid_medium.h"
#include "Input.h"
#include "Texture.h"


Asteroid_medium::Asteroid_medium()
{
	m_asteroid = new aie::Texture("../bin/textures/rock_large.png"); // Medium sized
	srand(time(NULL));
	asteroidRotation_med = rand() % 2 + 2;
	std::cout << asteroidRotation_med << std::endl;
}

Asteroid_medium::~Asteroid_medium()
{
}

void Asteroid_medium::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	m_timer += deltaTime;

	// Large asteroid roation
	if (asteroidRotation_med == 2)
		rotation_med += deltaTime;
	else if (asteroidRotation_med == 3)
		rotation_med -= deltaTime;

	







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

void Asteroid_medium::draw(aie::Renderer2D* m_2dRenderer) {
	aie::Input* input = aie::Input::getInstance();

	// Position and draw the asteroids
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);

	// Medium sized
	m_2dRenderer->drawSprite(m_asteroid, positionX, tan(m_timer * 2) * -100 + 720, 96, 104, rotation_med, 0.8);
}