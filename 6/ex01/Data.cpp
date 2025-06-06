/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:47:15 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/06 14:39:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data():data1(0), data2(0), data3(0), data4(0){}
Data::Data(const Data& other):data1(other.data1),data2(other.data2),data3(other.data3),data4(other.data4){}
Data& Data::operator=(const Data& other){
	if (this != &other){
		data1 = other.data1;
		data2 = other.data2;
		data3 = other.data3;
		data4 = other.data4;
	}
	return (*this);
}

Data::~Data(){}
