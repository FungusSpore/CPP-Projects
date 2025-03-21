/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:37:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/21 16:21:58 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void){
	FragTrap	defaultFrag;
	FragTrap	Frag("Frag");
	FragTrap	copyFrag(Frag);
	FragTrap	imposterFrag("Imposter");
	imposterFrag = Frag;

	std::cout << defaultFrag.get_name() << std::endl;
	std::cout << defaultFrag.get_hitPoint() << std::endl;
	std::cout << defaultFrag.get_energyPoint() << std::endl;
	std::cout << defaultFrag.get_attackDamage() << std::endl << std::endl;

	std::cout << Frag.get_name() << std::endl;
	std::cout << Frag.get_hitPoint() << std::endl;
	std::cout << Frag.get_energyPoint() << std::endl;
	std::cout << Frag.get_attackDamage() << std::endl << std::endl;

	std::cout << copyFrag.get_name() << std::endl;
	std::cout << copyFrag.get_hitPoint() << std::endl;
	std::cout << copyFrag.get_energyPoint() << std::endl;
	std::cout << copyFrag.get_attackDamage() << std::endl << std::endl;

	std::cout << imposterFrag.get_name() << std::endl;
	std::cout << imposterFrag.get_hitPoint() << std::endl;
	std::cout << imposterFrag.get_energyPoint() << std::endl;
	std::cout << imposterFrag.get_attackDamage() << std::endl << std::endl;

	defaultFrag.attack("Frag");
	imposterFrag.takeDamage(20);
	imposterFrag.beRepaired(1);
	copyFrag.takeDamage(1);
	std::cout << copyFrag.get_hitPoint() << std::endl;
	std::cout << copyFrag.get_energyPoint() << std::endl;
	copyFrag.beRepaired(1);
	std::cout << copyFrag.get_hitPoint() << std::endl;
	std::cout << copyFrag.get_energyPoint() << std::endl;
	copyFrag.highFivesGuys();
}
