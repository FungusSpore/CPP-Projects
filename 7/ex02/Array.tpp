/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:59:07 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/11 00:00:38 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array():arr(new T[0]), lenght(0){
}

template <typename T>
Array<T>::Array(unsigned int n):arr(new T[n]()), lenght(n){}

template <typename T>
Array<T>::Array(const Array& other):arr(new T[other.lenght]()), lenght(other.lenght){
	for (unsigned int i = 0; i < other.lenght; i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] (this->arr);
		this->arr = new T[other.lenght]();
		for (unsigned int i = 0; i < other.lenght; i++)
			this->arr[i] = other.arr[i];
		this->lenght = other.lenght;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(){
	delete[] this->arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= this->lenght)
		throw (IndexOutOfBounds("Accessing out of bounds index"));
	return (arr[index]);
}

template <typename T>
unsigned int Array<T>::size() const{
	return (this->lenght);
}

template <typename T>
Array<T>::IndexOutOfBounds::IndexOutOfBounds(const char* msg):msg(msg){}

template <typename T>
const	char* Array<T>::IndexOutOfBounds::what() const throw(){
	return (this->msg.c_str());
}

template <typename T>
Array<T>::IndexOutOfBounds::~IndexOutOfBounds() throw(){}
