#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_playerTexture = new aie::Texture("./textures/todd_chan.png");
	m_enemyTexture = new aie::Texture("./textures/fallout76.jpg");

	m_player = new Agent(m_playerTexture, 200.0f, 200.0f);
	m_player->AddBehaviour(new KeyboardBehaviour());
	m_player->m_maxSpeed = 80.0f;

	m_enemy = new Agent(m_enemyTexture, 400.0f, 100.0f);
	m_enemy->AddBehaviour(new SeekBehaviour(m_player));
	m_enemy->m_maxSpeed = 80.0f;

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	m_font = nullptr;
	delete m_2dRenderer;
	m_2dRenderer = nullptr;
	delete m_player;
	m_player = nullptr;
	delete m_enemy;
	m_enemy = nullptr;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime);
	m_enemy->update(deltaTime);

	int mouse_x = 0;
	int mouse_y = 0;
	input->getMouseXY(&mouse_x, &mouse_y);

// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_player->draw(m_2dRenderer);
	m_enemy->draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f);
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}