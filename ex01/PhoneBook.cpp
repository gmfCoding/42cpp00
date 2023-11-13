#include <cstdlib>
#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"
#include "util.hpp"

using std::string;

PhoneBook::PhoneBook() : used(0), newest(0)
{

}	 

void PhoneBook::Add(Contact contact)
{
	this->contacts[newest] = contact;
	if (used < MAX_CONTACTS)
		used++;
	newest++;
	newest = newest % MAX_CONTACTS;
}

void PhoneBook::PromptControl()
{
	while (1)
	{
		std::cout << "MODE (ADD, SEARCH, EXIT):";
		string str;
		getline(std::cin, str);
		if (!str.compare("ADD"))	
			PromptAdd();
		else if (!str.compare("SEARCH"))
			PromptSearch();
		else if (!str.compare("EXIT"))
			break ;
		else
			std::cout << "Unrecognised Option" << std::endl;
	}
}

void PhoneBook::PromptSearch()
{
	string row(44, '-');
	string colnames[] = {"index", "first name", "lastname", "nickname" };
	
	std::cout << row << std::endl;

	// Print column headers
	for (int i = 0; i < 4; i++)
	{
		print_rowcol("|", colnames[i]);
	}
	std::cout << "|" << std::endl;

	// Print each row
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		Contact contact = this->contacts[i];
		std::ostringstream ss;
		ss << i + 1;
		print_rowcol("|", ss.str());
		print_rowcol("|", contact.GetFirstName());
		print_rowcol("|", contact.GetLastName());
		print_rowcol("|", contact.GetNickName(), "|");
		std::cout << std::endl;
	}
	std::cout << row << std::endl;
	
	// Get an integer from stdin for the index
	char*	p;
	string	input = Prompt("Index:");
	long	index = strtol(input.c_str(), &p, 10);
	if (*p || index <= 0 || index > MAX_CONTACTS)
	{
		if (*p)
			std::cout << "Not a number" << std::endl;
		else
			std::cout << "Out of range (1-" << MAX_CONTACTS << ")" << std::endl;
		return ;
	}
	std::cout << "First name:\t" << contacts[index - 1].GetFirstName() << std::endl;
	std::cout << "Last name:\t" << contacts[index - 1].GetLastName() << std::endl;
	std::cout << "Nickname:\t" << contacts[index - 1].GetNickName() << std::endl;
	std::cout << "Number:\t\t" << contacts[index - 1].GetNumber() << std::endl;
	std::cout << "Secret:\t\t" << contacts[index - 1].GetSecret() << std::endl;
}


void PhoneBook::PromptAdd()
{
	std::cout << "ADDING..." << std::endl;
	string first = Prompt("First name:");
	string last = Prompt("Last name:");
	string nick = Prompt("Nickname:");
	string number = Prompt("Number:");
	string secret = Prompt("Secret:");
	Add(Contact(first, last, nick, number, secret));
}
