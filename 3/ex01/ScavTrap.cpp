/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:41 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 21:03:54 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap default contructor called" << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(50);
	this->set_attackDamage(20);
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name){
	std::cout << "ScavTrap default contructor called" << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(50);
	this->set_attackDamage(20);
};

ScavTrap::ScavTrap(const ScavTrap& other):ClapTrap(other){
	std::cout << "ScavTrap copy contructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	std::cout << "ScavTrap copy assignment called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->get_hitPoint() == 0){
		std::cout << "ScavTrap " << this->get_name()
							<< "has already died" << std::endl;
		return ;
	}
	if (this->get_energyPoint() == 0){
		std::cout << "ScavTrap " << this->get_name()
							<< " is exhausted and will not move" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->get_name()
						<< " attacks " << target
						<< ", causing " << this->get_attackDamage()
						<< " points of damage!" << std::endl;
	this->set_energyPoints(this->get_energyPoint() - 1);
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is now guarding a gate" << std::endl;
}
