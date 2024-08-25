#include "Bureaucrat.hpp"

struct TestID
{

};

const int MAX_TEST_COUNT = 100;

bool tests[MAX_TEST_COUNT] = {false};
unsigned int testsc = 0;

void rslt_test(bool res)
{
	if (testsc >= sizeof(tests))
	{
		std::cerr << "Test error: MAX_TEST_COUNT reached" << std::endl;
		tests[MAX_TEST_COUNT - 1] = false;
	}
	else
		tests[testsc++] = res;
}

void fail_test()
{
	rslt_test(false);
}

void pass_test()
{
	rslt_test(true);
}

std::ostream& operator<<(std::ostream &out, const TestID& b)
{
	(void)b;
	out << "\n[" << testsc << "]";
	return out;
}

void ctor_test(std::string name, int grade, bool fail_expected)
{
	std::cout << TestID() << "\nBureucrat Constructor Test: " << name << grade << std::endl;
	try
	{
		Bureaucrat bc(name, grade);
		if (fail_expected)
			fail_test();
		else
			pass_test();
	}
	catch(const std::exception& e)
	{
		if (fail_expected)
			pass_test();
		else
			fail_test();
		std::cerr << name << ": " << e.what() << '\n';
	}
}

void ex00_tests()
{
	ctor_test("Taylor", -1, true);
	ctor_test("George", 0, true);
	ctor_test("Gregg", 1, false);
	ctor_test("James", 2, false);
	ctor_test("Micheal", 149, false);
	ctor_test("Rihanna", 150, false);
	ctor_test("Lucy", 151, false);
	ctor_test("Tim", 152, true);

	{

		std::cout << TestID() << "\nTrying to increment grade past allowed value.";
		try
		{
			Bureaucrat bc("Philip", 1);
			std::cout << bc << std::endl;
			bc.incrementGrade();
			fail_test();
		}
		catch(const std::exception& e)
		{
			std::cerr << "incrementing grade past highest possible. " << e.what() << '\n';
			pass_test();
		}
	}
	{
		std::cout << TestID() << "\nTrying to decrement grade past allowed value.";
		try
		{
			Bureaucrat bc("Max", 151);
			std::cout << bc << std::endl;
			bc.decrementGrade();
			fail_test();
		}
		catch(const std::exception& e)
		{
			std::cerr << "decrementing grade past lowest possible. " << e.what() << '\n';
			pass_test();
		}
	}
	{
		std::cout << TestID() << "\nTrying ostream operator<< and copy constructor.";
		Bureaucrat az("Lisa", 15);
		Bureaucrat bc(az);
		std::cout << bc << std::endl;
		std::cout << bc.getName() << ", ";
		std::cout << bc.getGrade() << std::endl;
		pass_test();
	}
}

int main()
{
	ex00_tests();

	bool any_failed = false;
	for (size_t i = 0; i < testsc; i++)
	{
		if (tests[i] == false)
		{
			std::cout << "Test: " << i << ", failed to pass.\n";
			any_failed = true;
		}
	}
	if (any_failed == false)
		std::cout << "All tests passed :)" << std::endl;
}