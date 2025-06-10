/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:05:41 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/08 16:37:50 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base::Base(){}

Base::~Base(){}

A::A(){
	std::cout << "contructed A" << std::endl;
}

B::B(){
	std::cout << "contructed B" << std::endl;
}

C::C(){
	std::cout << "contructed C" << std::endl;
}

Base* generate(void){
	Base* result;	
	int type = rand() % 3;

	switch (type){
		case 0:
			result = new A();
			break;
		case 1:
			result = new B();
			break;
		case 2:
			result = new C();
			break;
		default:
			std::cout << "Error generating" << std::endl;
			return (NULL);
	}
	return (result);
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Not any of the derieved classes" << std::endl;
}

void	identify(Base& p){
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (const std::exception& e ){}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (const std::exception& e ){}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (const std::exception& e ){}

	std::cout << "Not any of the derieved classes" << std::endl;
}
