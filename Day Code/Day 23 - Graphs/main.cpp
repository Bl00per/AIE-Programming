#include <crtdbg.h>
#include <string>

#include "Graphs.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Graphs<std::string> m_graph; // Facebook

	m_graph.create_node("Will");
	m_graph.create_node("Alex");
	m_graph.create_node("Josh");
	m_graph.create_node("Jack");
	m_graph.create_node("Tristian");

	// Have to search all nodes on the graph class
	// Islands and friendship 



	/*node<std::string>* node_A = m_graph.create_node("Will");
	node<std::string>* node_B = m_graph.create_node("Alex");
	node<std::string>* node_C = m_graph.create_node("Josh");
	node<std::string>* node_D = m_graph.create_node("Jack");
	node<std::string>* node_E = m_graph.create_node("Tristian");

	m_graph.create_edge(node_A, node_B);
	m_graph.create_edge(node_C, node_D);
	m_graph.create_edge(node_D, node_E);
	auto e = m_graph.create_edge(node_C, node_A);

	m_graph.remove_edge(e);
	m_graph.remove_node(node_C);*/





	return 0;
}