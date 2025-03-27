/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Garbage.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:23:38 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 18:23:57 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Garbage.hpp"
#include "AMateria.hpp"

Garbage::Garbage(){
	head = NULL;
}

Garbage::Garbage(const Garbage& other){
	this->head = other.head;
}

Garbage& Garbage::operator=(const Garbage& other){
	if (this != &other){
		this->head = other.head;
	}
	return (*this);
}

Garbage::~Garbage(){
	Bin *temp;

	std::cout << "Garbage Collector destructor called" << std::endl;
	while (head){
		delete head->data;
		temp = head->next;
		delete head;
		head = temp;
	}
}

void Garbage::throwRubbish(AMateria *data){
	Bin* node = new Bin;
	node->data = data;
	node->next = head;
	head = node;
}
