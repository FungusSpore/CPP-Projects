#include "PhoneBook.hpp"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <strings.h>
#include <stdlib.h>

void	add(PhoneBook& phunkButt)
{
	std::string input;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	darkest_secret;
	int					phone_no;

	std::cout << "First name: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ;
	first_name = input;

	std::cout << "Last name: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ;
	last_name = input;

	std::cout << "Nickname: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ;
	nickname = input;

	std::cout << "Darkest secret: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ;
	darkest_secret = input;

	std::cout << "Phone number: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ;
	phone_no = atoi(input.c_str());

	phunkButt.addContact(first_name, last_name, nickname, darkest_secret, phone_no);
	if (phunkButt.get_total() < 8)
		phunkButt.set_total(phunkButt.get_total() + 1);
}

void print_space(int i)
{
	for (int j = 0; j < i; j++)
		std::cout << " ";
}

void	string_formater(std::string str)
{
	if (str.length() <= 10)
		print_space(10 - str.length());
	else
	{
		str.erase(9, str.length());
		str.append(".");
	}
	std::cout << str;
}

void search(PhoneBook& phonkButt){
	std::string input;

	if (phonkButt.get_total() == 0)
	{
		std::cout << "phonkButt can't remember any contact stored\n";
		return ;
	}
	std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname\n";
	for (int i = 0; i < phonkButt.get_total(); i++){
		std::cout << "         " << i + 1 << "|";
		string_formater(phonkButt.getContact(i).getFirst());
		std::cout << "|";
		string_formater(phonkButt.getContact(i).getLast());
		std::cout << "|";
		string_formater(phonkButt.getContact(i).getNick());
		std::cout << "\n";
	}
	std::cout << "Choose your contact: ";
	getline(std::cin, input);
	if (std::cin.eof() || input.length() == 0)
	{
		std::cout << "PhonkButt didn't receive nothing will return to main menu\n";
		return ;
	}
	int index = atoi(input.c_str());
	if (index < 1 || index >= phonkButt.get_total())
	{
		std::cout << "PhonkButt is mad and will make you restart\n";
		return ;
	}
	std::cout << "First Name" << phonkButt.getContact(index - 1).getFirst() << "\n";
	std::cout << "Last Name" << phonkButt.getContact(index - 1).getLast() << "\n";
	std::cout << "Nickname" << phonkButt.getContact(index - 1).getNick() << "\n";
	std::cout << "Darkest Secret" << phonkButt.getContact(index - 1).getSecret() << "\n";
	std::cout << "Phone Number" << phonkButt.getContact(index - 1).getPhoneNo() << "\n";
}

int	main(void)
{
	PhoneBook phunkButt = PhoneBook();
	std::string input;

	std::cout << "Welcome to PhonkButt\n\n";
	while (true){
		std::cout << "Please enter the following\n\n";
		std::cout << "ADD: To save a new contact\n";
		std::cout << "SEARCH: To display a specific contact\n";
		std::cout << "EXIT: To exit the program (PhonkButt is senile and will forget everything)\n\n";
		std::cout << "PhunkButt: ";
		input.clear();
		getline(std::cin, input);
		if (std::cin.bad()){
			std::cout << "An error has occurred";
			return (1);
		}
		if (!input.compare("ADD"))
			add(phunkButt);
		else if (!input.compare("SEARCH"))
			search(phunkButt);
		else if (!input.compare("EXIT") || std::cin.eof())
			break ;
		else
			std::cout << "PhunkButt: LEarN To Read.....\n";
	}
	return (0);
}
