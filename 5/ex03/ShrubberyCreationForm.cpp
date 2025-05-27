/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:03:39 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/23 23:30:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", S_SIGNING_GRADE, S_EXECUTING_GRADE), _target("undefined"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", S_SIGNING_GRADE, S_EXECUTING_GRADE), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


void ShrubberyCreationForm::action(void) const{
	std::ofstream file1((_target + "_shrubbery").c_str(), std::ios::out);
	if (!file1.is_open())
		std::cout << "Error opening file" << std::endl;
	file1 << 
		"   /@@__@__@@\\\n"
		"  (  o     o  )\n"
		" (      ^      )\n"
		"(~~^~~~~~^~~~^~~)\n"
		"       | |\n"
		".*.Y.!.(_)..!..Y%*.\n\n";
	file1.close();
}
