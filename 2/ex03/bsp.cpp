/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:20:37 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 01:29:59 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point const x, Point const y, Point const z){
	Fixed temp = 
		(((x.getX() * y.getY()) + (y.getX() * z.getY()) + (z.getX() * x.getY())) -
		((x.getY() * y.getX()) + (y.getY() * z.getX()) + (z.getY() * x.getX()))) / 2;
	if (temp < Fixed(0))
		temp = temp * -1;
	return (temp);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed total_area = area(a, b, c);
	Fixed sub_ab = area(a, b, point);
	Fixed sub_bc = area(b, c, point);
	Fixed sub_ca = area(c, a, point);

	if (sub_ab == 0 || sub_bc == 0|| sub_ca == 0)
		return (false);
	else if (sub_ab + sub_bc + sub_ca == total_area)
			return  (true);
	return (false);
}
