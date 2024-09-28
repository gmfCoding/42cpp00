#include "Span.hpp"
#include <iostream>

const char* GREEN = "\033[1;32m";
const char* RED = "\033[1;31m";
const char* WHITE = "\033[0m";

void test(int shortest, int longest, std::size_t amount, ...)
{
	va_list args;
	va_start(args, amount);

	Span span(amount);
	for (std::size_t i = 0; i < amount; i++)
		span.addNumber(va_arg(args, int));
	va_end(args);

	int shortSpan = span.shortestSpan();
	int longSpan = span.longestSpan();
	
	if (longest != longSpan || shortest != shortSpan)
		std::cout << RED;
	if (shortest != shortSpan)
		std::cout << "Shortest";
	if (longest != longSpan && shortest != shortSpan)
		std::cout << " & ";
	if (longest != longSpan)
		std::cout << "Longest";
	if (longest != longSpan || shortest != shortSpan)
		std::cout << " TEST FAILED: ";
	else
		std::cout << GREEN << "TEST PASSED: ";
   
	std::cout << shortest << ", " << longest << WHITE << std::endl;
}

int main()
{
	test(10, 20, 3, 10, 20, 30);

	return 0;
}
