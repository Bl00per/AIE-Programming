#pragma once
/*
	Binary Tree
	Each leaf can only have two children.
	Each leaf only has one parent.
	The value of the left child is < the current leaf.
	The value of the right child is > the current leaf.
	Data can only exist once in the tree.

	Positions of data are relative to both existing data
	and the order data is added to the tree.
*/
#include "node.h"

template<typename T>
class binary_tree
{
public:
	binary_tree<T>() {}
	~binary_tree() {}

	node<T>* m_root_node = nullptr;

	bool insert(const T& a_data)
	{
		// If this is the first node, create root node
		if (!m_root_node)
		{
			m_root_node = new node<T>(a_data);
			return true;
		}

		// Look for location to insert
		bool inserted = false;
		node<T>* current_node = m_root_node;

		while (!inserted)
		{
			// Compare and traverse
			if (a_data == current_node->m_data)
			{
				// Data already existed
				inserted = false;
				return inserted;
			}

			// Left child check / insert
			else if (a_data < current_node->m_data)
			{
				if (current_node->m_left) // is there already node?
				{
					current_node = current_node->m_left;
				}
				else // Insert at null leaf by creating new node
				{
					current_node->m_left = new node<T>(a_data);
					current_node->m_left->m_parent = current_node;
					inserted = true;
				}
			}

			// Right child check / insert
			else if (a_data > current_node->m_data)
			{
				if (current_node->m_right) // is there already node?
				{
					current_node = current_node->m_right;
				}
				else // Insert at null leaf by creating new node
				{
					current_node->m_right = new node<T>(a_data);
					current_node->m_right->m_parent = current_node;
					inserted = true;
				}
			}
		}

		return inserted;
	}

	bool find(const T& a_data)
	{
		// If this is the first node, create root node
		if (!m_root_node) { return false; }

		bool found = false;
		// Look for location to insert
		node<T>* current_node = m_root_node;

		while (!found)
		{
			// Compare and traverse
			if (a_data == current_node->m_data)
			{
				// Data already existed
				found = true;
				return found;
			}

			// Left child check / insert
			else if (a_data < current_node->m_data)
			{
				if (current_node->m_left) // is there already node?
				{
					current_node = current_node->m_left;
				}
				else // Insert at null leaf by creating new node
				{
					return found;
				}
			}

			// Right child check / insert
			else if (a_data > current_node->m_data)
			{
				if (current_node->m_right) // is there already node?
				{
					current_node = current_node->m_right;
				}
				else // Insert at null leaf by creating new node
				{
					return found;
				}
			}
		}

		return found;
	}
};