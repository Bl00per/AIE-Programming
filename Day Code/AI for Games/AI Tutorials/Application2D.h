#pragma once

#include "Application.h"
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	aie::Texture* m_playerTexture;
	aie::Texture* m_enemyTexture;

	Agent* m_player;

	Agent* m_enemy;


	float m_timer;
};