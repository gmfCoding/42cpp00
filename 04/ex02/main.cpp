#include "AAnimal.hpp"
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
	//const Animal* meta = new Animal(); // No Longer allowed
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//meta->makeSound();// No Longer allowed
	//delete meta;
	delete i;
	delete j;
}

void test_2()
{
	std::cout << std::endl << bold_on << "[2] Specific/Self pointer type test" << bold_off << std::endl;
	//const Animal* meta = new Animal(); // No Longer allowed
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//meta->makeSound();// No Longer allowed
	//delete meta;// No Longer allowed
	delete i;
	delete j;
}

void test_3()
{
	std::cout << std::endl << bold_on << "[3] Static test" << bold_off << std::endl;
	//const Animal meta = Animal(); // No Longer allowed
	const Dog j = Dog();
	const Cat i = Cat();
	std::cout << j.getType() << " " << std::endl;
	std::cout << i.getType() << " " << std::endl;
	i.makeSound(); //will output the cat sound!
	j.makeSound();
	//meta.makeSound(); // No Longer allowed
}

void test_4()
{
	std::cout << std::endl << bold_on << "[4] Repeated invokation type test" << bold_off << std::endl;
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

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
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	const AAnimal* dog_del = dog;
	const AAnimal* cat_del = cat;
	delete dog_del;
	delete cat_del;
}

void test_6()
{
	std::cout << std::endl << bold_on << "[6] Polymorphic Array test" << bold_off << std::endl;
	const int size = 7;
	const AAnimal* animals[size] = {
		new Dog(),
		new Cat(),
		//new Animal(), No longer allowed
		new Dog(), // It will be a dog instead!
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
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	Dog copydog;
	copydog = *dog;
	copydog.makeSound();
	Cat copycat = Cat(*cat);
	copycat.makeSound();
	delete dog;
	delete cat;
}

void test_8()
{
	std::cout << std::endl << bold_on << "[8] Wrong types test" << bold_off << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // Shouldn't output a cat sound
	meta->makeSound();
	delete meta;
	delete i;
}

void test_9()
{
	std::cout << std::endl << bold_on << "[9] Deep copy test" << bold_off << std::endl;
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
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	test_9();
	return 0;
}