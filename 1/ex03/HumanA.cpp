/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:42:04 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:47:45 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(){}

HumanA::HumanA(std::string name, Weapon weapon){
	this->weapon = weapon;
	this->name = name;
}

HumanA::HumanA(const HumanA& other){
	this->weapon = other.weapon;
	this->name = other.name;
}

HumanA& HumanA::operator=(const HumanA& other){
	if (this != &other){
		this->weapon = other.weapon;
		this->name = other.name;
	}
	return (*this);
}

HumanA::~HumanA(){};

void	HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
