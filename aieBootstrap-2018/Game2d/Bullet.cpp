#include "Bullet.h"
#include "Input.h"
#include "Texture.h"

//Bullet::Bullet(int direction) {
//	bulletDirection = direction;
//}


Bullet::Bullet(float m_positionX, float m_positionY, float m_rotation, int m_direction)
{
	m_bullet = new aie::Texture("../bin/textures/nuke.png");
	bulletPosX = m_positionX;
	bulletPosY = m_positionY;
	bulletRotation = m_rotation;
	bulletDirection = m_direction;
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();

	// Fire the bullet in the direction that the ship is facing
	switch(bulletDirection) {
	case 0: // Up
		bulletPosY += bulletSpeed * deltaTime;
		break;
	case 1: // Up/Right
		bulletPosX += bulletSpeed * deltaTime;
		bulletPosY += bulletSpeed * deltaTime;
		break;
	case 2: // Right
		bulletPosX += bulletSpeed * deltaTime;
		break;
	case 3: // Down/Right
		bulletPosX += bulletSpeed * deltaTime;
		bulletPosY -= bulletSpeed * deltaTime;
		break;
	case 4: // Down
		bulletPosY -= bulletSpeed * deltaTime;
		break;
	case 5: // Down/Left
		bulletPosX -= bulletSpeed * deltaTime;
		bulletPosY -= bulletSpeed * deltaTime;
		break;
	case 6: // Left
		bulletPosX -= bulletSpeed * deltaTime;
		break;
	case 7: // Up/Left
		bulletPosX -= bulletSpeed * deltaTime;
		bulletPosY += bulletSpeed * deltaTime;
	default:
		break;
	}
	
}

void Bullet::draw(aie::Renderer2D*	m_2dRenderer) {
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_bullet, bulletPosX, bulletPosY, 29, 90, bulletRotation, 1);
}