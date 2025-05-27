/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:23:23 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/22 19:42:55 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#	include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form{
	private:
		const std::string _name;
		const int	_gradeToSign;
		const int _gradeToExecute;
		bool	_formSigned;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool	getFormSigned() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			private:
				std::string message;
			public:
				GradeTooHighException(const char* msg);
				const char* what() const throw();
				~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string message;
			public:
				GradeTooLowException(const char* msg);
				const char* what() const throw();
				~GradeTooLowException() throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form& current);

#endif // !BUREAUCRAT_HPP
