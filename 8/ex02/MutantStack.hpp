/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:54:56 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/18 22:35:17 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>


template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>{
public:
	typedef typename std::stack<T, Container>::container_type::iterator								iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator					const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator				reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

	// Orthodox
	MutantStack(){}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {};
	MutantStack& operator=(const MutantStack& other){
		if (this != &other){
			std::stack<T,Container>::operator=(other);
		}
		return (*this);
	}
	~MutantStack(){}

	// iterator definition
	iterator begin(){
		return (std::stack<T, Container>::c.begin());
	}
	iterator end(){
		return (std::stack<T, Container>::c.end());
	}

	const_iterator begin() const{
		return (std::stack<T, Container>::c.begin());
	}
	const_iterator end() const{
		return (std::stack<T, Container>::c.end());
	}

	reverse_iterator rbegin(){
		return (std::stack<T, Container>::c.rbegin());
	}
	reverse_iterator rend(){
		return (std::stack<T, Container>::c.rend());
	}

	const_reverse_iterator rbegin() const{
		return (std::stack<T, Container>::c.rbegin());
	}
	const_reverse_iterator rend() const{
		return (std::stack<T, Container>::c.rend());
	}
};

// #include "MutantStack.tpp"

#endif
