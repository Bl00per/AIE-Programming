#pragma once
#pragma comment(lib, "Winmm.lib")

#include <Windows.h>
#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"
#include "AsteroidManager.h"


class Game2dApp : public aie::Application {
public:

	Game2dApp();
	virtual ~Game2dApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	

protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_ammo;

	Player *mainCharacter;
	Asteroid_small *asteroidSmall;
	Asteroid_medium *asteroidMedium;
	Asteroid_large *asteroidLarge;

	bool detect_collision(Player* a_object_1, Asteroid_large* a_object_2);
	bool collided;
};