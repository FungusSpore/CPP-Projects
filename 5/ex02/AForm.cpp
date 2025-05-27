/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:40:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/23 22:00:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

AForm::AForm():_name("undefined"), _gradeToSign(75), _gradeToExecute(75), _formSigned(false){}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _formSigned(false){
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException("Your grade requirements are too low");
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException("Your grade requirements are too high");
}

AForm::AForm(const AForm& other):_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _formSigned(other._formSigned){}

AForm& AForm::operator=(const AForm& other){
	if (this != &other){
		_formSigned = other._formSigned;
	}
	return (*this);
}

AForm::~AForm(){
	// std::cout << "will it call destructor if exception thrown during contruction" << std::endl;
}

std::string AForm::getName() const{
	return (_name);
}

int AForm::getGradeToSign() const{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const{
	return (_gradeToExecute);
}

bool	AForm::getFormSigned() const{
	return (_formSigned);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException("Your Grade is too low to sign this form");
	_formSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException("Your grade is too low to execute");
	if (!_formSigned)
		throw FromNotSignedException("This from is not signed yet");
	action();
}

AForm::GradeTooHighException::GradeTooHighException(const char* msg):message(msg){}
const char* AForm::GradeTooHighException::what() const throw(){
	return (message.c_str());
}
AForm::GradeTooHighException::~GradeTooHighException() throw(){}

AForm::GradeTooLowException::GradeTooLowException(const char* msg):message(msg){}
const char* AForm::GradeTooLowException::what() const throw(){
	return (message.c_str());
}
AForm::GradeTooLowException::~GradeTooLowException() throw(){}

AForm::FromNotSignedException::FromNotSignedException(const char* msg):message(msg){}
const char* AForm::FromNotSignedException::what() const throw(){
	return (message.c_str());
}
AForm::FromNotSignedException::~FromNotSignedException() throw(){}

std::ostream &operator<<(std::ostream &os, const AForm& current){
	os << "This AForm is called " << current.getName()
		 << ", its required grade to sign is " << current.getGradeToSign()
		 << ", its required grade to execute is " << current.getGradeToExecute()
		 << ", is it currently signed " << (current.getFormSigned() ? "True" : "False")
		 << std::endl;
	return (os);
}
