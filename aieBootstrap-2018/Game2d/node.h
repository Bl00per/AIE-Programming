#pragma once
#include "Renderer2D.h"

template<typename T>
class node
{
public:
	static aie::Font* g_systemFont; // Static declaration - All nodes share this

	// Construction of node with valid data
	node(const T& a_data) : m_data(a_data)
	{}

	void draw(aie::Renderer2D* renderer, int x, int y, bool selected = false)
	{
		static char buffer[10];
		sprintf(buffer, "%d", m_data);
		renderer->setRenderColour(1, 1, 0);
		renderer->drawCircle(x, y, 30);
		if (selected == true)
			renderer->setRenderColour(.5, .5, 0);
		else
			renderer->setRenderColour(0, 0, 0);
		renderer->drawCircle(x, y, 28);
		renderer->setRenderColour(1, 1, 1);
		renderer->drawText(g_systemFont, buffer, x - 12, y - 10);
	}

	~node() {}

	// Data member for this node
	T m_data;

	// Graph linkage
	node<T>* m_parent = nullptr;
	node<T>* m_left = nullptr;
	node<T>* m_right = nullptr;


};

aie::Font* node<int>::g_systemFont = nullptr; // Static initialization

