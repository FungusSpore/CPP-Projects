/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:32:55 by jianwong          #+#    #+#             */
/*   Updated: 2025/05/22 20:24:46 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#	include <iostream>
# include <string>
# include <exception>

class Form;

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat{
	private:
		const std::string name;
		int		grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form& form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat& current);

#endif // !BUREAUCRAT_HPP
