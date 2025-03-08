/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:34:43 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:49:25 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon			weapon;
	std::string	name;

public:
	HumanA();
	HumanA(std::string name, Weapon weapon);
	HumanA(const HumanA& other);
	HumanA& operator=(const HumanA& other);
	~HumanA();
	void	attack();
};

#endif
