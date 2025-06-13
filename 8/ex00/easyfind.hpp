/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:44:00 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/13 17:48:33 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <bits/stdc++.h>

template <typename T>
typename T::iterator	easyfind(T& container, const int toFind);

# include "easyfind.tpp"

#endif // !EASYFIND_HPP

