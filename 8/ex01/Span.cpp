/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:09:50 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/13 23:07:27 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

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
		throw();
	this->_arr.push_back(nbr);
}

int Span::shortestSpan(){
	if (this->_size < 2)
		throw();
	std::sort(_arr.begin(), _arr.end());
	return (_arr.at(1) - _arr.at(0));
}

int Span::longestSpan(){

}
