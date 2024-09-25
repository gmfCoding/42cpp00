#include <iostream>
#include <Array.hpp>
#include <cstdlib>

void test0()
{
	Array<std::string> names(10);
	names[0] = "James";
	names[1] = "Laurence";
	names[2] = "Tyler";
	names[3] = "Sarah";
	names[4] = "Vihn";
	names[5] = "Becca";

	for (int i = 0; i < names.size(); i++)
	{
		if (names[i].empty())
			continue;
		std::cout << i << ": " << names[i] << std::endl;
	}
}

void test1()
{
	Array<int>* numbers = new Array<int>(10);
	(*numbers)[0] = 1;
	(*numbers)[1] = 5;
	(*numbers)[2] = -2;
	(*numbers)[3] = 81;
	(*numbers)[4] = 986;
	(*numbers)[5] = -134;

	for (int i = 0; i < (*numbers).size(); i++)
	{
		std::cout << i << ": " << (*numbers)[i] << std::endl;
	}
	delete numbers;
}

#define MAX_VAL 750
int main(int, char**)
{
	test0();
	test1();
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
