#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	PhoneBook book = PhoneBook();
	book.PromptControl();
}
