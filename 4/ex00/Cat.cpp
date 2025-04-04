/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:46:43 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/22 15:01:59 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat():Animal("Cat"){
	std::cout << "Cat contructor called" << std::endl;
}

Cat::Cat(const Cat& other):Animal(other){
	std::cout << "Cat copy contructor called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other){
std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Cat says meow" << std::endl;
}
