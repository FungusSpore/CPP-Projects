/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:09:53 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/16 17:28:38 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <exception>
#include <string>

class Span{
private:
	std::vector<int> _arr;
	unsigned int _maxSize;
	unsigned int _size;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int nbr);

	template <typename Iterator>
	void addNumber(Iterator a, Iterator b){
		if (std::distance(a, b)	< 0)
			throw _M_range_insert("Iterator range is impossible");
		if (b == a)
			throw NotEnoughElements("No elements in iterator range");
		if (this->_size + std::distance(a, b) > this->_maxSize)
				throw MaxSizeReached("Not enough space to insert this range of iterators");
		for (; a != b; ++a){
			this->_arr.push_back(*a);
			this->_size++;
		}
		std::sort(_arr.begin(), _arr.end());
	}

	int shortestSpan();
	int longestSpan();

	class MaxSizeReached : public std::exception {
	private:
		std::string msg;
	public:
		MaxSizeReached(std::string message);
		const char* what() const throw();
		~MaxSizeReached() throw();
	};
	class NotEnoughElements : public std::exception {
	private:
		std::string msg;
	public:
		NotEnoughElements(std::string message);
		const char* what() const throw();
		~NotEnoughElements() throw();
	};
	class _M_range_insert : public std::exception {
	private:
		std::string msg;
	public:
		_M_range_insert(std::string message);
		const char* what() const throw();
		~_M_range_insert() throw();
	};
};

#endif
