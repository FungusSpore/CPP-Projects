/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:41:43 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/26 23:29:46 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter{
private:
	std::string name;
	AMateria*	inventory[4];

public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character(){}

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
