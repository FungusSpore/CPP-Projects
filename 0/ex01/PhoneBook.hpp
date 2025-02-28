#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook{
public:
	Contact contacts[MAX_CONTACT];
	int	current_contact;
	int	total_contact;

	PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook& operator=(const PhoneBook& other);
	~PhoneBook();
	void addContact
	(std::string first_name,
	 std::string last_name,
	 std::string nickname,
	 std::string darkest_secret,
	 int phone_no);
	Contact *getContact();
};

#endif // !CONTACT_HPP
