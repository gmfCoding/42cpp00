#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{

private:
	int m_used;
	int m_max;
	
	int m_container[];

	Span();

public:
	Span(unsigned int max);
	Span(const Span& copy);
	Span& operator=(const Span& rhs);
	~Span();

	shortestSpan();
	longestSpan();
}

Span::Span(unsigned int max) : m_used(0), m_max(max), m_container(new int[max])
{

}

Span::(const Span& copy) : m_used(copy.m_used), m_max(copy.m_max), m_container(new int[copy.m_max])  
{
	for (size_t i = 0; i < copy.m_used; i++)
		m_container[i] = copy.m_container[i];
}

Span& Span::operator=(const Span& rhs)
{
	if (&rhs == this)
		return *this;
	 std::size_t newSize = rhs.m_max;
	 int* newArray = newSize ? new int[newSize]() : nullptr;
	 std::copy(rhs.mArray, rhs.mArray + newSize, newArray);
	
	delete [] mArray;
	m_max = newSize;
	m_container = newArray;
}

Span::~Span()
{
	if (m_container != NULL)
		delete[] m_container;
}



#endif
