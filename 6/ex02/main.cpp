/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:46:28 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/06 19:20:24 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void){
	Base* test1 = generate();
	Base* test2 = generate();
	Base* test3 = generate();
	Base* test4 = generate();

	Base& testR1 = *test1;
	Base& testR2 = *test2;
	Base& testR3 = *test3;
	Base& testR4 = *test4;

	identify(test1);
	identify(test2);
	identify(test3);
	identify(test4);

	identify(testR1);
	identify(testR2);
	identify(testR3);
	identify(testR4);

	delete test1;
	delete test2;
	delete test3;
	delete test4;
}
