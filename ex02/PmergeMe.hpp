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

static unsigned long jacobsthal_diff[] = {
	2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
	2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
	1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
	178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
	11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
	366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
	11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
	375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
	6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
	96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
	1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

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
		comparisons++;
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
		// Starting with the first element from the pairs
		if (!pairs.empty()) {
			chain.insert(chain.begin(), pairs.front().b);
		}

		for (size_t i = 1; i < pairs.size(); ++i) {
			// Use Jacobsthal sequence to decide the segment size
			if (i < sizeof(jacobsthal_diff) / sizeof(jacobsthal_diff[0])) {
				size_t segment_size = jacobsthal_diff[i];
				if (i + segment_size > pairs.size()) {
					segment_size = pairs.size() - i; // Adjust segment size if it exceeds remaining pairs
				}

				// Perform binary search and insertion for each segment
				for (size_t j = 0; j < segment_size && (i + j) < pairs.size(); ++j) {
					int selected_value = containerAt(pairs.begin(), i + j)->b;
					int loc = BinarySearch(selected_value, 0, chain.size());
					chain.insert(containerAt(chain.begin(), loc), selected_value);
				}
				i += segment_size - 1; // Move the index forward by segment size
			}
		}
	}
};

#endif
