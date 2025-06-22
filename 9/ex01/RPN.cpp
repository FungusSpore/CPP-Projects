/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:33:34 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/23 00:48:52 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstring>
#include <list>
#include <string>
#include <cstdlib>
#include <iostream>

// spliter
// split all by space

// format
// check if any more than 2 lenght
// check for first 2 being numbers
// then alternating with +-*/ then numbers
// and with special
// if fail throw execption

// print
// using ostream print out based on requirement

void RPN::split(std::string input){
	size_t i;
	for(i = 0; std::isspace(input[i]); i++);
	input.erase(0, i);
	input.erase(input.find_last_not_of(" \n\r\t") + 1);

	size_t found = input.find(" ");

	while (found != std::string::npos){
		this->expression.push_back(input.substr(0, found));
		found = input.find(" ");
		input.erase(0, found);
	}

}

bool RPN::is_formatted(){
	std::list<std::string>::iterator it = this->expression.begin();

	for (; it != this->expression.end(); it++)
		if (it->size() != 1)
			return (false);

	it = this->expression.begin();

	for (size_t i = 0; i < 2; i++)
		if (!std::isdigit(*it++->c_str()))
			return (false);

	bool isOperator = true;
	for (; it != this->expression.end(); it++){
		if (isOperator){
			if (strcmp("+-*/", it->c_str()) != 0)
				return (false);
			isOperator = false;
		}
		else{
			if (!std::isdigit(*it->c_str()))
				return (false);
			isOperator = true;
		}
	}
	if (isOperator) // means it didn't end with a operator
		return (false);
	return (true);
}

void RPN::calculate(){
	const std::string op[4] = {"+", "-", "*", "/"};
	std::list<std::string>::iterator it = this->expression.begin();
	int a = atoi(it++->c_str());
	int b;


	for (; it != this->expression.end(); it++){
		size_t i;
		// get operator
		b = atoi(it++->c_str());
		for (i = 0; i < 4; i++){
			if (*it == op[i])
				break ;
		}
		// calculate value using a and b then assign to a
		switch (i) {
			case 0:
			  a += b;
			  break ;
			case 1:
			  a -= b;
			  break ;
			case 2:
			  a *= b;
			  break ;
			case 3:
			  a /= b;
			  break ;
		}
		// move it get new number assign to b
		// if (it != this->expression.end())
		// loop
	}
	result = a;
}

RPN::RPN(){}

RPN::RPN(std::string input){
	split(input);
	if (!is_formatted())
		throw GeneralError("Error");
	calculate();
}

RPN::RPN(const RPN& other):expression(other.expression), result(other.result){}

RPN& RPN::operator=(const RPN& other){
	if (this != &other){
		this->expression = other.expression;
		this->result = other.result;
	}
	return (*this);
}

RPN::~RPN(){}

int RPN::getResult() const{ return this->result; };

std::ostream &operator<<(std::ostream& os, const RPN& current){
	os << current.getResult();
	return (os);
}


RPN::GeneralError::GeneralError(const std::string msg):msg(msg){}
const char* RPN::GeneralError::what() const throw(){ return this->msg.c_str(); }
RPN::GeneralError::~GeneralError() throw(){}
