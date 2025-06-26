/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:17 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/26 21:28:48 by jianwong         ###   ########.fr       */
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
	std::cout << "container check" << std::endl;
	std::vector<unsigned int>::iterator it = this->vectorArr.begin();
	for (; it != this->vectorArr.end(); it++)
		std::cout << "|" << *it << "|" << std::endl;
	return (true);
}

void PmergeMe::insertSchedule(int k, std::vector<unsigned int>& order) {
    std::vector<int> jacobsthal;
    int n = 0;

    // Generate Jacobsthal numbers <= k
    while (true) {
        int j = ((1 << n) - ((n % 2 == 0) ? 1 : -1)) / 3;
        if (j > k) break;
        jacobsthal.push_back(j);
        n++;
    }

    // Insert elements in Jacobsthal batches from higher to lower
    for (int i = jacobsthal.size() - 1; i > 0; --i) {
        int curr = jacobsthal[i];
        int prev = jacobsthal[i - 1];

        // Insert from b[curr - 1] down to b[prev]
        for (int j = curr - 1; j >= prev; --j) {
            order.push_back(j);
        }
    }

    // Finally insert from b[jacobsthal[0] - 1] down to b[0]
    for (int j = jacobsthal[0] - 1; j >= 0; --j) {
        order.push_back(j);
    }
}


void PmergeMe::insert(std::vector<unsigned int>& winner, unsigned int value){
	std::vector<unsigned int> result;
	std::vector<unsigned int>::iterator low = winner.begin();
	std::vector<unsigned int>::iterator high = winner.end();
	std::vector<unsigned int>::iterator mid;

	while (low < high){

		mid = winner.begin() + std::distance(low, high) / 2;
		if (value < *mid)
			high = mid;
		else
			low = mid + 1;
	}
	winner.insert(low, value);
}


std::vector<unsigned int>	PmergeMe::fortJohnson(std::vector<unsigned int> vectorArr){
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
	winner = fortJohnson(winner);
	std::cout << "loser size" << loser.size() << std::endl;
	std::cout << "get loser queue" << std::endl;
	insertSchedule(loser.size(), order);
	std::vector<unsigned int>::iterator it2 = order.begin();
	std::cout << order.size() << std::endl;
	for (; it2 != order.end(); it2++)
		std::cout << "|" << *it2 << "|" << std::endl;

	std::cout << "insert loser into winner" << std::endl;
	std::cout << order.size() << " " << loser.size() << std::endl;
	for (size_t i = 0; i < order.size(); i++)
		insert(winner, loser.at(order.at(i)));
	
	return (winner);
}

void PmergeMe::sort(){
	this->vectorArr = fortJohnson(this->vectorArr);
	std::vector<unsigned int>::iterator it = this->vectorArr.begin();
	std::cout << "RESULT" << std::endl;
	for (; it != this->vectorArr.end(); it++)
		std::cout << *it << std::endl;
}

//=================================
// EXCEPTION
//=================================

PmergeMe::ParsingError::ParsingError(const std::string msg):msg(msg){}
const char* PmergeMe::ParsingError::what() const throw(){ return this->msg.c_str(); }
PmergeMe::ParsingError::~ParsingError() throw(){}
