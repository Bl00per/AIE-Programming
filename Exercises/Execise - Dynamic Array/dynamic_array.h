#pragma once

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

	// Assignment operator
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

	// Access array element by index
	T& operator[] (const int index)
	{
		return m_data[index];
	}

	// Adding data
	void push(const T& a_data)
	{
		// Check if the length is equal to the capacity
		if (m_count == m_capacity)
		{
			std::cout << "Capacity increased\n";
			// Increase size of array
			//m_capacity += m_default_capacity;
			m_capacity *= 2;
			T* new_location = new T[m_capacity];
			for (size_t i = 0; i < m_count; i++)
			{
				new_location[i] = m_data[i];
			}
			delete[] m_data;
			m_data = new_location;
		}
		m_data[m_count] = a_data;
		++m_count;
	}

	void pop()
	{
		--m_count;
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