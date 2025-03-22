/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:46:55 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/22 16:12:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Weird Monster"){
	std::cout << "WrongAnimal contructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name):type(name){
	std::cout << "WrongAnimal contructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	std::cout << "WrongAnimal copy contructor called" << std::endl;
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
	return (type);
}

void WrongAnimal::makeSound() const{
	std::cout << "Random weird animal noises" << std::endl;
}
