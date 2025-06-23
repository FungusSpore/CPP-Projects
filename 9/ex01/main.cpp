/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:30:12 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/23 16:13:24 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv){
	try{
		if (argc != 2){
			std::cerr << "Wrong Input" << std::endl;
			return (1);
		}
		RPN expr(argv[1]);
		std::cout << expr << std::endl;
		// std::cout << 
		// 2 * 2 * 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 *
		// 2 * 2 * 2 << std::endl;
		return (0);
	}catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
