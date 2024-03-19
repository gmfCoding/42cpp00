#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[97;1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[37;0m";
}

void test_1()
{
	std::cout << std::endl << bold_on << "[1] Basic test" << bold_off << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	i->makeSound(); 
	j->makeSound();
	delete i;
	delete j;
}

void test_2()
{
	std::cout << std::endl << bold_on << "[2] Copy Assignment test" << bold_off << std::endl;
	const Dog* j = new Dog();
	Dog i = *j;
	i.makeSound(); 
	j->makeSound();
	delete j;
}

void test_3()
{
	std::cout << std::endl << bold_on << "[3] Deep copy test" << bold_off << std::endl;
	{
		const Dog* original = new Dog();
		const Dog* dog = new Dog(*original);
		std::cout << bold_on << "Deep Copy:" << (dog->isDeepCopy(original) ? "True" : "False") << bold_off << std::endl;
		delete original;
		delete dog;
	}
	{
		const Cat* original = new Cat();
		const Cat* cat = new Cat(*original);
		std::cout << bold_on << "Deep Copy:" << (cat->isDeepCopy(original) ? "True" : "False") << bold_off << std::endl;
		delete original;
		delete cat;
	}

}

int main()
{
	std::cout << std::endl << bold_on << "[0] Main Test" << bold_off << std::endl;
	Animal* animals[8];
	const int size = sizeof(animals) / sizeof(*animals);

	for (size_t i = 0; i < size / 4; i++)
		animals[i] = new Dog();
	for (size_t i = size / 4; i < size; i++)
		animals[i] = new Cat();
	for (size_t i = 0; i < size; i++)
		delete animals[i];
	test_1();
	test_2();
	test_3();
	return 0;
}