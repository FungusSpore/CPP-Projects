/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:59:15 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/08 22:37:36 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void valuePlus(T& i){
	std::cout << "Before: " << i << std::endl;
	i++;
	std::cout << "After: " << i << std::endl;
}

template <typename T, typename F>
void	iter(T addr, size_t lenght, F funcPtr){
	for (size_t i = 0; i < lenght; i++)
		funcPtr(addr[i]);
}

#endif // !ITER_HPP
