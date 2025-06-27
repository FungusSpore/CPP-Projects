/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:22:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/28 01:43:47 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <sys/time.h>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <cstdlib>

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
	long long	vector_time;
	std::vector<int> vectorArr;
	long long	deque_time;
	std::deque<int> dequeArr;

	long long getCurrentTime();

	template <typename Container>
	void	fortJohnson(Container& vectorArr);
	template <typename Container>
	void insertSchedule(int k, Container& order);
	template <typename Container>
	void insert(Container& winner, int value);
	template <typename Container>
	bool fill_container(char** argv, Container& arr);


public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sort(char** argv);

	class ParsingError : public std::exception{
	private:
		std::string msg;
	public:
		ParsingError(const std::string msg);
		const char* what() const throw();
		~ParsingError () throw();
	};
};

template <typename Container>
bool PmergeMe::fill_container(char** argv, Container& arr){
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
			arr.push_back(num);
		}
		found = 0;
	}
	return (true);
}

template <typename Container>
void PmergeMe::insertSchedule(int k, Container& order) {
	if (k <= 0) return;
	

	Container jacobsthal;

	jacobsthal.push_back(0);
	if (k > 0) 
		jacobsthal.push_back(1);

	int n = 2;
	while (true) {
		int next_j = jacobsthal[n-1] + 2 * jacobsthal[n-2];
		if (next_j >= k)
			break;
		jacobsthal.push_back(next_j);
		n++;
	}

	Container added(k, false);
	for (int i = jacobsthal.size() - 1; i > 0; --i) {
		int curr = std::min(jacobsthal[i], k - 1);
		int prev = jacobsthal[i - 1];

		for (int j = curr; j > prev; --j)
			if (j < k && !added[j]) {
					order.push_back(j);
					added[j] = true;
			}
	}
	for (int j = std::min(jacobsthal[0], k - 1); j >= 0; --j)
		if (!added[j]) {
			order.push_back(j);
			added[j] = true;
		}
	for (int j = 0; j < k; ++j)
		if (!added[j])
			order.push_back(j);
}

template <typename Container>
void PmergeMe::insert(Container& winner, int value){
	typedef typename Container::iterator iterator;
	iterator low = winner.begin();
	iterator high = winner.end();
	iterator mid;

	while (low < high){
		mid = low + std::distance(low, high) / 2;
		if (value < *mid)
			high = mid;
		else
			low = mid + 1;
	}
	winner.insert(low, value);
}


template <typename Container>
void	PmergeMe::fortJohnson(Container& vectorArr){
	if (vectorArr.size() < 2) return ;
	if (vectorArr.size() == 2 && vectorArr.at(0) > vectorArr.at(1)){
		unsigned int temp = vectorArr.at(0);
		vectorArr.at(0) = vectorArr.at(1);
		vectorArr.at(1) = temp;
		return ;
	}

	Container winner;
	Container loser;
	Container order;
	typename Container::iterator it = vectorArr.begin();

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
	fortJohnson(winner);
	insertSchedule(loser.size(), order);
	for (size_t i = 0; i < order.size(); i++)
		insert(winner, loser.at(order.at(i)));
	vectorArr = winner;
}

#endif
