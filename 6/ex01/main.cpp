/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:05:35 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/06 14:40:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void){
	Data data;
	uintptr_t seriliazed_data = Serializer::serialize(&data);

	std::cout << &data << std::endl;
	std::cout << seriliazed_data << std::endl;
	std::cout << Serializer::deserialize(seriliazed_data) << std::endl;
}
