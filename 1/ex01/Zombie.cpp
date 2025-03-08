/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:44:49 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:07:55 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(const Zombie& other){
	this->name = other.name;
}

Zombie& Zombie::operator=(const Zombie& other){
	if (this != &other)
		this->name = other.name;
	return (*this);
}

Zombie::~Zombie(){
	std::cout << name << " has been killed\n";
	/*delete (this);*/
}

void Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name){
	this->name = name;
}

std::string	Zombie::getName(){
	return (name);
}
