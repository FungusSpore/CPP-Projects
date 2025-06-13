/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:16:48 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/13 17:58:45 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <list>
#include <vector>

int main(void){
	int arr[5] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0])); 
	std::deque<int> deque(arr, arr + sizeof(arr)/sizeof(arr[0]));
	std::list<int> list(arr, arr + sizeof(arr)/sizeof(arr[0]));
	// std::forward_list<int> f_list(arr, arr + sizeof(arr)/sizeof(arr[0]));


	// easyfind(arr, 3);
	std::cout << "Vector Test" << std::endl;
	std::cout << "\nValid Test" << std::endl;
	std::vector<int>::iterator vecIt = easyfind(vec, 3);
	if (vecIt != vec.end())
		std::cout << "Number found " << *vecIt << std::endl;
	else
		std::cout << "Number not found" << std::endl; 

	std::cout << "\nInvalid Test" << std::endl;
	vecIt = easyfind(vec, 8);
	if (vecIt != vec.end())
		std::cout << "Number found " << *vecIt << std::endl;
	else
		std::cout << "Number not found" << std::endl; 

// --------------------------------------------------------

	std::cout << "Deque Test" << std::endl;
	std::cout << "\nValid Test" << std::endl;
	std::deque<int>::iterator deqIt = easyfind(deque, 3);
	if (deqIt != deque.end())
		std::cout << "Number found " << *deqIt << std::endl;
	else
		std::cout << "Number not found" << std::endl; 

	std::cout << "\nInvalid Test" << std::endl;
	deqIt = easyfind(deque, 8);
	if (deqIt != deque.end())
		std::cout << "Number found " << *deqIt << std::endl;
	else
		std::cout << "Number not found" << std::endl; 

// --------------------------------------------------------
	
	std::cout << "List Test" << std::endl;
	std::cout << "\nValid Test" << std::endl;
	std::list<int>::iterator listIt = easyfind(list, 3);
	if (listIt != list.end())
		std::cout << "Number found " << *listIt << std::endl;
	else
		std::cout << "Number not found" << std::endl; 

	std::cout << "\nInvalid Test" << std::endl;
	listIt = easyfind(list, 8);
	if (listIt != list.end())
		std::cout << "Number found " << *listIt << std::endl;
	else
		std::cout << "Number not found" << std::endl; 

// --------------------------------------------------------
	
// 	std::cout << "Forward List Test" << std::endl;
// 	std::cout << "\nValid Test" << std::endl;
// 	std::forward_list<int>::iterator flistIt = easyfind(f_list, 3);
// 	if (flistIt != f_list.end())
// 		std::cout << "Number found " << *flistIt << std::endl;
// 	else
// 		std::cout << "Number not found" << std::endl; 
//
// 	std::cout << "\nInvalid Test" << std::endl;
// 	flistIt = easyfind(f_list, 8);
// 	if (flistIt != f_list.end())
// 		std::cout << "Number found " << *flistIt << std::endl;
// 	else
// 		std::cout << "Number not found" << std::endl; 
}
