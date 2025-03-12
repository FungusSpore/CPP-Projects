/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:34:30 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/12 20:22:10 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl = Harl();
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	idx = -1;

	if (argc != 2){
		std::cout << "./harlFilter <level> or <random string>";
		return (0);
	}

	for (int i = 0; i < 4; i++){
		if (argv[1] == arr[i]){
			idx = i;
			break ;
		}
	}

	switch (idx) {
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break ;
		case 0:
			std::cout << "[ DEBUG ]\n";
			harl.complain("DEBUG");
		case 1:
			std::cout << "[ INFO ]\n";
			harl.complain("INFO");
		case 2:
			std::cout << "[ WARNING ]\n";
			harl.complain("WARNING");
		case 3:
			std::cout << "[ ERROR ]\n";
			harl.complain("ERROR");
	}
}
