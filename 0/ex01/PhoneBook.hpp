#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook{
private:
	Contact contacts[MAX_CONTACT];
	int	current_contact;
	int	total_contact;
public:
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
	Contact	getContact(int idx);
	void	set_current(int current_idx);
	int		get_current();
	void	set_total(int total);
	int		get_total();
};

#endif // !CONTACT_HPP
