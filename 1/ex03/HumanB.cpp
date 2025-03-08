/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:48:08 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:55:13 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(){}

HumanB::HumanB(std::string name){
	this->name = name;
}

HumanB::HumanB(std::string name, Weapon weapon){
	this->weapon = weapon;
	this->name = name;
}

HumanB::HumanB(const HumanB& other){
	this->weapon = other.weapon;
	this->name = other.name;
}

HumanB& HumanB::operator=(const HumanB& other){
	if (this != &other){
		this->weapon = other.weapon;
		this->name = other.name;
	}
	return (*this);
}

HumanB::~HumanB(){};

void	HumanB::setWeapon(Weapon weapon){
	this->weapon = weapon;
}

void	HumanB::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
