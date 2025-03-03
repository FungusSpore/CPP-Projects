#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <stddef.h>
# include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	int					phone_number;
public:

	Contact();
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);
	~Contact();
	void setFirst(std::string first_name);
	std::string getFirst();
	void setLast(std::string last_name);
	std::string getLast();
	void setNick(std::string nickname);
	std::string getNick();
	void setSecret(std::string darkest_secret);
	std::string getSecret();
	void setPhoneNo(int phone_number);
	int getPhoneNo();
};

#endif // !CONTACT_HPP
