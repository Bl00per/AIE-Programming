#include "Enemy.h"
#include "Input.h"
#include "Texture.h"


Enemy::Enemy()
{
	m_shipTexture2 = new aie::Texture("../bin/textures/ship2.png");
	m_ammo = new aie::Texture("../bin/textures/ammo.png");
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();

	if (positionX <= 0)
		positionX = 0;
	else if (positionX >= screenWidth)
		positionX = screenWidth;

	if (positionY <= 0)
		positionY = 0;
	else if (positionY >= screenHeight)
		positionY = screenHeight;

	bulletList.push_back(Bullet(positionX, positionY, rotation, direction));
}

void Enemy::draw(aie::Renderer2D*	m_2dRenderer) {
	aie::Input* input = aie::Input::getInstance();

	// Position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_shipTexture2, positionX, positionY, 0, 0, rotation, 0.9);
}