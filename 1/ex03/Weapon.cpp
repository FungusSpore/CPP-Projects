/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:31:53 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:45:51 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type){
	this->setType(type);
}

Weapon::Weapon(const Weapon& other){
	this->type = other.type;
}

Weapon& Weapon::operator=(const Weapon& other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

Weapon::~Weapon(){}

std::string	Weapon::getType(){
	return (type);
}

void				Weapon::setType(std::string type){
	this->type = type;
}
