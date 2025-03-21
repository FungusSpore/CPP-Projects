/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:05:02 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/21 18:48:42 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string name);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();
	std::string getType();
};

#endif
