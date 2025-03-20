/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:07:54 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 22:27:33 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(){
	this->set_hitPoints(100);
	this->set_energyPoints(100);
	this->set_attackDamage(30);
}

FragTrap::FragTrap(std::string name):ClapTrap(name){
	this->set_hitPoints(100);
	this->set_energyPoints(100);
	this->set_attackDamage(30);
}

FragTrap::FragTrap(const FragTrap& other):ClapTrap(other){
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap(){

}

void FragTrap::highFivesGuys(void){
	std::cout << "YOOO High Five Guys" << std::endl;
}

