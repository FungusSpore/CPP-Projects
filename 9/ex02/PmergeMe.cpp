/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:17 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/25 14:41:51 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iterator>
#include <ostream>

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
	std::cout << "container check" << std::endl;
	std::vector<unsigned int>::iterator it = this->vectorArr.begin();
	for (; it != this->vectorArr.end(); it++)
		std::cout << "|" << *it << "|" << std::endl;
	return (true);
}

void PmergeMe::insertSchedule(unsigned int start, unsigned int end, std::vector<unsigned int>& order){
	std::cout << "start :" << start << "end: " << end << std::endl;
	if (start > end)
		return ;
	unsigned int mid = (end - start) / 2;
	std::cout << "mid: " << mid << std::endl;
	if (mid == 0)
		return ;
	order.push_back(mid);
	insertSchedule(start, mid - 1, order);
	insertSchedule(mid + 1, end, order);
}

void PmergeMe::insert(std::vector<unsigned int>& winner, unsigned int value){
	std::vector<unsigned int> result;
	std::vector<unsigned int>::iterator low = winner.begin();
	std::vector<unsigned int>::iterator high = winner.end();
	// unsigned int low = 0;
	// unsigned int high = winner.size();
	std::vector<unsigned int>::iterator mid;

	while (low < high){
		std::advance(mid, std::distance(high, low) / 2);
		if (value < *mid)
			high = mid;
		else
			low = mid + 1;
	}
}


std::vector<unsigned int>	PmergeMe::fortJohnson(std::vector<unsigned int> vectorArr){
	std::cout << "recursion" << std::endl;
	std::cout << "base case" << std::endl;
	if (vectorArr.size() < 2)
		return vectorArr;
	if (vectorArr.size() == 2 && vectorArr.at(0) > vectorArr.at(1)){
		unsigned int temp = vectorArr.at(0);
		vectorArr.at(0) = vectorArr.at(1);
		vectorArr.at(1) = temp;
		return vectorArr;
	}
	std::vector<unsigned int> winner;
	std::vector<unsigned int> loser;
	std::vector<unsigned int> order;
	std::vector<unsigned int>::iterator it = vectorArr.begin();

	std::cout << "pair compare" << std::endl;
	for (; it != vectorArr.end(); it++){
		unsigned int a = *it++;
		if (it == vectorArr.end()){
			winner.push_back(a);
			break ;
		}
		unsigned int b = *it;
		if (a > b){
			winner.push_back(a);
			loser.push_back(b);
		}
		else{
			winner.push_back(b);
			loser.push_back(a);
		}
	}
	std::cout << "call recursion" << std::endl;
	winner = fortJohnson(winner);
	std::cout << "get loser queue" << std::endl;
	insertSchedule(0, loser.size() - 1, order);
	std::cout << "insert loser into winner" << std::endl;
	for (size_t i = 0; i < loser.size(); i++)
		insert(winner, loser.at(order.at(i)));
	
	return (winner);
}

void PmergeMe::sort(){
	fortJohnson(this->vectorArr);

}

//=================================
// EXCEPTION
//=================================

PmergeMe::ParsingError::ParsingError(const std::string msg):msg(msg){}
const char* PmergeMe::ParsingError::what() const throw(){ return this->msg.c_str(); }
PmergeMe::ParsingError::~ParsingError() throw(){}
