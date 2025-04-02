/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:22:43 by hamad             #+#    #+#             */
/*   Updated: 2025/04/02 12:29:35 by hamad            ###   ########.fr       */
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

		Fixed&				operator=(const Fixed& f);

		bool				operator>(const Fixed& f);
		bool				operator<(const Fixed& f);
		bool				operator>=(const Fixed& f);
		bool				operator<=(const Fixed& f);
		bool				operator==(const Fixed& f);
		bool				operator!=(const Fixed& f);

		Fixed				operator+(const Fixed& f);
		Fixed				operator-(const Fixed& f);
		Fixed				operator*(const Fixed& f);
		Fixed				operator/(const Fixed& f);

		Fixed				operator++(int); //Post increment
		Fixed&				operator++(); //Pre increment
		Fixed				operator--(int); //Post decrement
		Fixed&				operator--(); //Pre Decrement
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif