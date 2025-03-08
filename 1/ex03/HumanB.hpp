/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:48:30 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:54:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon			weapon;
	std::string	name;

public:
	HumanB();
	HumanB(std::string name);
	HumanB(std::string name, Weapon weapon);
	HumanB(const HumanB& other);
	HumanB& operator=(const HumanB& other); ~HumanB();
	void	setWeapon(Weapon weapon);
	void	attack();
};

#endif
