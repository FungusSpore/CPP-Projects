/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:53:08 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/27 14:45:57 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 
#include <exception>
#include <ostream>

Bureaucrat::Bureaucrat():name("undefined"), grade(75){}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name){
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException("Your grade is too high");
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException("Your grade is too low");
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name), grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const{
	return (name);
}

int Bureaucrat::getGrade() const{
	return (grade);
}

void	Bureaucrat::incrementGrade(void){
	if (--grade < HIGHEST_GRADE)
		throw GradeTooHighException("Your grade is too high");
	grade--;
}
void	Bureaucrat::decrementGrade(void){
	if (++grade > LOWEST_GRADE)
		throw GradeTooHighException("Your grade is too low");
	grade++;
}

void	Bureaucrat::signForm(AForm& form){
	try{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
		std::cout << name << " executed " << form.getName();
	}
	catch (std::exception& e){
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* msg):message(msg){}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return (message.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* msg):message(msg){}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return (message.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& current){
	os << current.getName() << ", bureaucrat grade " 
		<< current.getGrade() << "." << std::endl;
	return (os);
}

