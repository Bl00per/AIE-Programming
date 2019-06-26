#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_graph = new graph<vector_2>();

	// Recursive magic to build graph
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			m_graph->create_node({ 
				(j + 1.0f) * spacing, 
				(i + 1.0f) * spacing });
		}
	}

	// Horizontals
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width - 1; j++)
		{
			m_graph->create_edge(
				m_graph->m_nodes[i * width + j],
				m_graph->m_nodes[i * width + j + 1]);
		}
	}

	// Verticals
	for (int i = 0; i < height - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			m_graph->create_edge(
				m_graph->m_nodes[i * width + j],
				m_graph->m_nodes[(i + 1) * width + j]);
		}
	}

	m_timer = 0;

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	m_font = nullptr;
	delete m_2dRenderer;
	m_2dRenderer = nullptr;
	delete m_graph;
	m_graph = nullptr;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	int mouse_x = 0;
	int mouse_y = 0;
	input->getMouseXY(&mouse_x, &mouse_y);

	// Terrible order N lookup
	float shortest_distance = FLT_MAX;
	node<vector_2>* closest_node = nullptr;

	if (input->wasMouseButtonPressed(0))
	{
		vector_2 mouse_position{ float(mouse_x), float(mouse_y) };
		for (auto& a_node : m_graph->m_nodes)
		{
			float distance = (mouse_position - a_node->m_data).magnitude();
			if (distance < shortest_distance)
			{
				shortest_distance = distance;
				closest_node = a_node;
			}
		}

		m_selection_queue.push(closest_node);
		if (m_selection_queue.size() > 2)
		{
			m_selection_queue.pop();
		}

		if (m_selection_queue.size() == 2)
		{
			m_graph->calculate_path_a_star(
				m_selection_queue.front(),
				m_selection_queue.back());

			//m_graph->calculate_path_dijkstra(
			//	m_selection_queue.front(), 
			//	m_selection_queue.back());
		}
	}

// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//// Draw the graph
	//for (auto& a_edge : m_graph->m_edges)
	//{
	//	node<vector_2>* A = a_edge->m_nodes[0];
	//	node<vector_2>* B = a_edge->m_nodes[1];
	//	m_2dRenderer->drawLine(A->m_data.x, A->m_data.y, B->m_data.x, B->m_data.y, 2.0f);
	//}

	//// Edges
	//m_2dRenderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);
	//for (int i = 0; i < int(m_graph->m_path.size()) - 1; i++)
	//{
	//	node<vector_2>* A = m_graph->m_path[i];
	//	node<vector_2>* B = m_graph->m_path[i + 1];
	//	m_2dRenderer->drawLine(A->m_data.x, A->m_data.y, B->m_data.x, B->m_data.y, 2.0f);

	//}

	//// Draw nodes
	//m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	//for (auto& a_node : m_graph->m_nodes)
	//{
	//	m_2dRenderer->drawCircle(a_node->m_data.x, a_node->m_data.y, 8.0f);
	//}

	//// Render selected
	//m_2dRenderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);

	//if (m_selection_queue.size() > 0)
	//	m_2dRenderer->drawCircle(m_selection_queue.front()->m_data.x, m_selection_queue.front()->m_data.y, 12.0f);
	//if (m_selection_queue.size() > 1)
	//	m_2dRenderer->drawCircle(m_selection_queue.back()->m_data.x, m_selection_queue.back()->m_data.y, 12.0f);

	m_2dRenderer->setRenderColour(0.0f, 1.0f, 1.0f, 1.0f);



	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	// output some text, uses the last used colour
	char nodes[32];
	sprintf_s(nodes, 32, "Nodes: %i", m_selection_queue.size());
	m_2dRenderer->drawText(m_font, nodes, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}