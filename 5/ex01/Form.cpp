/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:40:36 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/22 20:36:54 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <ostream>

Form::Form():_name("undefined"), _gradeToSign(75), _gradeToExecute(75), _formSigned(false){}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _formSigned(false){
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException("Your grade requirements are too low");
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException("Your grade requirements are too high");
}

Form::Form(const Form& other):_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _formSigned(other._formSigned){}

Form& Form::operator=(const Form& other){
	if (this != &other){
		_formSigned = other._formSigned;
	}
	return (*this);
}

Form::~Form(){
	// std::cout << "will it call destructor if exception thrown during contruction" << std::endl;
}

std::string Form::getName() const{
	return (_name);
}

int Form::getGradeToSign() const{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const{
	return (_gradeToExecute);
}

bool	Form::getFormSigned() const{
	return (_formSigned);
}

void	Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooHighException("Your Grade is too low to sign this form");
	_formSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const char* msg):message(msg){}
const char* Form::GradeTooHighException::what() const throw(){
	return (message.c_str());
}
Form::GradeTooHighException::~GradeTooHighException() throw(){}

Form::GradeTooLowException::GradeTooLowException(const char* msg):message(msg){}
const char* Form::GradeTooLowException::what() const throw(){
	return (message.c_str());
}
Form::GradeTooLowException::~GradeTooLowException() throw(){}

std::ostream &operator<<(std::ostream &os, const Form& current){
	os << "This Form is called " << current.getName()
		 << ", its required grade to sign is " << current.getGradeToSign()
		 << ", its required grade to execute is " << current.getGradeToExecute()
		 << ", is it currently signed " << (current.getFormSigned() ? "True" : "False")
		 << std::endl;
	return (os);
}
