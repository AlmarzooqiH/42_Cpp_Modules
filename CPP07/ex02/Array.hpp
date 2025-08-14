/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:03:29 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/14 20:38:51 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array{
	private:
		T* arr;
		unsigned int tSize;

	public:
		Array();
		Array(unsigned int size);
		Array(const Array& right);
		Array<T>& operator=(const Array& right);
		~Array();
		unsigned int size(void) const;
		const T& operator[](unsigned int index) const;
		T& operator[](unsigned int index);
};

# include "Array.tpp"

#endif