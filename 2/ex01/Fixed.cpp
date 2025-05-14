/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:03:07 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/13 17:07:56 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed::Fixed():num(0){
	std::cout << "Default contructor called\n";
}

Fixed::Fixed(const int num){
	std::cout << "Int contructor called\n";
	this->num = num << fracBits;
}

Fixed::Fixed(const float num){
	std::cout << "Float contructor called\n";
	this->num = roundf(num * (1 << fracBits));
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called\n";
	this->num = other.num;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called\n";
	if (this != &other){ 
		this->num = other.num;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Fixed& current){
	os << current.toFloat();
	return (os);
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

float Fixed::toFloat(void) const{
	float result = num;
	return (result / (1 << fracBits));
}

int Fixed::toInt(void) const{
	return (num >> fracBits);
}
