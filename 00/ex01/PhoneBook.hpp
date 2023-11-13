#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <string>
# include "Contact.hpp"

# ifndef MAX_CONTACTS
#  define MAX_CONTACTS 8
# endif
class PhoneBook
{
	Contact	contacts[MAX_CONTACTS];
	int		used;
	int		newest;
	public:

	PhoneBook();	
	void	Add(Contact contact);


	void	PromptControl();
	void	PromptAdd();
	void	PromptSearch();
};
#endif
