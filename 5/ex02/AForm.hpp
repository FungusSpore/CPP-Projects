/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:23:23 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/23 21:59:47 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#	include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		const int	_gradeToSign;
		const int _gradeToExecute;
		bool	_formSigned;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool	getFormSigned() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		void	execute(Bureaucrat const & executor) const;
		virtual void action(void) const = 0;

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

		class FromNotSignedException : public std::exception {
			private:
				std::string message;
			public:
				FromNotSignedException(const char* msg);
				const char* what() const throw();
				~FromNotSignedException() throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm& current);

#endif // !BUREAUCRAT_HPP
