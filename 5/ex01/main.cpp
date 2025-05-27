/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:17:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/22 20:38:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
	
int main(void){
	try {
		Bureaucrat level1baby = Bureaucrat("baby", 150);
		Bureaucrat mafiaBoss = Bureaucrat("boss", 1);

		Form basic;
		Form expert = Form("expert", 1, 1);
		Form noob = Form("noob", 150, 150);

		std::cout << basic << std::endl;
		std::cout << expert << std::endl;
		std::cout << noob << std::endl;
		
		std::cout << "==================" << std::endl;

		level1baby.signForm(basic);
		level1baby.signForm(expert);
		level1baby.signForm(noob);

		std::cout << "==================" << std::endl;

		mafiaBoss.signForm(basic);
		mafiaBoss.signForm(expert);
		mafiaBoss.signForm(noob);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "==================" << std::endl;
		// std::cout << "test 1" << std::endl;
		Form tooHigh = Form("too high", 151, 151);
		// std::cout << "if print first means destrcution out of scope" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "==================" << std::endl;
		Form tooLow = Form("too low", 0, 0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
