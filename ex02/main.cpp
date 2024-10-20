#include <iostream>
#include <vector>

struct Pair
{
public:
	int a;
	int b;

	Pair()
	{ }

	Pair(int a, int b) : a(a), b(b)
	{ }

	int Largest()
	{
		if (a < b)
			return b;
		return a;
	}

	int Smallest()
	{
		if (a < b)
			return a;
		return b;
	}
};


void printPairs(std::vector<Pair> pairs)
{
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].a << ", " << pairs[i].b << ")" << std::endl;
	}
	std::cout << std::endl;
}

void createPairs(std::vector<int>& numbers, std::vector<Pair>& pairs, int& last)
{
	for (std::size_t i = 0; i < numbers.size(); i++)
	{
		if (i % 2 != 0)
			pairs.push_back(Pair(numbers[i - 1], numbers[i]));
		else if (i == numbers.size() - 1)
			last = numbers[i];
	}
}

// void highestOfPairs(std::vector<Pair>& pairs, std::vector<Pair>& list)
// {
// 	int* tmp = NULL;
// 	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
// 	{
// 		if (tmp != NULL)
// 		{
// 			list.push_back(Pair(tmp, (*it).Largest()));
// 			tmp = NULL;
// 			continue;
// 		}
// 		tmp = (*it).Largest();
// 	}
// }

std::vector<Pair> merge(std::vector<Pair>& left, std::vector<Pair>& right)
{
	std::vector<Pair> result;
	std::size_t i = 0;
	std::size_t j = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i].a < right[j].a)
		{
			result.push_back(left[i]);
			i += 1;
		}
		else
		{
			result.push_back(right[j]);
			j += 1;
		}
	}

	result.insert(result.end(), left.begin() + i, left.end());
	result.insert(result.end(), right.begin() + j, right.end());
	return result;
}

std::vector<Pair> mergeSort(std::vector<Pair>& pairs)
{
	if (pairs.size() <= 1)
		return pairs;

	int mid = pairs.size() / 2;

    std::vector<Pair> leftHalf(pairs.begin(), pairs.begin() + mid);
    std::vector<Pair> rightHalf(pairs.begin() + mid, pairs.end());

	std::vector<Pair> sortedLeft = mergeSort(leftHalf);
	std::vector<Pair> sortedRight = mergeSort(rightHalf);

	return merge(sortedLeft, sortedRight);
}



void sortHigh(std::vector<Pair>& pairs)
{
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->a < it->b && it->a && it->b)
			std::swap(it->a, it->b);
	}
}


int main()
{
	static const int arr[] = {6, 7, 8, 5, 3, 1, 2, 4, 9};
	std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::vector<Pair> pairs;
	int last;
	createPairs(numbers, pairs, last);
	// printPairs(pairs);
	// std::vector<Pair> high;
	// highestOfPairs(pairs, high);
	// printPairs(pairs);
	
	printPairs(pairs);
	sortHigh(pairs);
	printPairs(pairs);
	pairs = mergeSort(pairs);
	printPairs(pairs);
}
