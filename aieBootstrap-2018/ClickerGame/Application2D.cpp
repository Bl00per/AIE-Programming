#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() 
{
	
}

Application2D::~Application2D() 
{

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas_bold.ttf", 32);
	m_button = new Button("Duck", 640, 360, 120, 50);
	
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_button;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	textMove += deltaTime;
	textAlpha -= deltaTime;


	if (m_button->update())
	{
		std::cout << "Button clicked" << std::endl;
	}

	// input example
	aie::Input* input = aie::Input::getInstance();




	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_button->draw(m_2dRenderer);

	if (m_button->update())
	{
		textAlpha = 1;
		textMove = 0;
		m_2dRenderer->setUVRect(0, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "+1 Ducks", m_button->getPosX(), m_button->getPosY() + textMove);
	}


	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}