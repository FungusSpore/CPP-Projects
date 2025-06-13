/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:37:18 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/13 17:37:44 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T& container, const int toFind){
	typename T::iterator it = container.begin();

	while (it != container.end()){
		if (*it == toFind)
			break ;
		it++;
	}
	return (it);
}
