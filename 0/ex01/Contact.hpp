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
		Contact(){

		};
		Contact(char *first_name, char *last_name,
				char *nickname, int	phone_number, char *darkest_secret){
			this->first_name = first_name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->phone_number = phone_number;
			this->darkest_secret = darkest_secret;
		};
		char	*getFirstName() {return (first_name);}
		char	*getLastName() {return (last_name);}
		char	*getNickname() {return (nickname);}
		int		getPhoneNo() {return (phone_number);}
		char	*getDarkestSecret() {return (darkest_secret);}
};

#endif // !CONTACT_HPP
