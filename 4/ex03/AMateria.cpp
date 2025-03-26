/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:56:35 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/26 14:28:12 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():type("Unknown"){
	std::cout << "AMateria default contructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):type(type){
	std::cout << "AMateria default contructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other){
	std::cout << "AMateria copy contructor called" << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other){
	std::cout << "AMateria copy assignment called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const{
	return (type);
}

void use(ICharacter& target){

}
