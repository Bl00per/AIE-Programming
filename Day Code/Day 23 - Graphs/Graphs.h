#pragma once
#include <vector>

#include "node.h"
#include "edge.h"

template<typename T>
class Graphs
{
public:
	Graphs<T>() {}
	~Graphs()
	{
		for (auto node : m_nodes)
		{
			delete node;
		}

		for (auto edge : m_edge)
		{
			delete edge;
		}
	}

	node<T>* create_node(const T& a_data)
	{
		node<T>* new_node = new node<T>(a_data);
		m_nodes.push_back(new_node);
		return new_node;
	}
	edge<T>* create_edge(node<T>* a_node_A, node<T>* a_node_B)
	{
		edge<T>* new_edge = new edge<T>(a_node_A, a_node_B);
		m_edge.push_back(new_edge);
		return new_edge;
	}

	void remove_node(node<T>* a_nodes)
	{
		for (auto edge : a_node->m_edge)
		{
			remove_edge(edge);
		}
		a_node->disconnect();
		auto iter = std::find(m_nodes.begin(), m_nodes.end(), a_nodes);
		delete (*iter);
		m_edge.erase(iter);
	}

	void remove_edge(edge<T>* a_edge)
	{
		a_edge->m_nodes[0]->remove_edge(a_edge);
		a_edge->m_nodes[1]->remove_edge(a_edge);

		auto iter = std::find(m_edge.begin(), m_edge.end(), a_edge);
		delete (*iter);
		m_edge.erase(iter);
	}

private:
	std::vector<node<T>*> m_nodes;
	std::vector<edge<T>*> m_edge;
};