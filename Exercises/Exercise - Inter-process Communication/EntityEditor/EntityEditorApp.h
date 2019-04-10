#pragma once

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

class EntityEditorApp : public aie::Application {
public:

	EntityEditorApp();

	virtual ~EntityEditorApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	Entity m_entities[ENTITY_COUNT];

	HANDLE sizeHandle;
	HANDLE fileHandle;
};