#include "Game2dApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <ctime>

Game2dApp::Game2dApp() {

}

Game2dApp::~Game2dApp() {

}

bool Game2dApp::startup() {
	
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();

	mainCharacter = new Player();
	mainCharacter->setShipRadius(40.0f);

	asteroidSmall = new Asteroid_small();
	asteroidMedium = new Asteroid_medium();
	asteroidLarge = new Asteroid_large();

	// in ur main function write these two lines it should work
	mciSendString(L"open \"../bin/sounds/Awaken(Pillar Men Theme).mp3\" type mpegvideo alias backgroundmusic", NULL, 0, NULL);
	mciSendString(L"setaudio backgroundmusic volume to 200", NULL, 0, NULL);
	mciSendString(L"play backgroundmusic repeat", NULL, 0, NULL);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void Game2dApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Game2dApp::update(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();

	mainCharacter->update(deltaTime);

	asteroidSmall->update(deltaTime);
	asteroidMedium->update(deltaTime);
	asteroidLarge->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Game2dApp::draw() {
	aie::Input* input = aie::Input::getInstance();

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	mainCharacter->draw(m_2dRenderer);

	asteroidSmall->draw(m_2dRenderer);
	asteroidMedium->draw(m_2dRenderer);
	asteroidLarge->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 8, 10, 1);

	// done drawing sprites
	m_2dRenderer->end();
}

bool Game2dApp::detect_collision(Player* a_object_1, Asteroid_large* a_object_2)
{
	float distance =
		sqrt(((a_object_1->getPlayerPosX() - a_object_2->getAsteroidPosX()) *
		(a_object_1->getPlayerPosX() - a_object_2->getAsteroidPosX()) +
			(a_object_1->getPlayerPosY() - a_object_2->getAsteroidPosY()) *
			(a_object_1->getPlayerPosY() - a_object_2->getAsteroidPosY())));

	if (distance < a_object_1->getShipRadius() + a_object_2->getAsteroidRadius())
	{
		return true;
	}
	return false;
}


