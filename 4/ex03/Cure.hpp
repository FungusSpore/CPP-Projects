/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:04:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/24 02:05:24 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure{
public:
	Cure(std::string const & type);

	std::string const & getType() const; // return materia type
	virtual Cure* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
