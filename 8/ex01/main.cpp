/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:00:37 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/16 17:51:10 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main(void){
	int arr[5] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
	Span test1(5);
	Span test2(0);
	Span test3(-1); // unsigned int max
	Span test4(5);
	Span test5(4);

	// No Elem
	std::cout << "\nNo elem in Span" << std::endl;
	try {
		test1.longestSpan();
		test1.shortestSpan();
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		test2.longestSpan();
		test2.shortestSpan();
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		test3.longestSpan();
		test3.shortestSpan();
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nadd elem in Span" << std::endl;
	try {
		test1.addNumber(1);
		test1.addNumber(2);
		test1.addNumber(3);
		test1.addNumber(4);
		test1.addNumber(5);
		std::cout << "test 1 is now full" << std::endl;
		test1.addNumber(6);
		std::cout << "test 1: Error if this message is shown" << std::endl;
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		test2.addNumber(1);
		std::cout << "test 2: Error if this message is shown" << std::endl;
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		test3.addNumber(2);
		// std::cout << "test 3: Error if this message is shown" << std::endl;
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\ncall longest and shortest span" << std::endl;
	try {
		std::cout << "test 1 valid" << std::endl;
		std::cout << test1.longestSpan() << std::endl;
		std::cout << test1.shortestSpan() << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "test 2 invalid" << std::endl;
		std::cout << test2.longestSpan() << std::endl;
		std::cout << test2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "test 3 invalid" << std::endl;
		std::cout << test3.longestSpan() << std::endl;
		std::cout << test3.shortestSpan() << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nRange of iterators" << std::endl;
	try {
		test4.addNumber(vec.end(), vec.begin());
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		test5.addNumber(vec.begin(), vec.end());
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "valid test" << std::endl;
		test4.addNumber(vec.begin(), vec.end());
		std::cout << test4.longestSpan() << std::endl;
		std::cout << test4.shortestSpan() << std::endl;
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
