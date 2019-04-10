#include "Game2dApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include"../dependencies/imgui/imgui.h"

aie::Font* g_systemFont = nullptr;

Game2dApp::Game2dApp() {

}

Game2dApp::~Game2dApp() {
	delete node<int>::g_systemFont;
}

bool Game2dApp::startup() {
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	node<int>::g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);
	return true;
}

void Game2dApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete node<int>::g_systemFont;
	node<int>::g_systemFont = nullptr;
}

void Game2dApp::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();

	static int value = 0; 
	ImGui::InputInt("Value", &value); 

	if (ImGui::Button("Insert", ImVec2(50, 0))) 
	{ 
		m_binary_tree.insert(value); 
		m_selectedNode = m_binary_tree.find(value); 
	}

	if (ImGui::Button("Remove", ImVec2(50, 0))) 
	{ 
		m_binary_tree.remove(value); 
	}
	if (ImGui::Button("Find", ImVec2(50, 0))) 
	{ 
		m_selectedNode = m_binary_tree.find(value); 
	}
	// exit the application
	if(input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();


	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;

	m_2dRenderer->setCameraPos(camPosX, camPosY);
}

void Game2dApp::draw() {
	// wipe the screen to the background colour
	clearScreen();
	
	// begin drawing sprites
	m_2dRenderer->begin();
	
	// draw your stuff here!
	m_binary_tree.draw(m_2dRenderer, m_selectedNode);

	// output some text
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	
	// done drawing sprites
	m_2dRenderer->end();
}