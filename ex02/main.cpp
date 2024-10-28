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
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
#include <unistd.h>

template <typename T>
typename T::IntContainer benchmark(T& t, double &elapsed)
{
	int comparisons;
	std::clock_t start = std::clock();
	typename T::IntContainer con = t.Sort(comparisons);
	// if (!std::is_sorted(con.cbegin(), con.cend()))
	// {
	// 	for (typename T::IntContainer::iterator it = con.begin(); it != con.end(); it++)
	// 		std::cout << *it << ' ';
	// 	std::cerr << "ERROR NOT SORTED" << std::endl;
	// 	exit(1);
	// }
	std::clock_t end = std::clock();
	elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);

	//std::cout << comparisons << std::endl;
	return con;
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

		double vecElapsed = 0;
		double listElapsed = 0;

		std::vector<int> chain = benchmark(first, vecElapsed);
		benchmark(second, listElapsed);


		std::cout << "After: ";
		printChain(chain);
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecElapsed << " us" << std::endl;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::list : " << listElapsed << " us" << std::endl;

	}
    catch (const char *errorMsg)
    {
        std::cout << "Error: " << errorMsg << std::endl;
    }
	return 0;
}
