/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:07:54 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/21 13:55:36 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap default contructor called" << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(100);
	this->set_attackDamage(30);
}

FragTrap::FragTrap(std::string name):ClapTrap(name){
	std::cout << "FragTrap default contructor called" << std::endl;
	this->set_hitPoints(100);
	this->set_energyPoints(100);
	this->set_attackDamage(30);
}

FragTrap::FragTrap(const FragTrap& other):ClapTrap(other){
	std::cout << "FragTrap copy contructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap copy assignment called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "YOOO High Five Guys" << std::endl;
}

