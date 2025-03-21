/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:56:10 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/21 16:34:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("DiamondTrap_clap_name"){
	std::cout << "DiamondTrap default contructor called" << std::endl;
	this->name = "DiamondTrap";
	this->set_hitPoints(FragTrap().get_hitPoint());
	this->set_energyPoints(ScavTrap().get_energyPoint());
	this->set_attackDamage(FragTrap().get_attackDamage());
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"){
	std::cout << "DiamondTrap default contructor called" << std::endl;
	this->name = name;
	this->set_hitPoints(FragTrap().get_hitPoint());
	this->set_energyPoints(ScavTrap().get_energyPoint());
	this->set_attackDamage(FragTrap().get_attackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap& other){
	std::cout << "DiamondTrap copy contructor called" << std::endl;
	this->name = other.name;
	this->set_hitPoints(other.get_hitPoint());
	this->set_energyPoints(other.get_energyPoint());
	this->set_attackDamage(other.get_attackDamage());
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	std::cout << "DiamondTrap copy assignment called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << name
						<< "My ClapTrap name is " << this->get_name() << std::endl;
}
