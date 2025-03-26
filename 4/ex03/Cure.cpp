#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria(){
	std::cout << "Cure default contructor called" << std::endl;
}

Cure::Cure(std::string const & type):AMateria(type){
	std::cout << "Cure default contructor called" << std::endl;
}

Cure::Cure(const Cure& other){
	std::cout << "Cure copy contructor called" << std::endl;
	this->type = other.type;
}

Cure& Cure::operator=(const Cure& other){
	std::cout << "Cure copy assignment called" << std::endl;
	if (this != &other){
		AMateria::operator=(other);
	}
	return (*this);
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}

std::string const & Cure::getType() const{
	return (type);
}

Cure* Cure::clone() const{
	Cure* imposter = new Cure(*this);
	return (imposter);
}

void use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target << std::endl;
}
