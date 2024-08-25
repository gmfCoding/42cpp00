#include "Bureaucrat.hpp"

void test(std::string name, int grade)
{
    try
    {
        Bureaucrat bc(name, grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << name << ": " << e.what() << '\n';
    }
}

void ex00_tests()
{
    test("Taylor", -1); 
    test("George", 0); 
    test("Gregg", 1);
    test("James", 2); 
    test("Micheal", 149); 
    test("Rihanna", 150); 
    test("Lucy", 151); 
    test("Tim", 152);
    {
        try
        {
            Bureaucrat bc("Philip", 1);
            std::cout << bc << std::endl;
            bc.incrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << "incrementing grade past highest possible. " << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat bc("Max", 151);
            std::cout << bc << std::endl;
            bc.decrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << "derementing grade past lowest possible. " << e.what() << '\n';
        }
    }
    {
        Bureaucrat az("Lisa", 15);
        Bureaucrat bc(az);
        std::cout << bc << std::endl;
        std::cout << bc.getName() << ", ";
        std::cout << bc.getGrade() << std::endl;
    }
}

#include "AForm.hpp"

void ex01_test_abstract_instance()
{
	// std::cout << "\aForm signing test.\n";

    // AForm form("Minimum Wage Increase", 50, 30);
    // std::cout << "\nTrying an in-experienced bureucrat.\n";
    // try
    // {
    //     Bureaucrat beginner("Michael", 100);
    //     // Should throw Form::GradeToLowException
    //     form.beSigned(beginner);
    // }
    // catch(const std::exception& e)
    // { std::cerr << e.what() << '\n'; }
    
    // std::cout << "\nTrying an experienced bureucrat instead.\n";
    // try
    // {
    //     Bureaucrat experienced("Michael", 20);
    //     // Shouldn't throw..
    //     form.beSigned(experienced);
    // }
    // catch(const std::exception& e)
    // { std::cerr << e.what() << '\n'; }
}

void ex01_tests()
{
	ex01_test_abstract_instance();
	
}

int main()
{
    //ex00_tests();    
    ex01_tests();
}