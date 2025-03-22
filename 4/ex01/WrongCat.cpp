/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:46:43 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/22 15:06:15 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat"){
	std::cout << "WrongCat contructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other):WrongAnimal(other){
	std::cout << "WrongCat copy contructor called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &other){
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat says weom" << std::endl;
}
