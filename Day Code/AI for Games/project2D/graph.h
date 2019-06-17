#pragma once
#include <vector>
#include <list>

#include "node.h"
#include "edge.h"

template<typename T>
class graph
{
public:
	graph<T>() {}
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

	void remove_node(node<T>* a_nodes)
	{
		for (auto edge : a_node->m_edges)
		{
			remove_edge(edge);
		}
		a_node->disconnect();
		auto iter = std::find(m_nodes.begin(), m_nodes.end(), a_nodes);
		delete (*iter);
		m_edges.erase(iter);
	}

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

	std::vector<node<T>*>& calculate_parth_dijkstra(node<T>* a_start, node<T>* a_end)
	{
		// Initialise the starting node
		for (auto& a_nodes : m_nodes)
		{
			a_nodes->reset();
		}
		m_path.clear();

		// Validate the input
		if (!a_start || !a_end)
		{
			return m_path;
		}
		if (a_start == a_end)
		{
			m_path.clear();
			m_path.push_back(a_start);
			return m_path;
		}

		// Create our temporary lists for storing nodes we’re visiting/visited
		std::list<node<T>*> open_list;
		std::list<node<T>*> closed_list;


		//Add startNode to openList
		open_list.push_back(a_start);

		node<T>* current_node;
		//While openList is not empty
		while (open_list.size()) // != 0 || > 0
		{
			current_node = open_list.front();
			open_list.pop_front();

			// If we visit the endNode, then we can exit early.
			// Sorting the openList guarantees the shortest path is found,
			// given no negative costs (a prerequisite of the algorithm).
			// If currentNode is endNode
			// Exit While Loop
			// Remove currentNode from openList
			// Add currentNode to closedList
			closed_list.push_back(current_node);


			//For all connections c in currentNode
			for (auto& a_edges : current_node->m_edges)
			{
				node<T>* other_node = nullptr;
				if (a_edges->m_nodes[0] == current_node)
				{
					other_node = a_edges->m_nodes[1];
				}
				else
				{
					other_node = a_edges->m_nodes[0];
				}

				if (std::find(std::begin(closed_list), std::end(closed_list), other_node) == closed_list.end())
				{
					// Let gScore = currentNode.gScore + c.cost
					int current_g_score = current_node->m_g_score + 1;
						//other_node->m_g_score = current_node->m_g_score + 1/*Edge weight*/;

						// So calculate the Score and update its parent.
						// Also add it to the openList for processing.
						// if c.target not in openList
						if (std::find(std::begin(open_list), std::end(open_list), other_node) == open_list.end())
						{
							// Let c.target.gScore = gScore
							other_node->m_g_score = current_g_score;
							other_node->m_previous = current_node;
							open_list.push_back(other_node);
							// Node is already in the openList with a valid Score.
							// So compare the calculated Score with the existing
							// to find a shorter path
						}
						else if (current_g_score < other_node->m_g_score)
						{
							other_node->m_g_score = current_g_score;
							other_node->m_previous = current_node;
						}
				}
			}
		}
		// Create Path in reverse from endNode to startNode
		// Let Path be a list of Nodes
		// Let currentNode = endNode
		// While currentNode is not null
		// Add currentNode to beginning of Path
		// Let currentNode = currentNode.parent
		node<T>* end_node = a_end;
		m_path.push_back(end_node);
		while (end_node != a_start)
		{
			end_node = end_node->m_previous;
			m_path.push_back(end_node);
		}
		// Return the path for navigation between startNode/endNode
		return m_path;
	}
};