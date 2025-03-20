/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:37:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 21:04:28 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ScavTrap a("nerd");
	ScavTrap b(a);
	ClapTrap c("Bob");

	a.guardGate();
	b.guardGate();
	a.beRepaired(10);
	c = a;
	c.takeDamage(1);
	a.attack("c");
	b.attack("c");
	c.attack("c");
	a.attack("c");
	std::cout << c.get_hitPoint() << std::endl;
}
