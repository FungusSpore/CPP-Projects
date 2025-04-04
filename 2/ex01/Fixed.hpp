/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:39:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/14 21:49:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
private:
	static const int fracBits = 8;
	int	num;

public:
	Fixed();
	Fixed(const int);
	Fixed(const float);

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	friend std::ostream &operator<<(std::ostream &os, const Fixed& current);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

#endif
