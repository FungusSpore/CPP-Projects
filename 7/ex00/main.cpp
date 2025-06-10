/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:44:28 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/08 17:55:35 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Fixed.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Fixed test1 = 1;
	Fixed test2 = 2;

	::swap(test1, test2);
	std::cout << "test1 = " << test1 << ", test2 = " << test2 << std::endl;
	std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
	std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;

	return 0;
}
