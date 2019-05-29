#pragma once

#include <iostream>
#include "Application.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "matrix_3x3.h"
#include "game_object.h"
#include "aligned_bounding_box.h"
#include "line.h"
#include "circle.h"

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
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	// Sun
	aie::Texture* toddchan_texture;
	game_object* toddchan;

	// Planet doom
	aie::Texture* planetDoom_texture;
	game_object* planetDoom;

	// Planet skyrim
	aie::Texture* planetSkyrim_texture;
	game_object* planetSkyrim;

	// Fallout4 planet
	aie::Texture* planetF4_texture;
	game_object* planetF4;

	// Fallout76 planet
	aie::Texture* planetF76_texture;
	game_object* planetF76;

	// Energy ball
	aie::Texture* energy_ball_texture;
	game_object* energy_ball;

	float m_timer;
};