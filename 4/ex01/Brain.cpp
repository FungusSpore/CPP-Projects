/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:41:41 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/23 01:50:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain contructor called" << std::endl;
}

Brain::Brain(const Brain& other){
	std::cout << "Brain copy contructor called" << std::endl;
		for (int i = 0; i < 100; i++){
			this->ideas[i] = other.ideas[i];
		}
}

Brain& Brain::operator=(const Brain& other){
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &other){
		for (int i = 0; i < 100; i++){
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdeas(std::string str, int idx){
	if (0 <= idx || idx < 100){
		ideas[idx] = str;
		return ;
	}
	std::cout << "Out of range" << std::endl;
}

const std::string* Brain::getIdeas() const{
	return ideas;
}
