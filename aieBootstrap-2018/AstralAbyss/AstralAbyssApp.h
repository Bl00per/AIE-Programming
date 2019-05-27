// Author: Garreth Cheffirs
// 2014 - Introduction to C++ Assignment 1
// Modified 2017 - Sam Cartwright
// Academy of Interactive Entertainment
// This code is provided by AIE for the purposes of completing in-class tutorials
// Excessive use of this code in assessments, or its use without the appropriate 
// attribution will be treated as plagiarism.

#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <list>

class Player;
class Ship;
class Bullet;
class Entity;

enum GameState
{
	SPLASH_SCREEN,
	MAIN_MENU,
	GAME_PLAY,
	PAUSE_MENU,
	GAME_OVER,
	SCORE_BOARD
};

class AstralAbyssApp : public aie::Application {
public:

	AstralAbyssApp();
	virtual ~AstralAbyssApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void resetGame();
	
	void updateSplashScreen(float deltaTime);
	void updateMainMenu(float deltaTime);
	void updateGamePlay(float deltaTime);
	void updatePauseMenu(float deltaTime);
	void updateGameOver(float deltaTime);
	void updateScoreBoard(float deltaTime);

	void drawSplashScreen(aie::Renderer2D* renderer);
	void drawMainMenu(aie::Renderer2D* renderer);
	void drawGamePlay(aie::Renderer2D* renderer);
	void drawPauseMenu(aie::Renderer2D* renderer);
	void drawGameOver(aie::Renderer2D* renderer);
	void drawScoreBoard(aie::Renderer2D* renderer);

protected:

	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;
	aie::Texture* m_title;

	Player* m_player;
	Entity* m_explosion;
	Entity* m_enemyExplosion;
	
	GameState m_gameState;
	float m_timer;
	float m_enemySpawnTimer;
	int m_menuSelection;

	std::list<Bullet*> m_bullets;
	std::list<Ship*> m_ships;

	unsigned int m_wave, m_waveEnemies, m_spawnedEnemies, m_waveEnemiesCap, m_waveSpawnIncrease;

	int m_highscore;
	bool m_bNewHighScore;
};