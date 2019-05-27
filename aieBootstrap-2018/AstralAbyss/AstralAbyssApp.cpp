// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#include "AstralAbyssApp.h"
#include "defines.h"
#include "Font.h"
#include "Input.h"
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Ship.h"
#include <Texture.h>
#include <string>

AstralAbyssApp::AstralAbyssApp() {

}

AstralAbyssApp::~AstralAbyssApp() {

}

bool AstralAbyssApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/ARCADE.TTF", 14);
	m_title = new aie::Texture("./textures/title.png");

	m_gameState = SPLASH_SCREEN;
	m_timer = 0;
	m_enemySpawnTimer = 0;
	m_menuSelection = 0;

	m_player = new Player();
	m_player->setPosition(glm::vec2(200, 120));

	m_explosion = new Entity("./textures/explosion_1.png", 2, 0.2f, false);
	m_explosion->setAlive(false);

	m_enemyExplosion = new Entity("./textures/explosion_2.png", 2, 0.2f, false);
	m_enemyExplosion->setAlive(false);

	m_wave = 1;
	m_waveSpawnIncrease = 10;
	m_waveEnemies = m_wave * m_waveSpawnIncrease;
	m_spawnedEnemies = 0;
	m_waveEnemiesCap = 200;

	m_highscore = 0;
	m_bNewHighScore = false;
	return true;
}

void AstralAbyssApp::shutdown() {
	
	delete m_player;
	delete m_explosion;
	delete m_enemyExplosion;
	delete m_title;

	delete m_font;
	delete m_2dRenderer;
}

void AstralAbyssApp::resetGame()
{
	for (std::list<Ship*>::iterator iter = m_ships.begin(); iter != m_ships.end(); iter++)
	{
		delete (*iter);
	}
	m_ships.clear();

	for (std::list<Bullet*>::iterator iter = m_bullets.begin(); iter != m_bullets.end(); iter++)
	{
		delete (*iter);
	}
	m_bullets.clear();
}

void AstralAbyssApp::update(float deltaTime) {

	switch (m_gameState)
	{
	case SPLASH_SCREEN:
		updateSplashScreen(deltaTime);
		break;
	case MAIN_MENU:
		updateMainMenu(deltaTime);
		break;
	case GAME_PLAY:
		updateGamePlay(deltaTime);
		break;
	case PAUSE_MENU:
		updatePauseMenu(deltaTime);
		break;
	case GAME_OVER:
		updateGameOver(deltaTime);
		break;
	case SCORE_BOARD:
		updateScoreBoard(deltaTime);
		break;
	default:
		break;
	}	
}

void AstralAbyssApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	switch (m_gameState)
	{
	case SPLASH_SCREEN:
		drawSplashScreen(m_2dRenderer);
		break;
	case MAIN_MENU:
		drawMainMenu(m_2dRenderer);
		break;
	case GAME_PLAY:
		drawGamePlay(m_2dRenderer);
		break;
	case PAUSE_MENU:
		drawPauseMenu(m_2dRenderer);
		break;
	case GAME_OVER:
		drawGameOver(m_2dRenderer);
		break;
	case SCORE_BOARD:
		drawScoreBoard(m_2dRenderer);
		break;
	default:
		break;
	}

	// done drawing sprites
	m_2dRenderer->end();
}

void AstralAbyssApp::updateSplashScreen(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// Auto skip splash
	m_timer += deltaTime;

	if (m_timer > SPLASH_DELAY || input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_gameState = MAIN_MENU;
		m_timer = 0;
	}
}

void AstralAbyssApp::updateMainMenu(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		switch (m_menuSelection)
		{
		case 0:		// embark
			m_player->reset();
			m_player->setPosition(glm::vec2(24.0f, 128.0f));
			m_gameState = GAME_PLAY;
			break;
		case 1:		// highscores
			m_gameState = SCORE_BOARD;
			break;
		case 2:		// quit
			quit();
			break;
		}
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN))
	{
		if (m_menuSelection < 2)
		{
			m_menuSelection++;
		}
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_UP))
	{
		if (m_menuSelection > 0)
		{
			m_menuSelection--;
		}
	}
}

void AstralAbyssApp::updateGamePlay(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	m_explosion->update(deltaTime);
	m_enemyExplosion->update(deltaTime);

	if (m_player->hasDied() == true)
	{
		m_player->update(deltaTime);
		m_explosion->setAlive(true);
		m_explosion->setPosition(m_player->getPosition());
		m_timer = 0;
	}

	if (m_player->isAlive() == false)
	{
		m_timer += deltaTime;
		if (m_timer > SCREEN_DELAY)
		{
			if (m_player->getScore() > m_highscore)
			{
				m_bNewHighScore = true;
			}
			
			m_gameState = GAME_OVER;
			m_timer = 0;
		}
		return;
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE)) {
		m_gameState = PAUSE_MENU;
	}

	// Player Update
	m_player->update(deltaTime);
			
	if (m_player->isShooting()) {
		switch (m_player->getUpgradeLevel())
		{
		default:
		case 1:
			m_bullets.push_back(new Bullet(m_player->getPosition(), PLAYER_LEVEL1, m_player->getUpgradeLevel(), glm::vec2(150, 0)));
			break;
		case 2:
			m_bullets.push_back(new Bullet(m_player->getPosition(), PLAYER_LEVEL2, m_player->getUpgradeLevel(), glm::vec2(250, 0)));
			break;
		case 3:
			m_bullets.push_back(new Bullet(m_player->getPosition(), PLAYER_LEVEL3, m_player->getUpgradeLevel(), glm::vec2(450, 0)));
			break;
		}
	}

	// Collisions
	for (std::list<Bullet*>::iterator iter = m_bullets.begin(); iter != m_bullets.end(); )
	{
		Bullet* bullet = *iter;

		bullet->update(deltaTime);
						
		// check bullet against player
		if (bullet->isEnemyBullet() && m_player->isColliding(bullet) )
		{
			m_player->damage(bullet->getDamage() - m_player->getUpgradeLevel() + 1);
			bullet->setAlive(false);
		}

		// check bullet against ships
		if (!bullet->isEnemyBullet())
		{
			for (std::list<Ship*>::iterator shipIter = m_ships.begin(); shipIter != m_ships.end(); shipIter++)
			{
				Ship *ship = *shipIter;

				if (!ship->isAlive())
					continue;

				if (ship->isColliding(bullet))
				{
					m_enemyExplosion->setAlive(true);
					m_enemyExplosion->setPosition(ship->getPosition());

					ship->damage(bullet->getDamage());
					m_player->addPoints(ship->getPoints());
					bullet->setAlive(false);
				}
			}
		}

		// if bullet died, remove destroy and remove from list
		if (bullet->isAlive() == false)
		{
			delete bullet;
			iter = m_bullets.erase(iter);
		}
		else
		{
			iter++;
		}
	}
		
	// Enemy Update
	for (std::list<Ship*>::iterator iter = m_ships.begin(); iter != m_ships.end(); )
	{
		Ship *ship = *iter;

		if (ship->isAlive())
		{
			ship->update(deltaTime);

			// Bullet Creation
			if (ship->isShooting()) {
				m_bullets.push_back(new Bullet(ship->getPosition(), ENEMY_BULLET, ship->getPower(), glm::vec2(-100, 0)));
			}

			if (ship->isColliding(m_player))
			{
				m_enemyExplosion->setAlive(true);
				m_enemyExplosion->setPosition(ship->getPosition());

				ship->setAlive(false);
					
				m_player->damage(ship->getPower() - m_player->getUpgradeLevel() + 1);
				m_player->addPoints(1);
			}
		}

		if (ship->isAlive() == false)
		{
			delete ship;
			iter = m_ships.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	//==========================================================================================
	// Wave System For Enemies
	//==========================================================================================

	if (m_spawnedEnemies < m_waveEnemies)
	{
		m_enemySpawnTimer += deltaTime;
		if (m_enemySpawnTimer > SPAWN_DELAY)
		{
			int yPos = MIN_Y_MOVE + (rand() % (MAX_Y_MOVE - MIN_Y_MOVE));

			m_ships.push_front(new Ship(glm::vec2(256, yPos), 10 * m_wave, 3));

			m_spawnedEnemies++;
			m_enemySpawnTimer = 0;
		}
	}
	else
	{
		if (m_ships.size() == 0) {
			m_enemySpawnTimer += deltaTime;
		}

		if (m_enemySpawnTimer > WAVE_DELAY)
		{
			m_spawnedEnemies = 0;
			m_wave++;

			m_player->upgradeShip();
				
			if (m_waveEnemies < m_waveEnemiesCap)
			{
				m_waveEnemies = m_wave * m_waveSpawnIncrease;
			}

			m_enemySpawnTimer = 0;
		}
	}
}

void AstralAbyssApp::updatePauseMenu(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (m_menuSelection > 1)
		m_menuSelection = 1;

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		switch (m_menuSelection)
		{
		case 0:		// continue
			m_menuSelection = 0;
			m_gameState = GAME_PLAY;
			break;
		case 1:		// quit
			m_menuSelection = 0;
			resetGame();
			m_gameState = MAIN_MENU;
			break;
		}
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_DOWN)) {
		if (m_menuSelection < 1) {
			m_menuSelection++;
		}
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_UP)) {
		if (m_menuSelection > 0) {
			m_menuSelection--;
		}
	}
}

void AstralAbyssApp::updateGameOver(float deltaTime)
{
	m_timer += deltaTime;

	if (m_timer > GAMEOVER_DELAY)
	{
		if (m_bNewHighScore) {
			m_highscore = m_player->getScore();
		}
		m_gameState = MAIN_MENU;
		m_timer = 0;

		resetGame();
	}
}

void AstralAbyssApp::updateScoreBoard(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_gameState = MAIN_MENU;
	}
}

void AstralAbyssApp::drawSplashScreen(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "ENCEL GAMES PRESENTS", 48, 216);
	renderer->drawText(m_font, "ASTRAL ABYSS", 80, 188);
	renderer->drawText(m_font, "SELECT/MOVE -- ARROW KEYS", 24, 152);
	renderer->drawText(m_font, "ACCEPT/SHOOT -- SPACEBAR", 16, 120);
	renderer->drawText(m_font, "PAUSE GAME -- ESCAPE KEY", 32, 88);
	renderer->drawText(m_font, "DESIGN &", 96, 48);
	renderer->drawText(m_font, "CODE BY ZYTE", 80, 32);
}

void AstralAbyssApp::drawMainMenu(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "EMBARK", 88, 104);
	renderer->drawText(m_font, "HI-SCORES", 88, 88);
	renderer->drawText(m_font, "QUIT", 88, 72);

	renderer->drawSprite(m_title, 120, 200);
	renderer->drawText(m_font, "@ 2014 ENCEL GAMES", 56, 16);

	int y = 104 - (m_menuSelection * 16);
	renderer->drawText(m_font, ">", 78, y);
}

void AstralAbyssApp::drawGamePlay(aie::Renderer2D* renderer)
{
	m_player->draw(renderer);
	for (std::list<Ship*>::iterator shipIter = m_ships.begin(); shipIter != m_ships.end(); shipIter++) {
		(*shipIter)->draw(renderer);
	}
	for (std::list<Bullet*>::iterator iter = m_bullets.begin(); iter != m_bullets.end(); iter++) {
		(*iter)->draw(renderer);
	}
	m_explosion->draw(renderer);
	m_enemyExplosion->draw(renderer);
	

	//==========================================================================================
	// HUD
	//==========================================================================================
	
	renderer->setRenderColour(1, 1, 1, 1);

	static char buffer[50];

	// Draw headings
	renderer->drawText(m_font, "SCORE", 8, 228);
	renderer->drawText(m_font, "HI-SCORE", 96, 228);
	renderer->drawText(m_font, "WAVE", 216, 228);
	renderer->drawText(m_font, "SHIP INTEGRITY", 8, 12);
	renderer->drawText(m_font, "UPGRADE LVL", 160, 12);

	// Update values
	if (m_player != nullptr)
	{
		sprintf(buffer, "%.6d", m_player->getScore());
		renderer->drawText(m_font, buffer, 8, 220);

		int highscore = 0;
		sprintf(buffer, "%.6d", highscore);
		renderer->drawText(m_font, buffer, 104, 220);

		sprintf(buffer, "%d", m_wave);
		renderer->drawText(m_font, buffer, 224, 220);
		
		std::string hudIntegrity = "-";
		for (int i = 0; i < m_player->getHealth(); i++)
		{
			hudIntegrity += '#';
		}
		while (hudIntegrity.length() < 13)
		{
			hudIntegrity += ' ';
		}
		hudIntegrity += '-';
		renderer->drawText(m_font, hudIntegrity.c_str(), 8, 4);

		sprintf(buffer, "STAGE %d", m_player->getUpgradeLevel());
		renderer->drawText(m_font, buffer, 184, 4);
	}

}

void AstralAbyssApp::drawPauseMenu(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "-PAUSED-", 96, 144);
	renderer->drawText(m_font, "CONTINUE", 88, 120);
	renderer->drawText(m_font, "QUIT", 88, 104);
	
	int y = 120 - (m_menuSelection * 16);
	renderer->drawText(m_font, ">", 78, y);
}

void AstralAbyssApp::drawGameOver(aie::Renderer2D* renderer)
{
	//==========================================================================================
	// Game Over Screen
	//==========================================================================================

	// Heading
	renderer->drawText(m_font, "GAME OVER!", 88, 144);

	// Items
	if (m_bNewHighScore)
	{
		renderer->drawText(m_font, "NEW HI-SCORE", 80, 120);		
	}
}

void AstralAbyssApp::drawScoreBoard(aie::Renderer2D* renderer)
{
	static char buffer[10];

	renderer->drawText(m_font, "HI-SCORE", 56, 224);

	sprintf(buffer, "%.6d", m_highscore);
	renderer->drawText(m_font, buffer, 56, 192);

	renderer->drawText(m_font, "> BACK TO MENU", 72, 24);
}
