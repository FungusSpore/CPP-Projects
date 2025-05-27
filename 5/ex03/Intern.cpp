/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:39:13 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/27 21:51:19 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	if (this != &other){}
}

Intern& Intern::operator=(const Intern& other){
	if (this != &other){}
	return (*this);
}

Intern::~Intern(){}

AForm* createShrubbery(const std::string& target){
	return new ShrubberyCreationForm(target);
}
AForm* createRobotomy(const std::string& target){
	return new RobotomyRequestForm(target);
}
AForm* createPresidential(const std::string& target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target){
	typedef AForm* (*FuncPtr)(const std::string&);
	const int form_no = 3;
	AForm *form;

	FuncPtr funcPtr[form_no] = {createShrubbery, createRobotomy, createPresidential};

	std::string formNames[form_no] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < form_no; i++){
		if (formName == formNames[i]){
			form = funcPtr[i](target);
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
	}
	std::cout << "Intern cannot create what doesn't exist" << std::endl;
	return (NULL);
}
