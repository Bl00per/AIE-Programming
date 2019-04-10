#pragma once

#include <vector>
#include <Windows.h>
#include "Application.h"
#include "Renderer2D.h"

struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	float r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityDisplayApp : public aie::Application {
public:

	EntityDisplayApp();
	virtual ~EntityDisplayApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	// an array of an unknown number of entities
	std::vector<Entity> m_entities;

	HANDLE sizeHandle;
	HANDLE fileHandle;
};