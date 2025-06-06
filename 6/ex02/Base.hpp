/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:08:39 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/06 19:29:35 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base{
	public:
		Base();
		virtual ~Base();
};

class A: public Base{
	public:
		A();
};

class B: public Base{
	public:
		B();
};

class C: public Base{
	public:
		C();
};

Base* generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif

