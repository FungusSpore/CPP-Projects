/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:16:50 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/09 01:20:07 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << &brain << "\n";
	std::cout << &stringPTR << "\n";
	std::cout << &stringREF << "\n";

	std::cout << brain << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";
}
