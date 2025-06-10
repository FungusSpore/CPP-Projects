/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:07:13 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/10 23:47:34 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <string>
#include <cstdlib>
#include <cstring>

template <typename T>
class Array{
private:
	T *arr;
	unsigned int lenght;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	unsigned int size() const;

	class IndexOutOfBounds : public std::exception{
	private:
		std::string msg;
	public:
		IndexOutOfBounds(const char* msg);
		const	char* what() const throw();
		~IndexOutOfBounds() throw();
	};

};

#include "Array.tpp"

#endif // !ARRAY_HPP
