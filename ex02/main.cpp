#include <iostream>
#include <vector>

struct Pair
{
public:
	int* a;
	int* b;

	Pair()
	{ }

	Pair(int* a, int* b) : a(a), b(b)
	{ }

	int* Largest()
	{
		if (b == NULL)
			return a;
		if (*a < *b)
			return b;
		return a;
	}

	int* Smallest()
	{
		if (b == NULL)
			return a;
		if (*a < *b)
			return a;
		return a;
	}
};
void createPairs(std::vector<int>& numbers, std::vector<Pair>& pairs)
{
	for (std::size_t i = 0; i < numbers.size(); i++)
	{
		if (i % 2 != 0)
			pairs.push_back(Pair(&numbers[i - 1], &numbers[i]));
		else if (i == numbers.size() - 1)
		{
			pairs.push_back(Pair(&numbers[i], NULL));
		}
	}
}

void highestOfPairs(std::vector<Pair>& pairs, std::vector<Pair>& list)
{
	int* tmp = NULL;
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (tmp != NULL)
		{
			list.push_back(Pair(tmp, (*it).Largest()));
			tmp = NULL;
			continue;
		}
		tmp = (*it).Largest();
	}
}

void sortHigh(std::vector<Pair> pairs)
{
	
}

void printPairs(std::vector<Pair> pairs)
{
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << *(pairs[i].a) << ", " << ((pairs[i].b) ? *(pairs[i].b) : -1)  << ")" << std::endl;
	}
}

int main()
{
	static const int arr[] = {6, 7, 8, 5, 3, 1, 2, 4, 9};
	std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::vector<Pair> pairs;
	createPairs(numbers, pairs);
	printPairs(pairs);
	std::vector<Pair> high;
	highestOfPairs(pairs, high);
	printPairs(high);
}
