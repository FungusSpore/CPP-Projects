/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:16:52 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/27 14:41:59 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", P_SIGNING_GRADE, P_EXECUTING_GRADE), _target("undefined"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", P_SIGNING_GRADE, P_EXECUTING_GRADE), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action(void) const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
