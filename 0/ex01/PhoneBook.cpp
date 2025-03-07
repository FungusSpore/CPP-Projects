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
	// delete (this);
}

void PhoneBook::addContact(
 std::string first_name,
 std::string last_name,
 std::string nickname,
 std::string darkest_secret,
 int phone_no
){
	int	array_idx = PhoneBook::current_contact % MAX_CONTACT;
	PhoneBook::contacts[array_idx].setFirst(first_name);
	PhoneBook::contacts[array_idx].setLast(last_name);
	PhoneBook::contacts[array_idx].setNick(nickname);
	PhoneBook::contacts[array_idx].setSecret(darkest_secret);
	PhoneBook::contacts[array_idx].setPhoneNo(phone_no);
	PhoneBook::current_contact++;
}

Contact	PhoneBook::getContact(int idx){
	return PhoneBook::contacts[idx];
}

void	PhoneBook::set_current(int current_idx){
	this->current_contact = current_idx;
}

int		PhoneBook::get_current(){
	return (this->current_contact);
}
void	PhoneBook::set_total(int total){
	this->total_contact = total;
}
int		PhoneBook::get_total(){
	return (this->total_contact);
}
