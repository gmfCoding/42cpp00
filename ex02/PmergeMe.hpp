#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include "Pair.hpp"
#include <vector>

class PmergeMe
{
	std::vector<int> numbers;
	std::vector<Pair> pairs;
	std::vector<int> chain;
    int comparisons;
	int last;

	PmergeMe();
public:
	PmergeMe(std::vector<int>& numbers);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& rhs);
	virtual ~PmergeMe();
	std::vector<int> Sort(int& comparisons);

private:
    void InitMainChain();
	void InsertMainChain();
	int BinarySearch(int item, int low, int high);
	void InsertElement(int item, std::vector<int>& chain);
	void SortHigh();
	void CreatePairs();

    std::vector<Pair> Merge(std::vector<Pair>& left, std::vector<Pair>& right);

	std::vector<Pair> MergeSort(std::vector<Pair>& pairs);
};

#endif
