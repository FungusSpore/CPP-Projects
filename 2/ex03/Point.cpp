/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:43:39 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 00:47:02 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point():x(0),y(0){}

Point::Point(Fixed x, Fixed y){
	this->x = x;
	this->y = y;
}

Point::Point(const Point& other){
	this->x = other.x;
	this->y = other.y;
}

Point& Point::operator=(const Point& other){
	if (this != &other){
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

Point::~Point(){}

Fixed Point::getX() const{
	return (this->x);
}

Fixed Point::getY() const{
	return (this->y);
}
