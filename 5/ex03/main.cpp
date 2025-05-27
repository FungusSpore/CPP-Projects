/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:17:31 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/27 20:22:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <exception>
	
int main(void){
	try {
		Intern Bum = Intern();
		AForm *president = Bum.makeForm("PresidentialPardonForm", "John");
		AForm *robotomy = Bum.makeForm("RobotomyRequestForm", "Robo");
		AForm *shrubbery = Bum.makeForm("ShrubberyCreationForm", "Berry");
		AForm *non_exit = Bum.makeForm("nonExist", "void");
		if (!non_exit)
			std::cout << "nonExist memmang null" <<std::endl;

		Bureaucrat *John = new Bureaucrat("John", 1);
		Bureaucrat *BabyJohn = new Bureaucrat("BabyJohn", 150);

		// before sign
		std::cout <<"\n before sign" << std::endl;
		John->executeForm(*president);
		John->executeForm(*robotomy);
		John->executeForm(*shrubbery);

		BabyJohn->executeForm(*president);
		BabyJohn->executeForm(*robotomy);
		BabyJohn->executeForm(*shrubbery);

		std::cout <<"\n try to sign" << std::endl;
		// Try to sign
		BabyJohn->signForm(*president);
		BabyJohn->signForm(*robotomy);
		BabyJohn->signForm(*shrubbery);

		// Sign
		John->signForm(*president);
		John->signForm(*robotomy);
		John->signForm(*shrubbery);

		// after sign
		std::cout << "\nExecute president form" << std::endl;
		John->executeForm(*president);
		std::cout << "\nExecute robotomy multiple times form" << std::endl;
		John->executeForm(*robotomy);
		John->executeForm(*robotomy);
		John->executeForm(*robotomy);
		std::cout << "\nExecute shrubbery form" << std::endl;
		John->executeForm(*shrubbery);

		std::cout <<"\n baby execute" << std::endl;
		BabyJohn->executeForm(*president);
		BabyJohn->executeForm(*robotomy);
		BabyJohn->executeForm(*shrubbery);

	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}
