/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:17 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/27 18:54:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iterator>
#include <ostream>
#include <cmath>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other):vectorArr(other.vectorArr), dequeArr(other.dequeArr){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other){
		this->vectorArr = other.vectorArr;
		this->dequeArr = other.dequeArr;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

// input validation
// 
// trim ends for spaces
// split input based on space
// check if input isdigit
// check for any negative numbers

bool PmergeMe::fill_container(char** argv){
	std::string currentArg;
	size_t found = 0;

	while (*++argv){
		currentArg = *argv;
		while (found != std::string::npos){
			// trim spaces
			currentArg.erase(0, currentArg.find_first_not_of(" \t\r\n"));
			currentArg.erase(currentArg.find_last_not_of(" \t\r\n") + 1);

			// split
			std::string num_str = currentArg.substr(0, found = currentArg.find(" "));
			for (size_t i = 0; i < num_str.size(); i++)
				if (!std::isdigit(num_str.c_str()[i]))
					throw ParsingError("Error: not a number");

			long num = static_cast<long>(atoi(num_str.c_str()));
			if (num < 0)
				throw ParsingError("Error: cannot have negative");

			currentArg.erase(0, currentArg.find(" ") + 1);
			this->dequeArr.push_back(num);
			this->vectorArr.push_back(num);
		}
		found = 0;
	}
	return (true);
}
//
// void PmergeMe::insertSchedule(int k, std::vector<unsigned int>& order) {
// 	if (k <= 0) 
// 		return;
//
// 	std::vector<int> jacobsthal;
//
// 	jacobsthal.push_back(0);
// 	if (k > 0) 
// 		jacobsthal.push_back(1);
//
// 	int n = 2;
// 	while (true) {
// 		int next_j = jacobsthal[n-1] + 2 * jacobsthal[n-2];
// 		if (next_j >= k)
// 			break;
// 		jacobsthal.push_back(next_j);
// 		n++;
// 	}
//
// 	std::vector<bool> added(k, false);
// 	for (int i = jacobsthal.size() - 1; i > 0; --i) {
// 		int curr = std::min(jacobsthal[i], k - 1);
// 		int prev = jacobsthal[i - 1];
//
// 		for (int j = curr; j > prev; --j)
// 			if (j < k && !added[j]) {
// 					order.push_back(j);
// 					added[j] = true;
// 			}
// 	}
// 	for (int j = std::min(jacobsthal[0], k - 1); j >= 0; --j)
// 		if (!added[j]) {
// 			order.push_back(j);
// 			added[j] = true;
// 		}
// 	for (int j = 0; j < k; ++j)
// 		if (!added[j])
// 			order.push_back(j);
// }
//
//
// void PmergeMe::insert(std::vector<unsigned int>& winner, unsigned int value){
// 	typedef std::vector<unsigned int>::iterator iterator;
// 	iterator low = winner.begin();
// 	iterator high = winner.end();
// 	iterator mid;
//
// 	while (low < high){
// 		mid = low + std::distance(low, high) / 2;
// 		if (value < *mid)
// 			high = mid;
// 		else
// 			low = mid + 1;
// 	}
// 	winner.insert(low, value);
// }
//
//
// std::vector<unsigned int>	PmergeMe::fortJohnson(std::vector<unsigned int> vectorArr){
// 	if (vectorArr.size() < 2)
// 		return vectorArr;
// 	if (vectorArr.size() == 2 && vectorArr.at(0) > vectorArr.at(1)){
// 		unsigned int temp = vectorArr.at(0);
// 		vectorArr.at(0) = vectorArr.at(1);
// 		vectorArr.at(1) = temp;
// 		return vectorArr;
// 	}
// 	std::vector<unsigned int> winner;
// 	std::vector<unsigned int> loser;
// 	std::vector<unsigned int> order;
// 	std::vector<unsigned int>::iterator it = vectorArr.begin();
//
// 	for (; it != vectorArr.end(); it++){
// 		unsigned int a = *it++;
// 		if (it == vectorArr.end()){
// 			winner.push_back(a);
// 			break ;
// 		}
// 		unsigned int b = *it;
// 		if (a > b){
// 			winner.push_back(a);
// 			loser.push_back(b);
// 		}
// 		else{
// 			winner.push_back(b);
// 			loser.push_back(a);
// 		}
// 	}
// 	winner = fortJohnson(winner);
// 	insertSchedule(loser.size(), order);
// 	for (size_t i = 0; i < order.size(); i++)
// 		insert(winner, loser.at(order.at(i)));
//
// 	return (winner);
// }

void PmergeMe::sort(){
	this->vectorArr = fortJohnson(this->vectorArr);
	this->dequeArr = fortJohnson(this->dequeArr);
	std::cout << "RESULT" << std::endl;
	std::cout << "vector" << std::endl;
	std::vector<unsigned int>::iterator it = this->vectorArr.begin();
	for (; it != this->vectorArr.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "deque" << std::endl;
	std::deque<unsigned int>::iterator it2 = this->dequeArr.begin();
	for (; it2 != this->dequeArr.end(); it2++)
		std::cout << *it2 << std::endl;
}

//=================================
// EXCEPTION
//=================================

PmergeMe::ParsingError::ParsingError(const std::string msg):msg(msg){}
const char* PmergeMe::ParsingError::what() const throw(){ return this->msg.c_str(); }
PmergeMe::ParsingError::~ParsingError() throw(){}
