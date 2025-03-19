/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:18:11 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 00:46:53 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"
# include <cmath>

class Point
{
private:
	Fixed x;
	Fixed y;

public:
	Point();
	Point(Fixed x, Fixed y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
