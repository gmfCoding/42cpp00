#include <iostream>
#include <vector>
#include <algorithm>

int g_comparisons_count = 0;


struct Pair
{
public:

	int a;
	int b;

	Pair()
	{ }

	Pair(int a, int b): a(a), b(b)
	{ }
	
	Pair(int b): a(-1), b(b)
	{ }

	int RemoveB()
	{
		int tmp = b;
		b = -1;
		return tmp;
	}

	int RemoveA()
	{
		int tmp = a;
		a = -1;
		return tmp;
	}

	void AddA(int val)
	{
		a = val;
	}

	void AddB(int val)
	{
		b = val;
	}

	void Swap()
	{
		std::swap(a, b);
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
#include <signal.h>

void printChain(std::vector<int> arr)
{
	for (std::size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ", ";
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

std::vector<Pair> merge(std::vector<Pair>& left, std::vector<Pair>& right)
{
	std::vector<Pair> result;
	std::size_t i = 0;
	std::size_t j = 0;

	while (i < left.size() && j < right.size())
	{
		g_comparisons_count++;
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


void sortFive(std::vector<Pair>& pairs, int val)
{
	g_comparisons_count++;
	if (pairs.size() == 0)
		pairs.insert(pairs.begin(), Pair(val));

	else if (val < pairs[0].a)
	{
	g_comparisons_count++;

		pairs.insert(pairs.begin(), Pair(val));
		if (val > pairs[1].b)
		{
			pairs[0].Swap();
			pairs[0].AddB(pairs[1].RemoveB());
		}
	}
	else if (pairs.size() >= 2)
	{
	g_comparisons_count++;

		if (val > pairs[1].a)
			pairs.insert(pairs.begin() + 2, Pair(val));
		else
			pairs.insert(pairs.begin() + 1, Pair(val));
	}
}

void sortHigh(std::vector<Pair>& pairs)
{
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		g_comparisons_count++;
		if (it->a < it->b && it->a && it->b)
			std::swap(it->a, it->b);
	}
}


void initMainChain(std::vector<Pair>& pairs, std::vector<int>& chain)
{
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		chain.push_back(it->a);
	}
}


// A binary search based function
// to find the position
// where item should be inserted
// in a[low..high]
int binarySearch(std::vector<int> vec, int item,
				int low, int high)
{
	if (high <= low)
	{
		g_comparisons_count++;
		return (item > vec[low]) ?
				(low + 1) : low;
	}

	int mid = (low + high) / 2;

	if (item == vec[mid])
		return mid + 1;

	g_comparisons_count++;
	if (item > vec[mid])
		return binarySearch(vec, item,
							mid + 1, high);
	return binarySearch(vec, item, low,
						mid - 1);
}

void insertElement(int item, std::vector<int>& chain)
{
	// find location where selected should be inserted
	int loc = binarySearch(chain, item, 0, std::max(chain.size() - 1, (size_t)0));
	chain.insert(chain.begin() + loc, item);
}



void insertMainChain(std::vector<Pair>& pairs, std::vector<int>& chain)
{
	// for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	// {
	// 	insertElement(it->b, chain);
	// }
	chain.insert(chain.begin(), pairs.begin()->b);
	size_t i;
	int loc, selected;
	for (i = 1; i < pairs.size(); ++i)
	{
		selected = pairs[i].b;
		if (selected < 0)
			continue;
		loc = binarySearch(chain, selected, 0, chain.size());
		chain.insert(chain.begin() + loc, selected);
	}
}

// // Function to sort an array a[] of size 'n'
// void insertionSort(std::vector<Pair>& pairs, std::vector<int>& chain)
// {
//     int i, loc, j, k, selected;
//     for (i = 1; i < pairs.size(); ++i)
//     {
//         j = i - 1;
//         selected = pairs[i].b;
//         // find location where selected should be inserted
//         loc = binarySearch(chain, selected, 0, j);
//         chain.insert(chain.begin() + loc, selected);
//     }
// }

#define SETS 10
#define ELEM 9
int main()
{
	static const int sets[SETS][ELEM] = {{13, 17, 19, 6, 20, 18, 11, 8, 12}, 
	{4, 10, 6, 12, 15, 14, 9, 7, 5}, 
	{2, 16, 8, 10, 6, 18, 3, 1, 14}, 
	{10, 2, 3, 12, 11, 5, 7, 6, 13}, 
	{13, 11, 18, 14, 7, 5, 19, 1, 16}, 
	{13, 14, 9, 2, 7, 5, 16, 3, 12}, 
	{4, 17, 14, 16, 1, 5, 2, 13, 9}, 
	{4, 19, 13, 20, 12, 6, 18, 8, 11}, 
	{5, 8, 16, 3, 11, 13, 10, 17, 19}, 
	{7, 19, 6, 10, 18, 5, 15, 1, 20}};

	for (unsigned int i = 0; i < SETS; i++)
	{
		const int* arr = &sets[i][0];
		std::vector<int> numbers(arr, arr + ELEM);
		std::vector<Pair> pairs;
		std::vector<int> chain;;
		int last;
		createPairs(numbers, pairs, last);
		
		printPairs(pairs);
		sortHigh(pairs);
		printPairs(pairs);
		pairs = mergeSort(pairs);
		printPairs(pairs);
		initMainChain(pairs, chain);
		printPairs(pairs);
		printChain(chain);
		insertMainChain(pairs, chain);

		if (numbers.size() % 2 != 0)
			insertElement(*(numbers.end() - 1), chain);
		printChain(chain);
		std::cout << "Comparisons: " << g_comparisons_count << std::endl;
		g_comparisons_count = 0;
	}
}
