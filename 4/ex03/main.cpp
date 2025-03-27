/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:37:27 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 20:02:55 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	std::cout << "INIT INSTANCES" << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	AMateria* tmp;

	std::cout << "\nEQUIP AMATERIA" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\nEQUIP AMATERIA 2" << std::endl;
	tmp = src->createMateria("ice");
	you->equip(tmp);
	tmp = src->createMateria("cure");
	you->equip(tmp);
	tmp = src->createMateria("ice");
	you->equip(tmp);
	tmp = src->createMateria("cure");
	you->equip(tmp);
	tmp = src->createMateria("ice");
	you->equip(tmp);
	you->unequip(0);
	you->equip(tmp);
	tmp = src->createMateria("cure");
	you->equip(tmp);
	you->unequip(0);
	you->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << "\nUSE AMATERIA" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	you->use(0, *bob);
	you->use(1, *bob);
	you->use(2, *bob);
	you->use(3, *bob);
	you->use(4, *bob);

	me->unequip(0);
	me->unequip(3);

	you->unequip(0);
	you->unequip(1);
	you->unequip(2);
	you->unequip(3);

	delete bob;
	delete me;
	delete you;
	delete src;

	return 0;
}
