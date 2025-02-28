#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <strings.h>
#include <stdlib.h>

void	add(PhoneBook& phunkButt)
{
	std::string input;

	std::cout << "First name: ";
	getline(std::cin, input);
	std::string first_name = input;

	std::cout << "Last name: ";
	getline(std::cin, input);
	std::string last_name = input;

	std::cout << "Nickname: ";
	getline(std::cin, input);
	std::string nickname = input;

	std::cout << "Darkest secret name: ";
	getline(std::cin, input);
	std::string darkest_secret = input;

	std::cout << "Phone number: ";
	getline(std::cin, input);
	int phone_no = atoi(input.c_str());

	phunkButt.addContact(first_name, last_name, nickname, darkest_secret, phone_no);
	if (phunkButt.total_contact < 8)
		phunkButt.total_contact++;
}

void	string_checker(std::string& str)
{
	if (str.length() <= 10)
		str.insert(0, 10 - str.length(), ' ');
	else
	{
		str.erase(9, str.length());
		str.append(".");
	}
	std::cout << str;
}

void search(PhoneBook& phonkButt){
	if (phonkButt.total_contact == 0)
	{
		std::cout << "phonkButt can't remember any contact stored\n";
		return ;
	}
	std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname\n";
	for (int i = 0; i < phonkButt.total_contact; i++){
		std::string first_name = phonkButt.contacts[i].first_name;
		std::string last_name = phonkButt.contacts[i].last_name;
		std::string nickname= phonkButt.contacts[i].nickname;
		std::cout << "         " << i << "|";
		string_checker(first_name);
		std::cout << "|";
		string_checker(last_name);
		std::cout << "|";
		string_checker(nickname);
		std::cout << "\n";
	}
	std::string input;
	getline(std::cin, input);
	int index = atoi(input.c_str());
	if (index < 0 || index > phonkButt.total_contact)
	{
		std::cout << "PhonkButt is mad and will make you restart\n";
		return ;
	}
	std::cout << phonkButt.contacts[index].first_name << "\n";
	std::cout << phonkButt.contacts[index].last_name << "\n";
	std::cout << phonkButt.contacts[index].nickname << "\n";
	std::cout << phonkButt.contacts[index].darkest_secret << "\n";
	std::cout << phonkButt.contacts[index].phone_number << "\n";
}

int	main(void)
{
	PhoneBook phunkButt = PhoneBook();
	std::string input;

	std::cout << "Welcome to PhonkButt\n";
	std::cout << "Please enter the following\n";
	std::cout << "ADD: To save a new contact\n";
	std::cout << "SEARCH: To display a specific contact\n";
	std::cout << "EXIT: To exit the program (PhonkButt is senile and will forget everything)\n";
	while (true)
	{
		getline(std::cin, input);
		// for (int i = 0; i < input.length(); i++){
		// 	toupper(input.);
		// }
		if (input.compare("ADD"))
			add(phunkButt);
		else if (input.compare("SEARCH"))
			search(phunkButt);
		else if (input.compare("EXIT"))
			break ;
	}
}
