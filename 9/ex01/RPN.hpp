/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:23:39 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/23 00:43:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <bits/std_thread.h>
#include <ostream>
#include <string>
#include <list>
#include <exception>

class RPN{
private:
	std::list<std::string> expression;
	int result;


	void split(std::string input);
	bool is_formatted();
	void calculate();


public:
	RPN();
	RPN(std::string input);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	int getResult() const;

	class GeneralError : public std::exception{
	private:
		std::string msg;
	public:
		GeneralError(const std::string msg);
		const char* what() const throw();
		~GeneralError () throw();
	};

};

std::ostream &operator<<(std::ostream& os, const RPN& current);

#endif // !RPN_HPP
