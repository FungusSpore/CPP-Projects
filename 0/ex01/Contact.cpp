#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact():phone_number(0){}

Contact::Contact(const Contact& other){
	first_name = other.first_name;
	last_name = other.last_name;
	nickname = other.nickname;
	darkest_secret = other.darkest_secret;
	phone_number = other.phone_number;
}

Contact& Contact::operator=(const Contact& other){
	if (this != &other){
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->nickname = other.nickname;
	this->darkest_secret = other.darkest_secret;
	this->phone_number = other.phone_number;
	}
	return (*this);
}

Contact::~Contact(){
	// delete this;
}

void Contact::setFirst(std::string first_name){
	this->first_name = first_name;
}

std::string Contact::getFirst(){
	return (this->first_name);
}

void Contact::setLast(std::string last_name){
	this->last_name = last_name;
}

std::string Contact::getLast(){
	return (this->last_name);
}

void Contact::setNick(std::string nickname){
	this->nickname = nickname;
}

std::string Contact::getNick(){
	return (this->nickname);
}

void Contact::setSecret(std::string darkest_secret){
	this->darkest_secret = darkest_secret;
}

std::string Contact::getSecret(){
	return (this->darkest_secret);
}

void Contact::setPhoneNo(int phone_number){
	this->phone_number = phone_number;
}

int Contact::getPhoneNo(){
	return (this->phone_number);
}
