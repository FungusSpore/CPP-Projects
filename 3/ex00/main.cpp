/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:37:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 15:44:55 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
	ClapTrap a;
	ClapTrap b("Bob");
	ClapTrap c(b);

	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("a");
	a.takeDamage(1);
	b.attack("c");
	c.beRepaired(10);
	b.beRepaired(10);
}
