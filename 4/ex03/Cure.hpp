/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:04:33 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/26 14:34:30 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure: public AMateria{
public:
	Cure();
	Cure(std::string const & type);
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	std::string const & getType() const; // return materia type
	Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif
