/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:22:43 by hamad             #+#    #+#             */
/*   Updated: 2025/04/01 17:56:47 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed{
	private:
		int rawBits;
		const static int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int i);
		Fixed(const float f);
		Fixed&	operator=(const Fixed& f);
		bool	operator>(const Fixed& f);
		bool	operator<(const Fixed& f);
		bool	operator>=(const Fixed& f);
		bool	operator<=(const Fixed& f);
		bool	operator==(const Fixed& f);
		bool	operator!=(const Fixed& f);
		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);
		Fixed	operator++(int increment); //Post increment
		Fixed	operator++(); //Pre increment
		Fixed	operator--(int decrement); //Post decrement
		Fixed	operator--(); //Pre Decrement

		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif