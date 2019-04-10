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

	void draw(aie::Renderer2D* renderer, node<T>* selected)
	{
		draw(renderer, m_root_node, 640, 680, 640, selected);
	}

	void draw(aie::Renderer2D* renderer, node<T>* pNode, int x, int y, int horizontalSpacing, node<T>* selected)
	{
		horizontalSpacing /= 2;
		if (pNode)
		{
			if (pNode->m_left)
			{
				renderer->setRenderColour(1, 0, 0);
				renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
				draw(renderer, pNode->m_left, x - horizontalSpacing, y - 80, horizontalSpacing, selected);
			}
			if (pNode->m_right)
			{
				renderer->setRenderColour(1, 0, 0);
				renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
				draw(renderer, pNode->m_right, x + horizontalSpacing, y - 80, horizontalSpacing, selected);
			}
			pNode->draw(renderer, x, y, (selected == pNode));
		}
	}

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

	bool remove(const T& a_data)
	{
		if (!find(a_data))
			return false;

		// Look for location to insert
		bool found = false;
		node<T>* current_node = m_root_node;

		// Find the data
		while (!found)
		{
			// Compare and traverse
			if (a_data == current_node->m_data)
			{
				// Data already existed
				found = true;
			}
			// Left child check / insert
			else if (a_data < current_node->m_data)
			{
				if (current_node->m_left) // Is there already node?
				{
					current_node = current_node->m_left;
				}
			}

			// Right child check / insert
			else if (a_data > current_node->m_data)
			{
				if (current_node->m_right) // Is there already node?
				{
					current_node = current_node->m_right;
				}
			}
		}

		//If the current node has a right branch, then
		if (current_node->m_right)
		{
			// find the minimum value in the right 
			// branch by iterating down the left branch of the
			// current node’s right child until there are no more left branch nodes
			node<T>* search_node = current_node->m_right;
			while (search_node->m_left)
			{
				search_node = search_node->m_left;
			}
			//copy the value from this minimum node to the current node
			current_node->m_data = search_node->m_data;
			//find the minimum node’s parent node
			//	(the parent of the node you are deleting)
			// search_node->m_parent
			if (search_node == search_node->m_parent->m_left)
			{
				//if you are deleting the parent’s left node
				//	set this left child of the parent to the right 
				//  child of the minimum node
				search_node->m_parent->m_left = search_node->m_right;
				if (search_node->m_right)
					search_node->m_right->m_parent = search_node->m_parent;
				delete search_node;
				search_node = nullptr;
			}
			else if (search_node == search_node->m_parent->m_right)
			{
				//if you are deleting the parent’s right node
				// set the right child of the parent to 
				// the minimum node’s right child
				search_node->m_parent->m_right = search_node->m_right;
				if (search_node->m_right)
					search_node->m_right->m_parent = search_node->m_parent;
				delete search_node;
				search_node = nullptr;
			}
			else
			{
				std::cout << "Massive Error in remove!";
			}

			return true;

		}
		else
		{
			//If we are deleting the root, the root becomes the left child of the current node
			if (current_node == m_root_node)
			{
				if (m_root_node->m_left)
				{
					m_root_node = m_root_node->m_left;
					m_root_node->m_parent = nullptr;
				}
				else
				{
					//Last node?
					m_root_node = nullptr;
				}

			}
			//If the current node has no right branch
			//if we are deleting the parent’s left child,
			//	set the left child of the parent to the left
			// child of the current node
			else if (current_node == current_node->m_parent->m_left)
			{
				current_node->m_parent->m_left = current_node->m_left;
				current_node->m_left->m_parent = current_node->m_parent;
			}
			//If we are deleting the parent’s right child, set the right child of the parent to the left
			//child of the current node
			else if (current_node == current_node->m_parent->m_right)
			{
				current_node->m_parent->m_right = current_node->m_left;
				current_node->m_left->m_parent = current_node->m_parent;
			}
			delete current_node;
			current_node = nullptr;
			return true;
		}
	}
};