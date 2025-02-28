#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>

PhoneBook::PhoneBook(){
	explicit_bzero(PhoneBook::contacts, sizeof(Contact) * MAX_CONTACT);
	PhoneBook:: current_contact = 0;
	PhoneBook::total_contact = 0;
}

PhoneBook::PhoneBook(const PhoneBook& other){
	for (int i = 0; i < MAX_CONTACT; i++){
		this->contacts[i] = other.contacts[i];
	}
	this->current_contact = other.current_contact;
	this->total_contact = other.total_contact;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other){
	if (this != &other){
		for (int i = 0; i < MAX_CONTACT; i++){
			this->contacts[i] = other.contacts[i];
		}
		this->current_contact = other.current_contact;
		this->total_contact = other.total_contact;
	}
	return (*this);
}

PhoneBook::~PhoneBook(){
	delete (this);
}

void PhoneBook::addContact(
 std::string first_name,
 std::string last_name,
 std::string nickname,
 std::string darkest_secret,
 int phone_no
){
	int	array_idx = PhoneBook::current_contact % MAX_CONTACT;
	PhoneBook::contacts[array_idx].first_name = first_name;
	PhoneBook::contacts[array_idx].last_name = last_name;
	PhoneBook::contacts[array_idx].nickname = nickname;
	PhoneBook::contacts[array_idx].darkest_secret = darkest_secret;
	PhoneBook::contacts[array_idx].phone_number = phone_no;
}

Contact	*PhoneBook::getContact(){
	return PhoneBook::contacts;
}
