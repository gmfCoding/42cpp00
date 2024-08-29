#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Type.hpp"
#include <iostream>

template<class T>
void testRef()
{
	T t = T();
	identify(t);
}


template<class T>
void testPtr()
{
	T* t = new T();
	identify(t);
	delete t;
}

int main()
{
	std::cout << "Testing A,B,C identify references\n" << std::endl;
	testRef<A>();
	testRef<B>();
	testRef<C>();

	std::cout << "Testing A,B,C identify pointers\n" << std::endl;
	testPtr<A>();
	testPtr<B>();
	testPtr<C>();

	std::cout << "Generating 20 random instances\n" << std::endl;
	for(int i = 0; i < 20; i++)
	{
		Base* instance = generate();
		identify(instance);
		delete instance;
	}
	return 0;
}
