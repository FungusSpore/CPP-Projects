/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:38:49 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:40:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

 int main()
 {
	{
		 Weapon club = Weapon("crude spiked club");

		 HumanA bob("Bob", club);
		 bob.attack();
		 club.setType("some other type of club");
		 bob.attack();
	}
	{
		 Weapon club = Weapon("crude spiked club");
		 HumanB jim("Jim");
		 jim.setWeapon(club);
		 jim.attack();
		 club.setType("some other type of club");
		 jim.attack();
	}
	return 0; 
}
