#include <iostream>
#include <stack>
#include <iterator>
#include "MutantStack.hpp"

// Test the MutantStack
int subjectex() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // Output: 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Output: 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it; // Move iterator forward
    --it; // Move iterator backward
    while (it != ite) {
        std::cout << *it << std::endl; // Output each element
        ++it;
    }

    std::stack<int> s(mstack); // Copying to std::stack
    return 0;
}


int main()
{
	subjectex();
	{
		MutantStack<std::string> names;

		names.push("Plate #1 (Quiche)");
		names.push("Plate #2 (Spaghetti)");
		names.push("Bowl #1 (Cereal)");
		names.push("Spoon");
		
		while (names.size() >= 1)
		{
			MutantStack<std::string>::iterator it = names.begin();
			MutantStack<std::string>::iterator ite = names.end();
			while (it != ite)
			{
				if (it + 1 == ite)
					std::cout << "*";
				std::cout << *it << std::endl;
				++it;
			}
			std::cout << std::endl;
			names.pop();
		}
	}
	return 0;
}
