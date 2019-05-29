#include <ctime>
#include <iostream>
#include "Asteroid_large.h"
#include "Input.h"
#include "Texture.h"


Asteroid_large::Asteroid_large()
{
	m_asteroid = new aie::Texture("../bin/textures/rock_large.png"); // Medium sized
	srand(time(NULL));
	asteroidRotation_lrg = rand() % 2 + 4;
	std::cout << asteroidRotation_lrg << std::endl;
}

Asteroid_large::~Asteroid_large()
{
}

void Asteroid_large::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	m_timer += deltaTime;

	// Large asteroid roation
	if (asteroidRotation_lrg == 4)
		rotation_lrg += deltaTime;
	else if (asteroidRotation_lrg == 5)
		rotation_lrg -= deltaTime;









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

void Asteroid_large::draw(aie::Renderer2D* m_2dRenderer) {
	aie::Input* input = aie::Input::getInstance();

	// Position and draw the asteroids
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);

	// Large sized
	m_2dRenderer->drawSprite(m_asteroid, positionX, tan(m_timer * 3) * -100 + 720, 192, 208, rotation_lrg, 0.8);
	m_2dRenderer->drawCircle(positionX, tan(m_timer * 3) * -100 + 720, m_radius, 0.7);
}

float Asteroid_large::getAsteroidPosX()
{
	return positionX;
}

float Asteroid_large::getAsteroidPosY()
{
	return positionY;
}

float Asteroid_large::getAsteroidRadius()
{
	return m_radius;
}