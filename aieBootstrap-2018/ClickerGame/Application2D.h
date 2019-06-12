#pragma once

#include <iostream>
#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"

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
	aie::Texture*		m_texture;
	aie::Font*			m_font;
	Button* m_button;


	float textAlpha;
	float textMove;

	float m_timer;
};