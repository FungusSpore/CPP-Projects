/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:20 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 15:44:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name(""), hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "default contructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "default contructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (this->hit_points == 0){
		std::cout << "ClapTrap " << this->name
							<< "has already died" << std::endl;
		return ;
	}
	if (this->energy_points == 0){
		std::cout << "ClapTrap " << this->name
							<< " is exhausted and will not move" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name
						<< " attacks " << target
						<< ", causing " << this->attack_damage
						<< " points of damage!" << std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hit_points == 0){
		std::cout << "ClapTrap " << this->name
							<< "has already died" << std::endl;
		return ;
	}
	if (this->energy_points == 0){
		std::cout << "ClapTrap " << this->name
							<< " is exhausted and will not move" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name
						<< " has been attacked causing" << amount
						<< " points of damage!" << std::endl;
	this->hit_points -= amount;
	this->energy_points--;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hit_points == 0){
		std::cout << "ClapTrap " << this->name
							<< "has already died" << std::endl;
		return ;
	}
	if (this->energy_points == 0){
		std::cout << "ClapTrap " << this->name
							<< " is exhausted and will not move" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name
						<< " has been healed" << amount
						<< " points of damage!" << std::endl;
	this->hit_points += amount;
	this->energy_points--;
}
