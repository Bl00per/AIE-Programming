#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "binary_tree.h"
#include "node.h"


class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shooting(float deltaTime );

	float shipPosX = 640.0f;
	float shipPosY = 360.0f;

	float objectPosX = 640.0f;
	float objectPosY = 360.0f;
	float objectRotation = 0.0f;

	float bulletPosX = objectPosX;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	binary_tree<int>		m_binary_tree;
	node<int>*			m_selectedNode;
};