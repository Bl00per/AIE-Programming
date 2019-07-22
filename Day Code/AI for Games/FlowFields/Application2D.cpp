#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <list>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	// generate random field
	// (could instead generate from an image)
	randomiseLevel(m_obstaclePercentage);

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	for (auto& go : m_gameObjects) {
		// update game object

	}

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// randomise level
	if (input->wasKeyPressed(aie::INPUT_KEY_R))
		randomiseLevel(m_obstaclePercentage);

	// pick goal cell
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT)) {

		// find cell under mouse
		int x = 0, y = 0;
		input->getMouseXY(&x, &y);

		// convert screen space to "grid space"
		x /= FLOWFIELD_CELLSIZE;
		y /= FLOWFIELD_CELLSIZE;

		if (m_integrationField[y][x] != eFlowFieldCosts::IMPASSABLE) {

			performIntergration(x, y);
			generateFlowfield();
		}
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw game objects
	for (auto& go : m_gameObjects) {
		m_2dRenderer->drawBox(go.position.x, go.position.y, 8, 8);
	}

	// draw obstacles
	for (int r = 0; r < FLOWFIELD_ROWS; ++r) {
		for (int c = 0; c < FLOWFIELD_COLS; ++c) {
			if (m_costField[r][c] == eFlowFieldCosts::IMPASSABLE) {
				m_2dRenderer->setRenderColour(1, 0, 0);
				m_2dRenderer->drawBox(FLOWFIELD_CELLSIZE * 0.5f + c * FLOWFIELD_CELLSIZE,
					FLOWFIELD_CELLSIZE * 0.5f + r * FLOWFIELD_CELLSIZE,
					FLOWFIELD_CELLSIZE, FLOWFIELD_CELLSIZE);
			}
			else {
				m_2dRenderer->setRenderColour(1, 1, 0);
				m_2dRenderer->drawLine(FLOWFIELD_CELLSIZE * 0.5f + c * FLOWFIELD_CELLSIZE,
					FLOWFIELD_CELLSIZE * 0.5f + r * FLOWFIELD_CELLSIZE,
					FLOWFIELD_CELLSIZE * 0.5f + c * FLOWFIELD_CELLSIZE + m_flowField[r][c].x * 16,
					FLOWFIELD_CELLSIZE * 0.5f + r * FLOWFIELD_CELLSIZE + m_flowField[r][c].y * 16);
			}
		}
	}

	// done drawing sprites
	m_2dRenderer->end();
}

void Application2D::randomiseLevel(float obstaclePercentage) {

	// randomly place obstacles
	for (int r = 0; r < FLOWFIELD_ROWS; ++r) {
		for (int c = 0; c < FLOWFIELD_COLS; ++c) {

			// a really bad random percentage calculator
			if (rand() % 100 < int(100 * obstaclePercentage))
				m_costField[r][c] = eFlowFieldCosts::IMPASSABLE;
			else
				m_costField[r][c] = eFlowFieldCosts::WALKABLE;

			m_integrationField[r][c] = 0;
			m_flowField[r][c].x = 0;
			m_flowField[r][c].y = 0;
		}
	}

	// safely place game objects
	for (auto& go : m_gameObjects) {
		int index = 0;
		do {
			index = rand() % (FLOWFIELD_ROWS * FLOWFIELD_COLS);
		} while (m_costField[index / FLOWFIELD_COLS][index % FLOWFIELD_COLS] == eFlowFieldCosts::IMPASSABLE);

		go.position.x = FLOWFIELD_CELLSIZE * 0.5f + (index % FLOWFIELD_COLS) * FLOWFIELD_CELLSIZE;
		go.position.y = FLOWFIELD_CELLSIZE * 0.5f + (index / FLOWFIELD_COLS) * FLOWFIELD_CELLSIZE;
	}
}

void Application2D::getCellNeighbours(int x, int y, std::vector<int>& neighbours) {

	neighbours.clear();

	// 8 potential neighbours
	// TIP: this could be improved by ignoring diagonal 
	// neighbours that should be blocked by impassable cells
	for (int r = -1; r <= 1; ++r) {
		for (int c = -1; c <= 1; ++c) {
			if (x == c &&
				y == r)
				continue;

			if ((x + c) >= 0 &&
				(x + c) <= (FLOWFIELD_COLS - 1) &&
				(y + r) >= 0 &&
				(y + r) <= (FLOWFIELD_ROWS - 1) &&
				m_costField[y + r][x + c] != eFlowFieldCosts::IMPASSABLE) {
				neighbours.push_back(x + c);
				neighbours.push_back(y + r);
			}
		}
	}
}

void Application2D::performIntergration(int goalX, int goalY) {
	// perform a dijkstra's search towards goal cell, 
	// starting from goal cell spreading outwards

	// Reset integration field
	for (int r = 0; r < FLOWFIELD_ROWS; r++)
		for (int c = 0; c < FLOWFIELD_COLS; c++)
			m_integrationField[r][c] = FLT_MAX;

	// Push goal into open list
	std::list<std::pair<int, int>> openList;
	openList.push_front({ goalX, goalY });

	m_integrationField[goalY][goalX] = 0;

	std::vector<int> neighbours(16);

	// Do search
	while (!openList.empty())
	{
		auto current = openList.front();
		openList.pop_front();

		// Get neighbours of popped cell and iterate over them
		getCellNeighbours(current.first, current.second, neighbours);

		unsigned int neighbourCount = neighbours.size();

		for (unsigned int i = 0; i < neighbourCount; i += 2)
		{
			// Calculate new trvael cost
			// current is a std::pair<int,int> representing x and y
			float cost = m_integrationField[current.second][current.first] + m_costField[neighbourCount[i + 1]][neighbours[i]];
		}
	}
}

void Application2D::generateFlowfield() {
	// for each grid cell, sample neighbour costs and 
	// setup flow direction to lowest cost neighbour

}