#pragma once
#include <vector>
#include "edge.h"

template<typename T>
class edge;

template<typename T>
class node
{
public:

	//struct node {
	//	// User defined data attached to each node.
	//	// In this example we just store the node position.
	//	vector_2 position;

	//	float gScore;
	//	node* parent;

	//	std::vector<edge> connections;
	//};

	node<T>(const T& a_data) : m_data(a_data)
	{}
	~node() {}

	void add_edge(edge<T>* a_edge)
	{
		m_edges.push_back(a_edge);
	}

	void remove_edge(edge<T>* a_edge)
	{
		auto iter = std::find(m_edges.begin(), m_edgess.end(), a_edges)
		m_edges.erase(iter);
	}

	void disconnect()
	{

	}

	T m_data;
	std::vector<edge<T>*> m_edges;

	node<T>* m_previous = nullptr;
	int m_g_score = 0;

	void reset() 
	{
		m_previous = nullptr;
		m_g_score = 0;
	}
};

