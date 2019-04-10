#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() 
{
	
}

Application2D::~Application2D() 
{
	delete node<int>::g_systemFont;
}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_bullet = new aie::Texture("./textures/nuke.png");
	node<int>::g_systemFont = new aie::Font("./font/consolas.ttf", 32);

	m_font = new aie::Font("./font/consolas_bold.ttf", 32);
	
	m_timer = 0;
	sprite_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete node<int>::g_systemFont;
	node<int>::g_systemFont = nullptr;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	sprite_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;

	// Buff Piranha Plant
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		objectPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		objectPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		objectPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		objectPosX += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT_CONTROL))
		objectRotation -= 50.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
		objectRotation += 50.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_6))
		objectRotation += 3000.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_5))
		objectRotation += 2000.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_4))
		objectRotation += 1000.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_3))
		objectRotation += 300.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_2))
		objectRotation += 150.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_1))
		objectRotation += 50.0f * deltaTime;
		
	if (input->isKeyDown(aie::INPUT_KEY_KP_0))
		objectRotation -= 10.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_KP_DECIMAL))
		objectRotation += 1000.0f * deltaTime;

	m_2dRenderer->setCameraPos(objectPosX - 640.0f, objectPosY - 360.0f);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	if (sprite_timer >= 0.05f) {
		sprite_timer = 0.0f;

		across_sprite++;
		if (across_sprite == 10) {
			across_sprite = 0;
			down_sprite++;
			if (down_sprite == 6) {
				down_sprite = 0;
			}
		}
	}



	// demonstrate animation			Across				Down	Where across/Where down
	m_2dRenderer->setUVRect((float)across_sprite / 10.0f, (float)down_sprite / 6.0f, 1.0f / 10.0f, 1.0/6.0f);
	m_2dRenderer->drawSprite(m_fire, 640, 270, 500, 200, 0, 0.8f);


	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_shipTexture, shipPosX, shipPosY, 0, 0, m_timer, 0.9);

	// additional stuff
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_background, 640, 360, 1280, 720, 0, 1.0);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_preston, 640, 360, 1280, 720, 0, 0.95f);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_toddchan, tan(m_timer * 3) * 200 + 640, cos(m_timer * 3) * 200 + 360, 640, 360, 0, 0.8);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_buffboi, objectPosX, objectPosY, 365, 365, objectRotation, 0.8);
	

	m_binary_tree.draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Buy my game.", tan(m_timer * 3) * 200 + 565, cos(m_timer * 3) * 200 + 500);

	// done drawing sprites
	m_2dRenderer->end();
}

void Application2D::shooting(float deltaTime)
{
	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_2dRenderer->begin();

	// Shooting
	if (input->isKeyUp(aie::INPUT_KEY_SPACE))
	{
		if (input->wasKeyPressed(aie::INPUT_KEY_LEFT))
		{
			m_2dRenderer->setUVRect(0, 0, 1, 1);
			m_2dRenderer->drawSprite(m_bullet, bulletPosX, objectPosY, 0, 0, 360.0f, 0.9f);

			bulletPosX -= 2000.0f * deltaTime;
		}
		if (input->wasKeyPressed(aie::INPUT_KEY_RIGHT))
		{
			m_2dRenderer->setUVRect(0, 0, 1, 1);
			m_2dRenderer->drawSprite(m_bullet, bulletPosX, objectPosY, 0, 0, 0, 0.9f);

			bulletPosX += 2000.0f * deltaTime;
		}
	}
}