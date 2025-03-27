/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:44:23 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 19:55:12 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "Garbage.hpp"

Character::Character():name("NPC"), inventory(new AMateria*[INVENTORY_SIZE]){
	std::cout << "Character default contructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++){
		inventory[i] = NULL;
	}
}

Character::Character(std::string name):name(name), inventory(new AMateria*[INVENTORY_SIZE]){
	std::cout << "Character default contructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++){
		inventory[i] = NULL;
		}
}

Character::Character(const Character& other){
	std::cout << "Character copy contructor called" << std::endl;
	this->name = other.name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = other.inventory[i];
}

Character& Character::operator=(const Character& other){
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &other){
		this->name = other.name;
		for (int i = 0; i < INVENTORY_SIZE; i++)
			inventory[i] = other.inventory[i];
	}
	return (*this);
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++){
		if (inventory[i] != NULL)
			delete inventory[i];
		}
	delete[] inventory;
}

std::string const & Character::getName() const{
	return (name);
}

void Character::equip(AMateria* m){
	for(int i = 0; i < INVENTORY_SIZE; i++){
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
	bin.throwRubbish(inventory[idx]);
	inventory[idx] = NULL;

}

void Character::use(int idx, ICharacter& target){
	if (0 > idx || idx > 3)
		return ;
	if (inventory[idx]){
		inventory[idx]->use(target);
	}
}

