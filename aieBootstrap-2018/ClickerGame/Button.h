#pragma once

#include "Renderer2D.h"
#include "Font.h"
#include "Input.h"
#include <string>

class Button
{
public:
	Button(const char* buttonText, float x, float y, float width, float height);
	~Button();

	void draw(aie::Renderer2D* renderer);
	bool update();

	float getPosX();
	float getPosY();


private:
	//Font and text for the button.
	aie::Font* m_font;
	char m_buttonText[64];

	//Button's position, width, and height.
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
};

