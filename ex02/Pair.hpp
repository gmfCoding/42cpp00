#ifndef PAIR_HPP
#define PAIR_HPP

struct Pair
{
public:

	int a;
	int b;

	Pair();

	Pair(int a, int b);
	
	Pair(int b);

	int RemoveB();

	int RemoveA();

	void AddA(int val);

	void AddB(int val);

	void Swap();
};
#endif
