/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:37:25 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	defaultDiamond;
	std::cout << std::endl;
	DiamondTrap	Diamond("Diamond");
	std::cout << std::endl;
	DiamondTrap	copyDiamond(Diamond);
	std::cout << std::endl;
	DiamondTrap	imposterDiamond("Imposter");
	std::cout << std::endl;
	imposterDiamond = Diamond;
	std::cout << std::endl;

	std::cout << defaultDiamond.get_name() << std::endl;
	std::cout << defaultDiamond.get_hitPoint() << std::endl;
	std::cout << defaultDiamond.get_energyPoint() << std::endl;
	std::cout << defaultDiamond.get_attackDamage() << std::endl << std::endl;

	std::cout << Diamond.get_name() << std::endl;
	std::cout << Diamond.get_hitPoint() << std::endl;
	std::cout << Diamond.get_energyPoint() << std::endl;
	std::cout << Diamond.get_attackDamage() << std::endl << std::endl;

	std::cout << copyDiamond.get_name() << std::endl;
	std::cout << copyDiamond.get_hitPoint() << std::endl;
	std::cout << copyDiamond.get_energyPoint() << std::endl;
	std::cout << copyDiamond.get_attackDamage() << std::endl << std::endl;

	std::cout << imposterDiamond.get_name() << std::endl;
	std::cout << imposterDiamond.get_hitPoint() << std::endl;
	std::cout << imposterDiamond.get_energyPoint() << std::endl;
	std::cout << imposterDiamond.get_attackDamage() << std::endl << std::endl;

	defaultDiamond.attack("Diamond");
	imposterDiamond.takeDamage(20);
	imposterDiamond.beRepaired(1);
	copyDiamond.takeDamage(1);
	std::cout << copyDiamond.get_hitPoint() << std::endl;
	std::cout << copyDiamond.get_energyPoint() << std::endl;
	copyDiamond.beRepaired(1);
	std::cout << copyDiamond.get_hitPoint() << std::endl;
	std::cout << copyDiamond.get_energyPoint() << std::endl << std::endl;
	defaultDiamond.whoAmI();
	Diamond.whoAmI();
	copyDiamond.whoAmI();
	imposterDiamond.whoAmI();
}
