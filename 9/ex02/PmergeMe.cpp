/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:17 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/28 01:48:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ostream>
#include <cmath>
#include <sys/select.h>

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

// bool PmergeMe::fill_container(char** argv){
// 	std::string currentArg;
// 	size_t found = 0;
//
// 	while (*++argv){
// 		currentArg = *argv;
// 		while (found != std::string::npos){
// 			// trim spaces
// 			currentArg.erase(0, currentArg.find_first_not_of(" \t\r\n"));
// 			currentArg.erase(currentArg.find_last_not_of(" \t\r\n") + 1);
//
// 			// split
// 			std::string num_str = currentArg.substr(0, found = currentArg.find(" "));
// 			for (size_t i = 0; i < num_str.size(); i++)
// 				if (!std::isdigit(num_str.c_str()[i]))
// 					throw ParsingError("Error: not a number");
//
// 			long num = static_cast<long>(atoi(num_str.c_str()));
// 			if (num < 0)
// 				throw ParsingError("Error: cannot have negative");
//
// 			currentArg.erase(0, currentArg.find(" ") + 1);
// 			this->dequeArr.push_back(num);
// 			this->vectorArr.push_back(num);
// 		}
// 		found = 0;
// 	}
// 	return (true);
// }

void PmergeMe::sort(char **argv){
	long long start, end;

	std::vector<int> temp;
	fill_container(argv, temp);
	std::cout << "Before: ";
	std::vector<int>::iterator it = temp.begin();
	for (; it != temp.end(); it++)
		std::cout << " " << *it;
	std::cout << "\n";

	start = getCurrentTime();
	fill_container(argv, this->vectorArr);
	fortJohnson(this->vectorArr);
	end = getCurrentTime();
	this->vector_time = end - start;

	start = getCurrentTime();
	fill_container(argv, this->dequeArr);
	fortJohnson(this->dequeArr);
	end = getCurrentTime();
	this->deque_time = end - start;

	std::cout << "After:  ";
	it = this->vectorArr.begin();
	for (; it != this->vectorArr.end(); it++)
		std::cout << " " << *it;
	std::cout << "\n";
	
	std::cout << "Time to process a range of   5 elements with std::vector : " << this->vector_time << std::endl;
	std::cout << "Time to process a range of   5 elements with std::deque : " << this->deque_time << std::endl;

	// std::vector<unsigned int>::iterator it = this->vectorArr.begin();
	// for (; it != this->vectorArr.end(); it++)
	// 	std::cout << *it << std::endl;
	// std::cout << "deque" << std::endl;
	// std::deque<unsigned int>::iterator it2 = this->dequeArr.begin();
	// for (; it2 != this->dequeArr.end(); it2++)
	// 	std::cout << *it2 << std::endl;
}


long long PmergeMe::getCurrentTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL + tv.tv_usec);
}

//=================================
// EXCEPTION
//=================================

PmergeMe::ParsingError::ParsingError(const std::string msg):msg(msg){}
const char* PmergeMe::ParsingError::what() const throw(){ return this->msg.c_str(); }
PmergeMe::ParsingError::~ParsingError() throw(){}
