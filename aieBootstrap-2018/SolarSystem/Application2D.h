#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "matrix_3x3.h"

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
	aie::Texture* m_toddchan;
	matrix_3x3 todd_world_transform;
	matrix_3x3 todd_local_transform;

	// Planet doom
	aie::Texture* m_PlanetDoom;
	matrix_3x3 doom_local_transform;
	matrix_3x3 doom_world_transform;
	float doom_rotation; // Object rotation rate in radians/second
	float doom_orbit;

	// Planet skyrim
	aie::Texture* m_PlanetSkyrim;
	matrix_3x3 skyrim_local_transform;
	matrix_3x3 skyrim_world_transform;
	float skyrim_rotation; // Object rotation rate in radians/second
	float skyrim_orbit;

	// Fallout4 planet
	aie::Texture* m_PlanetF4;
	matrix_3x3 fallout4_local_transform;
	matrix_3x3 fallout4_world_transform;
	float fallout4_rotation; // Object rotation rate in radians/second
	float fallout4_orbit; // Object orbit as an angle rate in radians/second

	// Fallout76 planet
	aie::Texture* m_PlanetF76;
	matrix_3x3 fallout76_local_transform;
	matrix_3x3 fallout76_world_transform;
	float fallout76_rotation; // Object rotation rate in radians/second
	float fallout76_orbit; // Object orbit as an angle rate in radians/second

	float m_timer;
};