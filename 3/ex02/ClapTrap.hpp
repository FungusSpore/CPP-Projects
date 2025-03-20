/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:14:37 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 20:57:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap{
private:
	std::string name;
	int					hit_points;
	int					energy_points;
	int					attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void set_hitPoints(int num);
	void set_energyPoints(int num);
	void set_attackDamage(int num);

	int get_hitPoint() const;
	int get_energyPoint() const;
	int get_attackDamage() const;
	std::string get_name() const;
};

#endif
