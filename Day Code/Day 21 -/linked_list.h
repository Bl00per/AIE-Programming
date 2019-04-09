#pragma once

template <typename T>
class node
{
public:
	node<T>* m_previous = nullptr;
	node<T>* m_next = nullptr;

	T m_data = 0;
};

template <typename T>
class linked_list
{
public:
	// Sentinel nodes
	node<T>* m_start = nullptr;
	node<T>* m_end = nullptr;

	linked_list()
	{
		// allocate memory for sentinels
		m_start = new node<T>();
		m_end = new node<T>();

		// Cross link sentinaels
		m_start->m_next = m_end;
		m_end->m_previous = m_start;
	}

	~linked_list()
	{
		node<T>* current = m_start->m_next;
		while (current != m_end)
		{
			node<T>* next = current->m_next;
			delete current;
			current = nullptr;
			current = next;
		}

		delete m_start;
		m_start = nullptr;

		delete m_end;
		m_end = nullptr;
	}

	// Push a value to the front of array
	void pushFront(const T& a_data)
	{
		node<T>* current = new node<T>();
		current->m_data = a_data;
		// Cross link at start
		current->m_previous = m_start;
		current->m_next = m_start->m_next;

		m_start->m_next = current;
		current->m_next->m_previous = current;

		++m_count;
	}

	// Pushback and push are same thing
	void pushBack(const T& a_data)
	{
		node<T>* current = new node<T>();
		current->m_data = a_data;

		current->m_next = m_end;
		current->m_previous = m_end->m_previous;

		m_end->m_previous = current;
		current->m_previous->m_next = current;

		++m_count;
	}

	// Inserts data at location a_index
	// If index is out of bounds, data inserted at end
	void insert(const T& a_data, const size_t a_index)
	{
		// Count to index
		node<T>* current = m_start->m_next;
		size_t counter = 0;

		while (counter < a_index && current != m_end)
		{
			++counter;
			current = current->m_next;
		}

		// Create node - Here current will become the new node's next node
		node<T>* new_node = new node<T>();
		new_node->m_data = a_data;
		// Cross link at end
		new_node->m_next = current;
		new_node->m_previous = current->m_previous;

		current->m_previous = new_node;
		new_node->m_previous->m_next = new_node;

		++m_count;
	}

	node<T>* erase(const size_t a_index)
	{
		// Count to index
		node<T>* current = m_start->m_next;
		size_t counter = 0;

		while (counter < a_index && current != m_end)
		{
			++counter;
			current = current->m_next;
		}

		node<T>* out_node = nullptr;
		if (current != m_end)
		{
			// Introducing neighbours
			current->m_next->m_previous = current->m_previous;
			current->m_previous->m_next = current->m_next;

			out_node = current->m_next;

			// Removing node
			std::cout << "Removed element (" << current->m_data << ") at index " << a_index << std::endl;
			delete current;
			current = nullptr;
		}
		--m_count;
		return out_node;
	}

	void remove(const T& a_value)
	{
		// Count to index
		node<T>* current = m_start->m_next;
		size_t counter = 0;

		while (counter <= m_count && current != m_end)
		{
			if (a_value == current->m_data)
			{
				current = erase(counter);
			}
			else
			{
				++counter;
				current = current->m_next;
			}
		}
	}

	// Beginning of the list
	node<T>* begin()
	{
		node<T>* current = m_start;
		return current;
	}

	// End of the list
	node<T>* end()
	{
		node<T>* current = m_end;
		return current;
	}

	// First value of the list
	T first()
	{
		node<T>* current = m_start->m_next;
		return current->m_data;
	}

	// Last value of the list
	T last()
	{
		//if (m_end->m_previous != m_start)
		node<T>* current = m_end->m_previous;
		return current->m_data;
	}

	size_t count()
	{
		return m_count;
	}

	void popBack()
	{
		if (m_count > 0)
			erase(m_count - 1);
	}

	void popFront()
	{
		if (m_count > 0)
			erase(0);
	}

	bool empty()
	{
		return !(bool(m_count == 0));
	}

	void clear()
	{
		while (m_count > 0)
		{
			popFront();
		}
	}

private:
	size_t m_count = 0;

};