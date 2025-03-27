/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:20:28 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 14:02:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria("cure"){
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

AMateria* Cure::clone() const{
	AMateria* imposter = new Cure(*this);
	return (imposter);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName()
						<< "'s wounds *"
						<< std::endl;
}
