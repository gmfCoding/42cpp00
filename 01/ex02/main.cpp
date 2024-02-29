#include <string>
#include <iostream>

int main(void)
{
	std::string brain = "THIS IS BRAIN";
	std::string* brainPTR = &brain;
	std::string& brainREF = brain;

	std::cout << "str var:  " << &brain << std::endl;
	std::cout << "ptr held: " << brainPTR << std::endl;
	std::cout << "ref held: " << &brainREF << std::endl;

	std::cout << "str val: " << brain << std::endl;
	std::cout << "ptr val: " << *brainPTR << std::endl;
	std::cout << "ref val: " << brainREF << std::endl;

	return (0);
}
