/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:15:09 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/27 14:40:19 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", R_SIGNING_GRADE, R_EXECUTING_GRADE), _target("undefined"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", R_SIGNING_GRADE, R_EXECUTING_GRADE), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::action(void) const{
	std::cout << "DRIIIIIIIILLLLLLL" << std::endl;
	if (rand() % 2)
		std::cout << _target << "has been robotomized" << std::endl;
	else
		std::cout << "The robotomy has failed" << std::endl;
}
