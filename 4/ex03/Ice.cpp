/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:39:35 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 14:04:39 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice():AMateria("ice"){
	std::cout << "Ice default contructor called" << std::endl;
}

Ice::Ice(const Ice& other){
	std::cout << "Ice copy contructor called" << std::endl;
	this->type = other.type;
}

Ice& Ice::operator=(const Ice& other){
	std::cout << "Ice copy assignment called" << std::endl;
	if (this != &other){
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}

std::string const & Ice::getType() const{
	return (type);
}

AMateria* Ice::clone() const{
	AMateria* imposter = new Ice(*this);
	return (imposter);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
