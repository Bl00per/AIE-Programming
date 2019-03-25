#pragma once
// class templates
template <class T>
class MyArray
{
public:
	MyArray() = default;
	MyArray(T values[], int size) {
		m_size = size;
		// dynamically allocating an array with generic data type
		m_value = new T[m_size];
		// copying all the values into my array
		for (int i = 0; i < m_size; ++i) {
			m_value[i] = values[i];
		}
	}

	T& operator[] (int & index) {
		return m_value[index];
	}

	~MyArray() {}

private:
	// takes any type of variables
	T * m_value;
	// size of the array
	int m_size;
};

