#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include "Pair.hpp"
#include <vector>
#include <list>

void printPairs(std::list<Pair> pairs);
void printPairs(std::vector<Pair> pairs);
void printChain(std::list<int> arr);
void printChain(std::vector<int> arr);

template<typename T>
T containerAt(T it, int index)
{
	advance(it, index);
	return it;
}

template <template <class, class> class Container = std::vector, class Allocator = std::allocator<int> >
class PmergeMe
{
	public:
    typedef Container<int, std::allocator<int> > IntContainer;
    typedef Container<Pair, std::allocator<Pair> > PairContainer;
private:

	IntContainer numbers;
	PairContainer pairs;
	IntContainer chain;
    int comparisons;
	int last;

	PmergeMe(): numbers(0), pairs(0), chain(0), comparisons(0)
	{

	}

public:
	PmergeMe(IntContainer& numbers): numbers(numbers), pairs(0), chain(0), comparisons(0)
	{

	}

	PmergeMe(const PmergeMe<Container, Allocator>& copy)
	{
		if (&copy == this)
			return;
	}

	PmergeMe& operator=(const PmergeMe<Container, Allocator>& rhs)
	{
		if (&rhs == this)
			return *this;
		return *this;
	}

	~PmergeMe()
	{

	}

	IntContainer Sort(int& comparisons)
	{
		CreatePairs();
		// printPairs(pairs);
		SortHigh();
		// printPairs(pairs);
		pairs = MergeSort(pairs);
		// printPairs(pairs);
		InitMainChain();
		// printPairs(pairs);
		// printChain(chain);
		InsertMainChain();

		if (numbers.size() % 2 != 0)
			InsertElement(*containerAt(numbers.end(), -1), chain);
		comparisons = this->comparisons;
		return chain;
	}

private:

	void CreatePairs()
	{
		for (std::size_t i = 0; i < numbers.size(); i++)
		{
			if (i % 2 != 0)
				pairs.push_back(Pair(*containerAt(numbers.begin(), i - 1), *containerAt(numbers.begin(), i)));
			else if (i == numbers.size() - 1)
				last = *containerAt(numbers.begin(), i);
		}
	}

	PairContainer Merge(PairContainer& left, PairContainer& right)
	{
		PairContainer result;
		std::size_t i = 0;
		std::size_t j = 0;

		while (i < left.size() && j < right.size())
		{
			comparisons++;
			if (containerAt(left.begin(), i)->a < containerAt(right.begin(), j)->a)
			{
				result.push_back(*containerAt(left.begin(), i));
				i += 1;
			}
			else
			{
				result.push_back(*containerAt(right.begin(), j));
				j += 1;
			}
		}

		result.insert(result.end(), containerAt(left.begin(), i), left.end());
		result.insert(result.end(), containerAt(right.begin(), j), right.end());
		return result;
	}

	PairContainer MergeSort(PairContainer& pairs)
	{
		if (pairs.size() <= 1)
			return pairs;

		int mid = pairs.size() / 2;

		PairContainer leftHalf(pairs.begin(), containerAt(pairs.begin(), mid));
		PairContainer rightHalf(containerAt(pairs.begin(), mid), pairs.end());

		PairContainer sortedLeft = MergeSort(leftHalf);
		PairContainer sortedRight = MergeSort(rightHalf);

		return Merge(sortedLeft, sortedRight);
	}


	// void sortFive(PairContainer& pairs, int val)
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

	void SortHigh()
	{
		for (typename PairContainer::iterator it = pairs.begin(); it != pairs.end(); it++)
		{
			comparisons++;
			if (it->a < it->b && it->a && it->b)
				std::swap(it->a, it->b);
		}
	}

	void InitMainChain()
	{
		for (typename PairContainer::iterator it = pairs.begin(); it != pairs.end(); it++)
			chain.push_back(it->a);
	}

	// A binary search based function
	// to find the position
	// where item should be inserted
	// in a[low..high]
	int BinarySearch(int item, int low, int high)
	{
		if (high <= low)
		{
			comparisons++;
			return (item > *containerAt(chain.begin(), low)) ?
					(low + 1) : low;
		}

		int mid = (low + high) / 2;
		if (item == *containerAt(chain.begin(), mid))
			return mid + 1;
		comparisons++;
		if (item > *containerAt(chain.begin(), mid))
			return BinarySearch(item, mid + 1, high);
		return BinarySearch(item, low, mid - 1);
	}

	void InsertElement(int item, IntContainer& chain)
	{
		// find location where selected should be inserted
		int loc = BinarySearch(item, 0, std::max(chain.size() - 1, (size_t)0));
		chain.insert(containerAt(chain.begin(), loc), item);
	}


	void InsertMainChain()
	{
		// for (PairContainer::iterator it = pairs.begin(); it != pairs.end(); it++)
		// {
		// 	InsertElement(it->b, chain);
		// }
		chain.insert(chain.begin(), pairs.begin()->b);
		int loc, selected;
		for (size_t i = 1; i < pairs.size(); ++i)
		{
			
			selected = containerAt(pairs.begin(), i)->b;
			if (selected < 0)
				continue;
			loc = BinarySearch(selected, 0, chain.size());
			
			chain.insert(containerAt(chain.begin(), loc), selected);
		}
	}

};

#endif
