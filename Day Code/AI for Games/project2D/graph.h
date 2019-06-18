#pragma once
#include <vector>
#include <list>
#include <algorithm>


#include "node.h"
#include "edge.h"
#include "heap.h"

// Container class for managing all nodes/vertecies and edges
template<typename T>
class graph
{
public:
	graph<T>() {};
	~graph() 
	{
		for (auto node : m_nodes)
		{
			delete node;
		}

		for (auto edge : m_edges)
		{
			delete edge;
		}
	}

	// Create an edgeless node
	node<T>* create_node(const T& a_data)
	{
		node<T>* new_node = new node<T>(a_data);
		m_nodes.push_back(new_node);
		return new_node;
	}

	// Create an edge between two nodes. Edges report self to nodes.
	edge<T>* create_edge(node<T>* a_node_A, node<T>* a_node_B)
	{
		edge<T>* new_edge = new edge<T>(a_node_A, a_node_B);
		m_edges.push_back(new_edge);
		return new_edge;
	}

	// Safely remove node and connected edges
	void remove_node(node<T>* a_node)
	{
		while (a_node->get_edges().size() > 0)
		{
			auto edge = a_node->get_edges().at(0);
			remove_edge(edge);
		}

		auto iter = std::find(m_nodes.begin(), m_nodes.end(), a_node);
		delete (*iter);
		m_nodes.erase(iter);
	}

	// Remove the edge from the graph
	void remove_edge(edge<T>* a_edge)
	{
		a_edge->m_nodes[0]->remove_edge(a_edge);
		a_edge->m_nodes[1]->remove_edge(a_edge);

		auto iter = std::find(m_edges.begin(), m_edges.end(), a_edge);
		delete (*iter);
		m_edges.erase(iter);
	}

	std::vector<node<T>*> m_nodes;
	std::vector<edge<T>*> m_edges;

	std::vector<node<T>*> m_path;

	std::vector<node<T>*>& calculate_path_dijkstra(node<T>* a_start, node<T>* a_end)
	{
		// Initialise the starting node
		for (auto& a_node : m_nodes)
		{
			a_node->reset(); // NO!!!!
		}
		m_path.clear();

		// Validate the input
		if (!a_start || !a_end)
		{
			return m_path;
		}

		if (a_start == a_end)
		{
			m_path.push_back(a_start);
			return m_path;
		}

		std::list<node<T>*> open_list;		// Heap
		std::list<node<T>*> closed_list;	// Array of bools

		//Add startNode to openList
		open_list.push_back(a_start);

		node<T>* current_node;
		//While openList is not empty
		while (open_list.size())
		{
			current_node = open_list.front();
			open_list.pop_front();

			//Add currentNode to closedList
			closed_list.push_back(current_node);

			//For all connections c in currentNode
			for (auto& a_edge : current_node->get_edges())
			{
				node<T>* other_node = nullptr;
				if (a_edge->m_nodes[0] == current_node)
				{
					other_node = a_edge->m_nodes[1];
				}
				else
				{
					other_node = a_edge->m_nodes[0];
				}
				
				if ( std::find(std::begin(closed_list), std::end(closed_list), other_node) == closed_list.end())
				{
					int current_g_score = current_node->m_g_score + 1;
					//other_node->m_g_score = current_node.m_g_score + 1/*Edge weight*/;

					if (std::find(std::begin(open_list), std::end(open_list), other_node) == open_list.end())
					{
						//Let c.target.gScore = gScore
						other_node->m_g_score = current_g_score;
						other_node->m_previous = current_node;
						open_list.push_back(other_node);

					}
					else if (current_g_score < other_node->m_g_score)
					{
						other_node->m_g_score = current_g_score;
						other_node->m_previous = current_node;
					}
				}
			}
		}

		node<T>* end_node = a_end;
		m_path.push_back(end_node);
		while (end_node != a_start)
		{
			end_node = end_node->m_previous;
			m_path.push_back(end_node);
		}
		return m_path;
	}


	std::vector<node<T>*>& calculate_path_a_star(node<T>* a_start, node<T>* a_end)
	{
		// Initialise the starting node
		for (auto& a_node : m_nodes)
		{
			a_node->reset(); // NO!!!!
		}
		m_path.clear();

		// Validate the input
		if (!a_start || !a_end)
		{
			return m_path;
		}

		if (a_start == a_end)
		{
			m_path.push_back(a_start);
			return m_path;
		}

		heap open_heap;		// Heap
		std::list<node<T>*> closed_list;	// Array of bools

		//Add startNode to openList
		open_heap.add(a_start);

		node<T>* current_node;
		//While openList is not empty
		while (open_heap.size())
		{
			current_node = open_heap.pop();
			//open_list.pop();

			//Add currentNode to closedList
			closed_list.push_back(current_node);

			//For all connections c in currentNode
			for (auto& a_edge : current_node->get_edges())
			{
				node<T>* other_node = nullptr;
				if (a_edge->m_nodes[0] == current_node)
				{
					other_node = a_edge->m_nodes[1];
				}
				else
				{
					other_node = a_edge->m_nodes[0];
				}

				if (std::find(std::begin(closed_list), std::end(closed_list), other_node) == closed_list.end())
				{
					int current_heuristic = (int) (other_node->m_data - a_end->m_data).magnitude();
					int current_g_score = current_node->m_g_score + 1 + current_heuristic;

					//other_node->m_g_score = current_node.m_g_score + 1/*Edge weight*/;

					//if (std::find(std::begin(open_list), std::end(open_list), other_node) == open_list.end())
					if (open_heap.find(other_node) == -1)
					{
						//Let c.target.gScore = gScore
						other_node->m_f_score = current_g_score;
						other_node->m_g_score = current_heuristic;
						other_node->m_h_score = current_g_score + current_heuristic;

						other_node->m_previous = current_node;
						open_heap.add(other_node);

					}
					else if (current_g_score + current_heuristic < other_node->m_g_score)
					{
						other_node->m_g_score = current_g_score;
						other_node->m_previous = current_node;
					}
				}
			}
		}

		node<T>* end_node = a_end;
		m_path.push_back(end_node);
		while (end_node != a_start)
		{
			end_node = end_node->m_previous;
			m_path.push_back(end_node);
		}
		return m_path;
	}
};

