#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "Pair.hpp"
#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>

int g_comparisons_count = 0;

void printPairs(std::list<Pair> pairs)
{
	for (std::list<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << "(" << it->a << ", " << it->b << ")" << std::endl;
	}
	std::cout << std::endl;
}

void printChain(std::list<int> arr)
{
	for (std::list<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

void printPairs(std::vector<Pair> pairs)
{
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].a << ", " << pairs[i].b << ")" << std::endl;
	}
	std::cout << std::endl;
}

void printChain(std::vector<int> arr)
{
	for (std::size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
void benchmark(T& t, int size, const std::string& container_name)
{
	int comparisons;
	std::clock_t start = std::clock();
	typename T::IntContainer con = t.Sort(comparisons);
	if (!std::is_sorted(con.cbegin(), con.cend()))
	{
		for (typename T::IntContainer::iterator it = con.begin(); it != con.end(); it++)
			std::cout << *it << ' ';
		std::cerr << "ERROR NOT SORTED" << std::endl;
		exit(1);
	}
	std::clock_t end = std::clock();
	double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);

	std::cout << "After: ";
	for (typename T::IntContainer::iterator it = con.begin(); it != con.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "Time to process a range of " << size << " elements with" << container_name << " : " << elapsed << " us" << std::endl;
	std::cout << comparisons << std::endl;

}

int main(int argc, char *argv[])
{
	if (argc <= 2)
	{
		std::cout << "Please provide at least 2 arguments" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::list<int> list;

	try
	{
		for (int i = 1; i < argc; i++)
		{
			int number;
			std::stringstream readstring(argv[i]);
			bool state = !(readstring >> number);
			if (state)
				throw ": Not a number";
			if (number < 0)
				throw ": Negative number !";
			vec.push_back(number);
			list.push_back(number);
		}

		PmergeMe<std::vector> first(vec);
		PmergeMe<std::list> second(list);

		std::cout << "Before: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		benchmark(first, argc - 1, "std::vector");
		benchmark(second, argc - 1, "std::list");

	}
    catch (const char *errorMsg)
    {
        std::cout << "Error: " << errorMsg << std::endl;
    }
	return 0;
}