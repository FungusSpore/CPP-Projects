/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:17:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/22 19:19:27 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
	
int main(void){
	try {
		Bureaucrat bob;
		Bureaucrat john = Bureaucrat("john", 1);
		Bureaucrat roti = Bureaucrat("roti", 150);

		std::cout << bob << std::endl;
		std::cout << john << std::endl;
		std::cout << roti << std::endl;

		// john.incrementGrade();
		// roti.incrementGrade();
		john.decrementGrade();
		roti.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat john3 = Bureaucrat("john", 151);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat john2 = Bureaucrat("john", 0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
