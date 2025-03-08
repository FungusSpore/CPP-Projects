/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:30:04 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:45:47 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string type);
	Weapon(const Weapon& other);
	Weapon& operator=(const Weapon& other);
	~Weapon();
	std::string	getType();
	void				setType(std::string type);
};

#endif
