#pragma once

// Define guard
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class dynamic_array
{
public:
	// Constructor
	dynamic_array<T>()
	{
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	// Destructor
	~dynamic_array()
	{
		delete[] m_data;
		m_data = nullptr;

		m_capacity = 0;
		m_count = 0;
	}

	//Copy Constructor
	dynamic_array(const dynamic_array& a_other) {
		m_count = a_other.m_count;
		m_capacity = a_other.m_capacity;

		// Need to deepy copy the array data
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_data[i] = a_other.m_data[i];
		}
	}

	// Copy Assignment operator
	dynamic_array& operator=(const dynamic_array& a_other)
	{
		if (this == &a_other)
		{
			return *this;
		}

		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}

		// Member wise copy
		m_count = a_other.m_count;
		m_capacity = a_other.m_capacity;

		// Deep copy
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			this->m_data[i] = a_other.m_data[i];
		}
		return *this;
	}


	/* @brief push adds a copy of new data to the end of the current array
	   @param a_data is a const ref to the data to be stored by copy
	*/
	void push(const T& a_data)
	{
		// Check capacity
		if (m_count == m_capacity)
		{
			grow();
		}
		// Copy data into array at end
		m_data[m_count] = a_data;
		// Incremend item count
		++m_count;
	}

	/* @brief 'Removes' the last element in the array
	*/
	void pop()
	{
		--m_count;
	}

	// Doubles array capacity
	void grow()
	{
		// Increase size of array
		m_capacity *= 2; // Doubling capacity when needed
		T* new_location = new T[m_capacity]; // New temp. storage
		for (size_t i = 0; i < m_count; i++) // Deep copy to new storage
		{
			new_location[i] = m_data[i];
		}
		delete[] m_data;					 // Remove old storage
		m_data = new_location;				 // Point at new storage
	}

	void insert(dynamic_array<T>& a_data, size_t a_elemen_count, size_t a_index)
	{
		insert(a_data.m_data, a_data.m_count, a_index);
	}

	// 1 or more elements or type t
	void insert(const T* a_data, size_t a_elemen_count, size_t a_index)
	{
		// Check capacity for insertion of 1 element
		while (m_count + a_elemen_count >= m_capacity)
		{
			grow();
		}

		// Move the data over
		for (size_t i = m_count - 1; i >= a_index; i--)
		{
			m_data[i + a_elemen_count] = m_data[i];
		}
		// Copy insertion from array
		size_t j = 0;
		for (size_t i = a_index; i < a_index; i++, j++)
		{
			m_data[i] = a_data[j]; // Insert from array
		}
	}

	void remove(size_t a_index, size_t a_count = 1)
	{
		for (size_t i = a_index; i + a_count < m_count; i++)
		{
			m_data[i] = m_data[i + a_count];
		}

		m_count -= a_count;
	}

	// Set as private function
	void trim()
	{
		if (m_count < m_capacity)
		{
			m_capacity = m_count + 1;
			T* new_location = new T[m_capacity]; // New temp. storage
			for (size_t i = 0; i < m_count; i++) // Deep copy to new storage
			{
				new_location[i] = m_data[i];
			}
			delete[] m_data;					 // Remove old storage
			m_data = new_location;
		}
	}

	void clear()
	{
		delete[] m_data;
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	// Access array element by index
	T& operator[] (const int index)
	{
		return m_data[index];
	}

	size_t count() const
	{
		return m_count;
	}

	size_t capacity() const
	{
		return m_capacity;
	}

private:
	// Pointer to storage
	T* m_data = nullptr;

	// Store current length
	size_t m_count = 0; // Count = length

	// Store current capacity
	size_t m_capacity = 0;

	// Default capacity for default storage
	const size_t m_default_capacity = 8;
};

#endif // !DYNAMIC_ARRAY_H