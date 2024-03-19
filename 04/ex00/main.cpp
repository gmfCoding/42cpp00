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
	std::cout << std::endl << bold_on << "[1] Base pointer type test" << bold_off << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}

void test_2()
{
	std::cout << std::endl << bold_on << "[2] Specific/Self pointer type test" << bold_off << std::endl;
	const Animal* meta = new Animal();
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}

void test_3()
{
	std::cout << std::endl << bold_on << "[3] Static test" << bold_off << std::endl;
	const Animal meta = Animal();
	const Dog j = Dog();
	const Cat i = Cat();
	std::cout << j.getType() << " " << std::endl;
	std::cout << i.getType() << " " << std::endl;
	i.makeSound(); //will output the cat sound!
	j.makeSound();
	meta.makeSound();
}

void test_4()
{
	std::cout << std::endl << bold_on << "[4] Repeated invokation type test" << bold_off << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	for (size_t i = 0; i < 10; i++)
	{
		dog->makeSound();
		cat->makeSound();
	}
	delete dog;
	delete cat;
}

void test_5()
{
	std::cout << std::endl << bold_on << "[5] Indirect deletion test" << bold_off << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Animal* dog_del = dog;
	const Animal* cat_del = cat;
	delete dog_del;
	delete cat_del;
}

void test_6()
{
	std::cout << std::endl << bold_on << "[6] Polymorphic Array test" << bold_off << std::endl;
	const int size = 7;
	const Animal* animals[size] = {
		new Dog(),
		new Cat(),
		new Animal(),
		new Cat(),
		new Cat(),
		new Dog(),
		new Dog(),
	};
	for (size_t i = 0; i < size; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
}

void test_7()
{
	std::cout << std::endl << bold_on << "[7] Copy tests" << bold_off << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	Dog copydog;
	copydog = *(Dog *)dog;
	copydog.makeSound();
	Cat copycat = Cat(*(Cat*)cat);
	copycat.makeSound();
	delete dog;
	delete cat;
}

void test_8()
{
	std::cout << std::endl << bold_on << "[1] Wrong types test" << bold_off << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // Shouldn't output a cat sound
	meta->makeSound();
	delete meta;
	delete i;
}

int main()
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	return 0;
}