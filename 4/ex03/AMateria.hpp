/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:06:02 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/24 01:41:38 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>

class AMateria{
protected:

public:
	AMateria(std::string const & type);

	std::string const & getType() const; // return materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
