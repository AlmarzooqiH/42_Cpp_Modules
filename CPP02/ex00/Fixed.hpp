/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:22:43 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 21:57:58 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed{
	private:
		int rawBits;
		const static int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed& operator=(const Fixed& f);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif