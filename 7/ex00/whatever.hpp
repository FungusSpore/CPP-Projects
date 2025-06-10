/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:41:47 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/08 17:54:45 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T> 
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
 T& min( T& x,  T& y){
	if (x >= y)
		return y;
	return x;
}

template <typename T>
 T& max( T& x,  T& y){
	if (x <= y)
		return y;
	return x;
}

#endif // !WHATEVER_HPP
