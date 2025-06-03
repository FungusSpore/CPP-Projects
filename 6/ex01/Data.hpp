/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:14:50 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/03 19:47:03 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data{
	private:
		int data1;
		long data2;
		float data3;
		double	data4;
	public:
		Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
};

#endif // !SCALARCONVERTER_HPP
