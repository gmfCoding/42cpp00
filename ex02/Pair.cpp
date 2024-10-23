#include "Pair.hpp"
#include <algorithm>

Pair::Pair()
{ }

Pair::Pair(int a, int b): a(a), b(b)
{ }

Pair::Pair(int b): a(-1), b(b)
{ }

int Pair::RemoveB()
{
    int tmp = b;
    b = -1;
    return tmp;
}

int Pair::RemoveA()
{
    int tmp = a;
    a = -1;
    return tmp;
}

void Pair::AddA(int val)
{
    a = val;
}

void Pair::AddB(int val)
{
    b = val;
}

void Pair::Swap()
{
    std::swap(a, b);
}
