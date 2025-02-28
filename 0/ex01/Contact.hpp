#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <stddef.h>
# include <string>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		int					phone_number;

		Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();
};

#endif // !CONTACT_HPP
