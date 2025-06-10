/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */ /*   Fixed.cpp                                          :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:03:07 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/16 02:04:13 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

// contructor
Fixed::Fixed():num(0){
	// std::cout << "Default contructor called\n";
}

Fixed::Fixed(const int num){
	// std::cout << "Int contructor called\n";
	this->num = num << fracBits;
}

Fixed::Fixed(const float num){
	// std::cout << "Float contructor called\n";
	this->num = roundf(num * (1 << fracBits));
}

Fixed::Fixed(const Fixed& other){
	// std::cout << "Copy constructor called\n";
	this->num = other.num;
}

Fixed& Fixed::operator=(const Fixed& other){
	// std::cout << "Copy assignment operator called\n";
	if (this != &other){ 
		this->num = other.num;
	}
	return (*this);
}

// Destructor
Fixed::~Fixed(){
	// std::cout << "Destructor called\n";
}

std::ostream& operator<<(std::ostream &os, const Fixed& current){
	os << current.toFloat();
	return (os);
}

// Comparison operators
bool Fixed::operator>(const Fixed& other){
	if (this->num > other.num)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other){
	if (this->num < other.num)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other){
	if (this->num >= other.num)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other){
	if (this->num <= other.num)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other){
	if (this->num == other.num)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& other){
	if (this->num != other.num)
		return (true);
	return (false);
}

// Maths
Fixed Fixed::operator+(const Fixed& other){
	Fixed temp;
	temp.num = this->num + other.num;
	return (temp);
}

Fixed Fixed::operator-(const Fixed& other){
	Fixed temp;
	temp.num = this->num - other.num;
	return (temp);
}

Fixed Fixed::operator*(const Fixed& other){
	Fixed temp;
	temp.num = (this->num * other.num) >> fracBits;
	return (temp);
}

Fixed Fixed::operator/(const Fixed& other){
	Fixed temp;
	temp.num = (this->num << fracBits) / other.num;
	return (temp);
}

//pre
Fixed& Fixed::operator++(){
	this->num += 1;
	return (*this);
}

Fixed& Fixed::operator--(){
	this->num -= 1;
	return (*this);
}

//post
Fixed	 Fixed::operator++(int){
	Fixed	temp = *this;
	this->num += 1;
	return (temp);
}

Fixed	 Fixed::operator--(int){
	Fixed	temp = *this;
	this->num -= 1;
	return (temp);
}

// ex00
int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (num);
}

void Fixed::setRawBits(int const raw){
	this->num = raw;
}

//ex01
float Fixed::toFloat(void) const{
	float result = num;
	return (result / (1 << fracBits));
}

int Fixed::toInt(void) const{
	return (num >> fracBits);
}

//ex02
Fixed& Fixed::min(Fixed& x, Fixed& y){
	if (x.num < y.num)
		return (x);
	return (y);
}

const Fixed& Fixed::min(const Fixed& x, const Fixed& y){
	if (x.num < y.num)
		return (x);
	return (y);
}

Fixed& Fixed::max(Fixed& x, Fixed& y){
	if (x.num < y.num)
		return (y);
	return (x);
}

const Fixed& Fixed::max(const Fixed& x, const Fixed& y){
	if (x.num < y.num)
		return (y);
	return (x);
}
