/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:03:07 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/13 14:43:48 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():num(0){
	std::cout << "Default contructor called\n";
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called\n";
	this->num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called\n";
	if (this != &other){
		this->num = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (num);
}

void Fixed::setRawBits(int const raw){
	this->num = raw;
}
