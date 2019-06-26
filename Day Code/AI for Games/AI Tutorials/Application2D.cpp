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

	m_player = new Agent();
	m_player->SetPosition(vector_2(100.0f, 100.0f));
	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour);

	m_enemy = new Agent();
	m_enemy->SetPosition(vector_2(500.0f, 500.0f));
	m_seekBehaviour = new SeekBehaviour();
	m_seekBehaviour->SetTarget(m_player);
	m_enemy->AddBehaviour(m_seekBehaviour);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	m_font = nullptr;
	delete m_2dRenderer;
	m_2dRenderer = nullptr;
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

	m_2dRenderer->setRenderColour(0.0f, 0.0f, 1.0f);
	m_player->draw(m_2dRenderer);
	m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f);
	m_enemy->draw(m_2dRenderer);


	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "Nodes: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}