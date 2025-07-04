/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:27:18 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/27 20:03:42 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource():source(new AMateria*[4]){
	for(int i = 0; i < 4; i++){
		this->source[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other):source(new AMateria*[4]){
	for(int i = 0; i < 4; i++){
		this->source[i] = other.source[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this == &other){
		for(int i = 0; i < 4; i++){
			this->source[i] = other.source[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	std::cout << "Default destructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		if (source[i] != NULL)
			delete source[i];
	}
	delete[] source;
}

void MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; i++){
		if (source[i] == NULL){
			source[i] = materia;
			return ;
		}
	}
	std::cout << "You have learned enough for this lifetime" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (source[i] && source[i]->getType() == type)
			return (source[i]->clone());
	}
	return (0);
}

