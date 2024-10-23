#include "PmergeMe.hpp"

//TODO: Remove
void printPairs(std::vector<Pair> pairs);
void printChain(std::vector<int> arr);

PmergeMe::PmergeMe(std::vector<int>& numbers): numbers(numbers), pairs(0), chain(0), comparisons(0)
{

}

PmergeMe::PmergeMe(): numbers(0), pairs(0), chain(0), comparisons(0)
{

}



PmergeMe::PmergeMe(const PmergeMe& copy)
{
	if (&copy == this)
		return;
}


PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (&rhs == this)
		return *this;
	return *this;
}

PmergeMe::~PmergeMe()
{

}

std::vector<int> PmergeMe::Sort(int& comparisons)
{
	CreatePairs();
	printPairs(pairs);
	SortHigh();
	printPairs(pairs);
	pairs = MergeSort(pairs);
	printPairs(pairs);
	InitMainChain();
	printPairs(pairs);
	printChain(chain);
	InsertMainChain();

	if (numbers.size() % 2 != 0)
		InsertElement(*(numbers.end() - 1), chain);
	comparisons = this->comparisons;
	return chain;
}


void PmergeMe::CreatePairs()
{
	for (std::size_t i = 0; i < numbers.size(); i++)
	{
		if (i % 2 != 0)
			pairs.push_back(Pair(numbers[i - 1], numbers[i]));
		else if (i == numbers.size() - 1)
			last = numbers[i];
	}
}

std::vector<Pair> PmergeMe::Merge(std::vector<Pair>& left, std::vector<Pair>& right)
{
	std::vector<Pair> result;
	std::size_t i = 0;
	std::size_t j = 0;

	while (i < left.size() && j < right.size())
	{
		comparisons++;
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

std::vector<Pair> PmergeMe::MergeSort(std::vector<Pair>& pairs)
{
	if (pairs.size() <= 1)
		return pairs;

	int mid = pairs.size() / 2;

	std::vector<Pair> leftHalf(pairs.begin(), pairs.begin() + mid);
	std::vector<Pair> rightHalf(pairs.begin() + mid, pairs.end());

	std::vector<Pair> sortedLeft = MergeSort(leftHalf);
	std::vector<Pair> sortedRight = MergeSort(rightHalf);

	return Merge(sortedLeft, sortedRight);
}


// void sortFive(std::vector<Pair>& pairs, int val)
// {
// 	comparisons++;
// 	if (pairs.size() == 0)
// 		pairs.insert(pairs.begin(), Pair(val));

// 	else if (val < pairs[0].a)
// 	{
// 	comparisons++;

// 		pairs.insert(pairs.begin(), Pair(val));
// 		if (val > pairs[1].b)
// 		{
// 			pairs[0].Swap();
// 			pairs[0].AddB(pairs[1].RemoveB());
// 		}
// 	}
// 	else if (pairs.size() >= 2)
// 	{
// 	comparisons++;

// 		if (val > pairs[1].a)m
// 			pairs.insert(pairs.begin() + 2, Pair(val));
// 		else
// 			pairs.insert(pairs.begin() + 1, Pair(val));
// 	}
// }

void PmergeMe::SortHigh()
{
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		comparisons++;
		if (it->a < it->b && it->a && it->b)
			std::swap(it->a, it->b);
	}
}

void PmergeMe::InitMainChain()
{
	for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
		chain.push_back(it->a);
}

// A binary search based function
// to find the position
// where item should be inserted
// in a[low..high]
int PmergeMe::BinarySearch(int item, int low, int high)
{
	if (high <= low)
	{
		comparisons++;
		return (item > chain[low]) ?
				(low + 1) : low;
	}

	int mid = (low + high) / 2;

	if (item == chain[mid])
		return mid + 1;

	comparisons++;
	if (item > chain[mid])
		return BinarySearch(item, mid + 1, high);
	return BinarySearch(item, low, mid - 1);
}

void PmergeMe::InsertElement(int item, std::vector<int>& chain)
{
	// find location where selected should be inserted
	int loc = BinarySearch(item, 0, std::max(chain.size() - 1, (size_t)0));
	chain.insert(chain.begin() + loc, item);
}


void PmergeMe::InsertMainChain()
{
	// for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	// {
	// 	InsertElement(it->b, chain);
	// }
	chain.insert(chain.begin(), pairs.begin()->b);
	int loc, selected;
	for (size_t i = 1; i < pairs.size(); ++i)
	{
		selected = pairs[i].b;
		if (selected < 0)
			continue;
		loc = BinarySearch(selected, 0, chain.size());
		chain.insert(chain.begin() + loc, selected);
	}
}
