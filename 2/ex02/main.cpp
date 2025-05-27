/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:02:03 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/14 13:16:54 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void){

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl;

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl;

	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == b) << std::endl;

	std::cout << std::endl;

	Fixed c(Fixed(5.05f) / Fixed(2));

	std::cout << c << std::endl;
	std::cout << c + Fixed(1) << std::endl;
	std::cout << c - Fixed(1) << std::endl;
	std::cout << c * Fixed(2) << std::endl;
	std::cout << c / Fixed(2) << std::endl;

	// will crash
	/*std::cout << c / Fixed(0) << std::endl;*/

	std::cout << b << "\n" << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	return 0;
}
