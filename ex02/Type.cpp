#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

typedef Base* (*baseGeneratorFn)(void);

static Base* generateA()
{
	return new A();
}

static Base* generateB()
{
	return new B();
}

static Base* generateC()
{
	return new C();
}

Base* generate(void)
{
	static baseGeneratorFn generators[] = { &generateA, &generateB, &generateC };
	int i = std::rand() % 3;
	return generators[i]();
}

void identify(Base* base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "A";
	else if (dynamic_cast<B*>(base))
		std::cout << "B";
	else if (dynamic_cast<C*>(base))
		std::cout << "C";
	std::cout << std::endl;
}

template<class T>
std::string get_type_name(Base& base, const std::string& name)
{
	try
	{
		T& t = dynamic_cast<T&>(base);
		static_cast<void>(t);
		return name;
	}
	catch (std::exception& e)
	{
		return "";
	}	
}

void identify(Base& base)
{
	std::string name;

	name = get_type_name<A>(base, "A");
	if (name.empty())
		name = get_type_name<B>(base, "B");
	if (name.empty())
		name = get_type_name<C>(base, "C");
	if (name.empty())
		name = "unknown type";

	std::cout << name << std::endl;
}
