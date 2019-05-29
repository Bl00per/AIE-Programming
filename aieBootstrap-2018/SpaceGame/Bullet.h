#pragma once
#include "Renderer2D.h"

class Bullet
{
public:
	Bullet() = delete;
	Bullet(float m_positionX, float m_positionY, float m_rotation, int m_direction);
	~Bullet();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture* m_bullet;
	float bulletPosX = 0;
	float bulletPosY = 0;
	float bulletRotation = 0; //radians
	/* 0 for up, 1 for up/right, 2 for right, 
	3 for down/right, 4 for down, 5 for down/left, 
	6 for left, 7 for up/left */
	int bulletDirection = 0;
	float bulletSpeed = 2500.0f;
	float PI = 3.14159;

};