/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:09:50 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/16 17:25:27 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <iostream>

Span::Span():_maxSize(0), _size(0){}

Span::Span(unsigned int N): _maxSize(N), _size(0){}

Span::Span(const Span& other):_arr(other._arr), _maxSize(other._maxSize), _size(other._size){}

Span& Span::operator=(const Span& other){
	if (this != &other){
		this->_arr = other._arr;
		this->_maxSize = other._maxSize;
		this->_size = other._size;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int nbr){
	if (this->_maxSize <= this->_size)
		throw MaxSizeReached("This Span has reached its storage limits");
	this->_arr.push_back(nbr);
	this->_size++;
	std::sort(_arr.begin(), _arr.end());
}

int Span::shortestSpan(){
	if (this->_size < 2)
		throw NotEnoughElements("There isn't enough elements to compare");
	return (_arr.at(1) - _arr.at(0));
}

int Span::longestSpan(){
	if (this->_size < 2)
		throw NotEnoughElements("There isn't enough elements to compare");
	return (*--_arr.end() - _arr.at(0));
}


Span::MaxSizeReached::MaxSizeReached(std::string message):msg(message){}
const char* Span::MaxSizeReached::what() const throw(){
	return (this->msg.c_str());
}
Span::MaxSizeReached::~MaxSizeReached() throw(){}

Span::NotEnoughElements::NotEnoughElements(std::string message):msg(message){}
const char* Span::NotEnoughElements::what() const throw(){
	return (this->msg.c_str());
}
Span::NotEnoughElements::~NotEnoughElements() throw(){}

Span::_M_range_insert::_M_range_insert(std::string message):msg(message){}
const char* Span::_M_range_insert::what() const throw(){
	return (this->msg.c_str());
}
Span::_M_range_insert::~_M_range_insert() throw(){}

