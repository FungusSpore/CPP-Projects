/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:01:18 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:14:59 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	Zombie *horde = zombieHorde(10, "John Does");

	for (int i = 0; i < 10; i++){
		horde[i].announce();
	}
	delete[] (horde);
}
