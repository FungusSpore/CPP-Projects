/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:05:21 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/08 18:04:59 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(const Zombie& other);
	Zombie& operator=(const Zombie& other);
	~Zombie();
	void	announce(void);
	void	setName(std::string);
	std::string	getName();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
