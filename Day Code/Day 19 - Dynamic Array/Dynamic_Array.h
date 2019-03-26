#pragma once
#include <iostream>

template <typename T> 
class Dynamic_Array
{
public:
	Dynamic_Array(T) 
	{
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	~Dynamic_Array()
	{
		delete[] m_data;
		m_data = nullptr;

		m_capacity = 0;
		m_count = 0;
	}

	//Copy Constructor
	Dynamic_Array(const Dynamic_Array& a_other) {
		m_count = a_other.m_count;
		m_capacity = a_other.m_capacity;

		// Need to deepy copy the array data
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_data[i] = a_other.m_data[i];
		}
	}

	Dynamic_Array& operator=(const Dynamic_Array& a_other)

	{
		// Prevent copying over self
		if (&a_other == this) { return *this; }
		// Clean up any existing data
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}

		// Member wise copy
		m_count = a_other.m_count;
		m_capacity = a_other.m_capacity;

		// Need to deepy copy the array data
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			this->m_data[i] = a_other.m_data[i];
		}
		return *this;
	}

	// Access array element by index
	T& operator[] (const ){

	}

	// Add data
	void push(const T& a_data) {
		// Check capacity
		if (m_count == m_capacity)
		{
			std::cout << "Capacity"


		}
	}

	void pop() {

	}
};

