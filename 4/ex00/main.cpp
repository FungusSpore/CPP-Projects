/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:43:53 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/22 16:13:25 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* z = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << z->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); // willl output the dog sound!
	meta->makeSound(); // default sound
	z->makeSound(); //will output the cat sound!
	h->makeSound(); // willl output the dog sound!
	/*...*/
	return 0;
}
