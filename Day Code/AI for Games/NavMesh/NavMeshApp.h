#pragma once

#include "Application.h"
#include "Renderer2D.h"

#include "NavMesh.h"

class NavMeshApp : public aie::Application {
public:

	NavMeshApp();
	virtual ~NavMeshApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	NavMesh*			m_navMesh;
};