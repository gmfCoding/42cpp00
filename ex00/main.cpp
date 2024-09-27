#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <deque>
#include <array>

template<typename T>
void template_fill(T& container)
{
	for (size_t i = 0; i < 10; i++)
		container.push_back(i);
}

template<>
void template_fill<std::array<int, 10> >(std::array<int, 10>& container)
{
	for (size_t i = 0; i < 10; i++)
		container[i] = i;
}

template<typename T>
void template_test(const std::string& name)
{
	T vec;
	template_fill(vec);
	typename T::iterator it = easyfind(vec, 4);
	std::cout << "[" << name << "]" << " Found: " << *it << " at index:" << it - vec.begin() << std::endl;
}

int main()
{
	template_test<std::vector<int> >("vector");
	template_test<std::array<int, 10> >("array");
	template_test<std::deque<int> >("dequeue");
}
