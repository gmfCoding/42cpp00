#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template<typename T>
class Array
{

private:
	T* m_array;
	int m_size;

public:	
	Array() : m_size(0), m_array(new T[0])
	{ }

	Array(int size) : m_array(new T[size]), m_size(size)
	{ }
	
	Array(const Array<T>& copy) : m_array(NULL), m_size(0)
	{
		operator=(copy);
	}

	Array<T>& operator=(const Array<T>& rhs)
	{
		if (this == &rhs)
			return *this;

		m_size = rhs.m_size;
		if (m_array)
			delete[] m_array;
		this->m_array = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
		return *this;
	}

	~Array()
	{ 
		if (m_array != NULL)
			delete[] m_array;
	}
	
	T& operator[](int index)
	{
		if (index >= m_size || index < 0)
		   throw std::out_of_range("Index out of bounds of array");	
		return m_array[index];
	}

	int size() const
	{
		return m_size;
	}
};

#endif
