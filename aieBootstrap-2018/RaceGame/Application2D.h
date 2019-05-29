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
	aie::Font*			m_font;

	// Race track
	aie::Texture* raceTrack;

	// Fallout4 planet
	aie::Texture* car_texture;
	game_object* playerCar;


	float m_timer;
};