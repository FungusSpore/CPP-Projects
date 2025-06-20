/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:40:26 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/20 22:52:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <ctime>
#include <exception>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

template <typename T>
struct tmComparitor {
	bool operator() (const T& lhs, const T& rhs) const{
		if (lhs.tm_year != rhs.tm_year)
			return (lhs.tm_year < rhs.tm_year);
		if (lhs.tm_mon != rhs.tm_mon)
			return (lhs.tm_mon < rhs.tm_mon);
		return (lhs.tm_mday < rhs.tm_mday);
	}
};

class BitcoinExchange{
private:
	std::map<tm, float, tmComparitor<tm> > database;
		
public:
	BitcoinExchange();
	BitcoinExchange(std::string data_path);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	float	exchangeRate(tm date);

	static bool		date_format_checker(std::string date_str);
	static bool		date_parser(std::string date_str, tm& date);
	static float	value_parser(std::string value_str);
	static bool		value_format_checker(float value);

	class FileCannotOpen : public std::exception{
	private:
		std::string msg;
	public:
		FileCannotOpen(const std::string msg);
		const char* what() const throw();
		~FileCannotOpen() throw();
	};

};

#endif
