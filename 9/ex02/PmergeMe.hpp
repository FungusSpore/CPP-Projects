/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:22:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/27 22:02:30 by jianwong         ###   ########.fr       */
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

template <typename Container>
void insertSchedule(int k, Container& order) {
	if (k <= 0) 
		return;

	std::vector<int> jacobsthal;

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

	std::vector<bool> added(k, false);
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
void insert(Container& winner, unsigned int value){
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
Container	fortJohnson(Container vectorArr){
	if (vectorArr.size() < 2)
		return vectorArr;
	if (vectorArr.size() == 2 && vectorArr.at(0) > vectorArr.at(1)){
		unsigned int temp = vectorArr.at(0);
		vectorArr.at(0) = vectorArr.at(1);
		vectorArr.at(1) = temp;
		return vectorArr;
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
	winner = fortJohnson(winner);
	insertSchedule(loser.size(), order);
	for (size_t i = 0; i < order.size(); i++)
		insert(winner, loser.at(order.at(i)));
	
	return (winner);
}

class PmergeMe{
private:
	std::vector<unsigned int> vectorArr;
	std::deque<unsigned int> dequeArr;
	// std::vector<unsigned int>	fortJohnson(std::vector<unsigned int> vectorArr);
	// void insertSchedule(int k, std::vector<unsigned int>& order);
	// void insert(std::vector<unsigned int>& winner, unsigned int value);


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
