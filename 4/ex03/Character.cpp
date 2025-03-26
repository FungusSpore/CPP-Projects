/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:44:23 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/26 22:22:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():name("NPC"){
	std::cout << "Character default contructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name):name(name){
	std::cout << "Character default contructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other){
	std::cout << "Character copy contructor called" << std::endl;
	this->name = other.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i];
}

Character& Character::operator=(const Character& other){
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &other){
		this->name = other.name;
		for (int i = 0; i < 4; i++)
			inventory[i] = other.inventory[i];
	}
	return (*this);
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
}



std::string const & Character::getName() const{
	return (name);
}

void Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++){
		if (inventory[i] == NULL){
			inventory[i] = m;
			return ;
		}
	}
	std::cout << name 
						<< " has a full inventory must unequip first"
						<< std::endl;
}

void Character::unequip(int idx){
	if (inventory[idx] == NULL){
		std::cout << "inventory slot "
							<< idx	
							<< " is already empty"
							<< std::endl;
		return ;
	}

}

void Character::use(int idx, ICharacter& target);
