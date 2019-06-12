#include "Button.h"



Button::Button(const char* buttonText, float x, float y, float width, float height)
{
	//Store the text that will appear on the button.
	strcpy_s(m_buttonText, 64, buttonText);
	
	//Load a font to use to display the text.
	m_font = new aie::Font("./font/consolas_bold.ttf", 28);
	
	//Store the button's position, width, and height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;
}

Button::~Button()
{
	delete m_font;
}

void Button::draw(aie::Renderer2D* renderer)
{
	// Drawing the box for the text to sit in
	renderer->setRenderColour(0.0f, 0.5f, 0.7f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	// Calculating the centred text position
	float textWidth = m_font->getStringWidth(m_buttonText);
	float textHeight = m_font->getStringHeight(m_buttonText);
	float centredPosX = m_posX - (textWidth * 0.5f);
	float centredPosY = m_posY - (textHeight * 0.5f);


	// Draw text on the bottom
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
}


bool Button::update()
{
	aie::Input* input = aie::Input::getInstance();

	// Get mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	// Calculate the 4 sides of the button
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);

	// Check if the mouse is inside the box made by the 4 sides.
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		// Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}

	return false;
}

float Button::getPosX()
{
	return m_posX;
}

float Button::getPosY()
{
	return m_posY;
}