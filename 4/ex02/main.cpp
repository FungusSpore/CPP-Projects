/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:43:53 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/26 22:04:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	/*const Animal* test = new Animal();*/
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Dog* jeff = new Dog();
	const Dog* imposter_jeff = new Dog(*jeff);

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << jeff->getType() << std::endl;
	std::cout << imposter_jeff->getType() << std::endl;

	jeff->getBrain()->setIdeas("I am hungry", 0);
	std::cout << jeff->getBrain()->getIdeas()[0] << std::endl;
	std::cout << imposter_jeff->getBrain()->getIdeas()[0] << std::endl;

	/*i->makeSound();*/

	delete j;
	delete i;
	delete jeff;
	delete imposter_jeff;

	return (0);
}
