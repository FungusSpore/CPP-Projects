/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:53:14 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/22 15:01:44 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal("Dog"){
	std::cout << "Dog contructor called" << std::endl;
}

Dog::Dog(const Dog& other):Animal(other){
	std::cout << "Dog copy contructor called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other){
std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Dog says bark" << std::endl;
}
