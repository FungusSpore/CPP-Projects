/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:54:56 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/17 16:05:57 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iterator>
#include <stack>


template <typename T>
class MutantStack: public std::stack<T>{
	struct iterator{
		using value_type = T;	
		using Pointer = T*;
		using Reference = T&;

		iterator(Pointer ptr);

		T& operator*();

		bool operator!=(const iterator& other);
		bool operator==(const iterator& other);
		//pre
		iterator& operator++();
		iterator& operator--();
		//post
		iterator	 operator++(int);
		iterator	 operator--(int);

		private:
			Pointer mPtr;
			size_t size;
			
	};
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iterator begin();
		iterator end();

};

#endif
