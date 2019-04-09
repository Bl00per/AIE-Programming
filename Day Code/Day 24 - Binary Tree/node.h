#pragma once

template<typename T>
class node
{
public:
	node(const T& a_data) : m_data(a_data)
	{}

	~node();

	// Data member for this node
	T m_data;

	// Graph linkage
	node<T>* m_parent = nullptr;
	node<T>* m_left = nullptr;
	node<T>* m_right = nullptr;


};

