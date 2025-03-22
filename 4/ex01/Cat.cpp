/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:46:43 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/23 00:25:46 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat"),brain(new Brain()){
	std::cout << "Cat contructor called" << std::endl;
}

Cat::Cat(const Cat& other):Animal(other), brain(new Brain(*other.brain)){
	std::cout << "Cat copy contructor called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other){
std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const{
	std::cout << "Cat says meow" << std::endl;
}

Brain*	Cat::getBrain() const{
	return (this->brain);
}
