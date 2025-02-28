#include "Contact.hpp"

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
	delete this;
}
