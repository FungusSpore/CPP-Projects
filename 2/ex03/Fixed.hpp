/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:39:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/14 13:14:38 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
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

	bool operator>(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);

	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	//pre
	Fixed& operator++();
	Fixed& operator--();
	//post
	Fixed	 operator++(int);
	Fixed	 operator--(int);

	~Fixed();


	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed& x, Fixed& y);
	static const Fixed& min(const Fixed& x, const Fixed& y);
	static Fixed& max(Fixed& x, Fixed& y);
	static const Fixed& max(const Fixed& x, const Fixed& y);
};

std::ostream &operator<<(std::ostream &os, const Fixed& current);
#endif
