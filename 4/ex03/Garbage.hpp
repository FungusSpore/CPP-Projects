/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Garbage.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:12:47 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 17:38:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_HPP
# define GARBAGE_HPP

#include "AMateria.hpp"

struct Bin{
	AMateria* data;
	Bin* next;
};

# include <iostream>

class Garbage{
protected:
	Bin* head;
public:
	Garbage();
	Garbage(const Garbage& other);
	Garbage& operator=(const Garbage& other);
	~Garbage();

	void throwRubbish(AMateria *data);
};

#endif
