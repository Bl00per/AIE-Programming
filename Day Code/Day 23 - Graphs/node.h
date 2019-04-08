#pragma once
#include <vector>
#include "edge.h"

template<typename T>
class edge;

template<typename T>
class node
{
public:
	node<T>(const T& a_data) : m_data(a_data)
	{}
	~node() {}

	void add_edge(edge<T>* a_edge)
	{
		m_edge.push_back(a_edge);
	}

	void remove_edge(edge<T>* a_edge)
	{
		auto iter = std::find(m_edge.begin(), m_edges.end(), a_edges)
		m_edge.erase(iter);
	}

	void disconnect()
	{

	}

private:
	std::vector<edge<T>*> m_edge;

	T m_data;
};

