/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:53:14 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/23 17:45:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog"), brain(new Brain()){
	std::cout << "Dog contructor called" << std::endl;
}

Dog::Dog(const Dog& other):Animal(other), brain(new Brain(*other.brain)){
	std::cout << "Dog copy contructor called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other){
std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const{
	std::cout << "Dog says bark" << std::endl;
}

Brain*	Dog::getBrain() const{
	return (this->brain);
}
