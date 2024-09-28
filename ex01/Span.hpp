#ifndef SPAN_HPP
#define SPAN_HPP
#include <cstddef>
#include <algorithm>
#include <limits>
class Span
{

private:
	std::size_t m_used;
	std::size_t m_max;
	
	int* m_container;

	Span();

public:
	Span(unsigned int max);
	Span(const Span& copy);
	Span& operator=(const Span& rhs);
	~Span();


	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

private:
	int smallest(int& index, int skip);
	int largest();
};


#endif
