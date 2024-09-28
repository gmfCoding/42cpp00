#include "Span.hpp"

Span::Span(unsigned int max) : m_used(0), m_max(max), m_container(new int[max])
{

}

Span::Span(const Span& copy) : m_used(copy.m_used), m_max(copy.m_max), m_container(new int[copy.m_max])  
{
	for (std::size_t i = 0; i < copy.m_used; i++)
		m_container[i] = copy.m_container[i];
}

Span& Span::operator=(const Span& rhs)
{
	if (&rhs == this)
		return *this;
	 std::size_t newSize = rhs.m_max;
	 int* newArray = newSize ? new int[newSize]() : nullptr;
	 std::copy(rhs.m_container, rhs.m_container + newSize, newArray);
	
	delete[] m_container;
	m_max = newSize;
	m_container = newArray;
	return *this;
}

Span::~Span()
{
	if (m_container != NULL)
		delete[] m_container;
}


void Span::addNumber(int number)
{
	if (m_used >= m_max)
		throw std::out_of_range("Span attempted to add number but span is full.");
	m_container[m_used] = number;
	m_used++;
}

int Span::smallest(int& index, int skip)
{
	int min = std::numeric_limits<int>::max();

	for (int i = 0; i < (long long)m_used; i++)
	{
		if (m_container[i] < min && i != skip)
		{
			index = i;
			min = m_container[i];
		}
	}
	return min;
}

int Span::largest()
{
	int max = std::numeric_limits<int>::min();

	for (int i = 0; i < (long long)m_used; i++)
	{
		if (m_container[i] > max)
		{
			max = m_container[i];
		}
	}
	return max;
}

int Span::shortestSpan()
{
	int span = std::numeric_limits<int>::max();

	for (std::size_t i = 0; i < m_used; i++)
	{
		for(std::size_t j = i + 1; j < m_used; j++)
		{
			if (std::abs(m_container[i] - m_container[j]) < span)
				span = std::abs(m_container[i] - m_container[j]);
		}
	}
	return span;
}

int Span::longestSpan()
{
	int discard;
	int min = smallest(discard, -1);
	int max = largest();
	return max - min;
}

