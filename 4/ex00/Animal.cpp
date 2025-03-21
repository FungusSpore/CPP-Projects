/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:46:55 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/21 18:52:06 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():type("Monster"){
	std::cout << "Animal contructor called" << std::endl;
}

Animal::Animal(std::string name):type(name){
	std::cout << "Animal contructor called" << std::endl;
}

Animal::Animal(const Animal& other){
	std::cout << "Animal copy contructor called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(){
	return (type);
}
