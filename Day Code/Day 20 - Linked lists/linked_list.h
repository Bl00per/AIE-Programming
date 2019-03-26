#pragma once


class node
{
public:
	node* m_previous = nullptr;
	node* m_next = nullptr;

	int m_data = 0;
};

class linked_list
{
	// Sentinel nodes
	node* m_start = nullptr;
	node* m_end = nullptr;

	linked_list() 
	{
		// allocate memory for sentinels
		m_start = new node();
		m_end = new node();

		// Cross link sentinaels
		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	~linked_list()
	{
		node* current = m_start->m_next;
		while (current != m_end)
		{
			node* next = current->m_next;
			delete current;
			current = nullptr;
			current = next;
		}

		delete m_start;
		m_start = nullptr;

		delete m_end;
		m_end = nullptr;
	}

	void push(const int a_data)
	{
		node* current = new node();
		current->m_data = a_data;
		// Cross link at end
		current->m_next = m_end;
		current->m_previous = m_end->m_previous;

		m_end->m_previous = current;
		current->m_previous->m_next = current;
	}

	// Inserts data at location a_index
	// If index is out of bounds, data inserted at end
	void insert(const int a_data, const size_t a_index)
	{
		// Count to index
		node* current = m_start->m_next;
		size_t counter = 0;

		while (counter < a_index && current != m_end)
		{
			++counter;
			current = current->m_next;
		}

		// Create node - Here current will become the new node's next node
		node* new_node = new node();
		new_node->m_data = a_data;
		// Cross link at end
		new_node->m_next = current;
		new_node->m_previous = current->m_previous;

		current->m_previous = new_node;
		new_node->m_previous->m_next = new_node;
	}

	void remove(const size_t a_index)
	{
		// Count to index
		node* current = m_start->m_next;
		size_t counter = 0;

		while (counter < a_index && current != m_end)
		{
			++counter;
			current = current->m_next;
		}

		if (current != m_end)
		{
			// Introducing neighbours
			current->m_next->m_previous = current->m_previous;
			current->m_previous->m_next = current->m_next;
			// Removing node
			delete current;
			current = nullptr;
		}
	}
};