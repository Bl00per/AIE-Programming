#include "Player.h"
#include "Input.h"
#include "Font.h"
#include "Texture.h"


Player::Player()
{
	m_shipTexture = new aie::Texture("../bin/textures/ship.png");
	m_ammo = new aie::Texture("../bin/textures/ammo.png");
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
}

Player::~Player()
{
}

void Player::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_UP) && input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		positionY += 450.0f * deltaTime;
		positionX += 450.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_UP) && input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		positionY += 450.0f * deltaTime;
		positionX -= 450.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_DOWN) && input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		positionY -= 400.0f * deltaTime;
		positionX += 400.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_DOWN) && input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		positionY -= 400.0f * deltaTime;
		positionX -= 400.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_UP)) {
		positionY += 500.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_DOWN)) {
		positionY -= 300.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		positionX -= 500.0f * deltaTime;
	}

	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		positionX += 500.0f * deltaTime;
	}

	// Screen Boundry
	if (positionX <= 0)
		positionX = 0;
	else if (positionX >= screenWidth)
		positionX = screenWidth;
	
	if (positionY <= 0)
		positionY = 0;
	else if (positionY >= screenHeight)
		positionY = screenHeight;


	// Fire bullet
	for (int i = 0; i < bulletList.size(); i++) {
		bulletList[i].update(deltaTime);
	}


	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && ammo_count > 0) {
		// Sends the values to the constructor
		bulletList.push_back(Bullet(positionX, positionY, rotation, direction));
		ammo_count--;
	}
	
	// If user is reloading, make the animation reverse until it reaches the first sprite
	if (is_reloading) {
		down_sprite--;
		if (down_sprite == 0)
			is_reloading = false;
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_R) && down_sprite != 0)
	{
		ammo_count = 10;
		is_reloading = true;
	}
}

void Player::draw(aie::Renderer2D*	m_2dRenderer) {
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && ammo_count >= 0) {
		if (ammo_count > 0) {
			down_sprite++;
		}
		else
		{
			down_sprite = 10;
		}
	}
	
	if (ammo_count == 0)
		m_2dRenderer->drawText(m_font, "Press R to reload!", positionX - 150, positionY + 58);

	// demonstrate animation			Across				Down	Where across/Where down
	m_2dRenderer->setUVRect((float)across_sprite / 1.0f, (float)down_sprite / 11.0f, 1.0f / 1.0f, 1.0 / 11.0f);
	m_2dRenderer->drawSprite(m_ammo, 1026, 45, 500, 78, 0, 1);


	// Position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_shipTexture, positionX, positionY, 0, 0, rotation, 0.9);

	m_2dRenderer->drawCircle(positionX, positionY, m_radius, 1);

	// Draw bullet
	for (int i = 0; i < bulletList.size(); i++) {
		bulletList[i].draw(m_2dRenderer);
	}
}

float Player::getPlayerPosX()
{
	return positionX;
}

float Player::getPlayerPosY()
{
	return positionY;
}

void Player::setShipRadius(float a_radius)
{
	m_radius = a_radius;
}


float Player::getShipRadius() const
{
	return m_radius;
}

