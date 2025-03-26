/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:39:58 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/26 14:40:23 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice: public AMateria{
public:
	Ice();
	Ice(std::string const & type);
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	std::string const & getType() const; // return materia type
	Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif
