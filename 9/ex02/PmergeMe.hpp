/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:22:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/26 17:00:51 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

// sorting input list
//
// base case of 2 and less
//
// split into a and b
// call recursion with a
// insert b into sorted a
// insert leftover

// input validation
// 
// trim ends for spaces
// split input based on space
// check if input isdigit
// check for any negative numbers


class PmergeMe{
private:
	std::vector<unsigned int> vectorArr;
	std::deque<unsigned int> dequeArr;
	std::vector<unsigned int>	fortJohnson(std::vector<unsigned int> vectorArr);
	void insertSchedule(int k, std::vector<unsigned int>& order);
	void insert(std::vector<unsigned int>& winner, unsigned int value);


public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	bool fill_container(char** argv);
	void sort();

	class ParsingError : public std::exception{
	private:
		std::string msg;
	public:
		ParsingError(const std::string msg);
		const char* what() const throw();
		~ParsingError () throw();
	};
};


#endif
