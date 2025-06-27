/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:16:00 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/28 01:05:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv){
	try{
		if (argc < 2){
			std::cerr << "Error No Input" << std::endl;
			return (1);
		}

		PmergeMe fj;

		// fj.fill_container(argv);
		fj.sort(argv);
			
		return (0);
	}catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
