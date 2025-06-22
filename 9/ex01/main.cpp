/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:30:12 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/23 00:42:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv){
	if (argc != 2){
		std::cerr << "Wrong Input" << std::endl;
		return (1);
	}
	RPN expr(argv[1]);
	std::cout << expr << std::endl;
	return (0);
}
