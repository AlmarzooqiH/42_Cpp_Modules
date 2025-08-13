/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:03:29 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/13 18:32:30 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array{
	private:
		T arr[];
		unsigned int _size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& right);
		T& operator=(const Array& right);
		~Array();
		unsigned int size(void) const;
};

# include "Array.tpp"

#endif