/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:00:49 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/17 20:15:46 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>

template <typename T>
MutantStack<T>::iterator::iterator(Pointer ptr):mPtr(ptr){}

template <typename T>
T& MutantStack<T>::iterator::operator*(){
	return (*this->mPtr);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& other){
	return (*this->mPtr != other.mPtr);
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator& other){
	return (*this->mPtr == other.mPtr);
}

//pre
template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++(){
	this->mPtr++;
	return (*this);
}
template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--(){
	this->mPtr--;
	return (*this);
}

//post
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int){
	typename MutantStack<T>::iterator temp = *this;
	this->mPtr--;
	return (temp);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int){
	typename MutantStack<T>::iterator temp = *this;
	this->mPtr++;
	return (temp);
}

template <typename T>
MutantStack<T>::MutantStack():std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other):std::stack<T>(other){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other){
	if (this != &other){
		this->stack = other->stack;
	}
	return (*this);
}
template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return iterator(this->stack);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return iterator(this->stack);
}

