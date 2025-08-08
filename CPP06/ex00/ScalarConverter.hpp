/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:42:27 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/09 00:06:15 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

/**
 * Added bitmasking because i can have multiple values under one value,
 * reminds me of when i was working on minishell when i used to open a
 * file descriptor we had to pass in some flags where we did something
 * similar to this: O_CREATE | O_OPEN | O_RDONLY. In here we can do the same
 * suppose the input was a float the value will contain the following values
 * INTEGER | FLOAT | DOUBLE so how can we check for them? Easy let's look at
 * them in binary at first:
 * Integer value is 8 and in binary it will be: 00000000 00000000 00000000 00001000
 * Float value is 16 and in binary it will be:  00000000 00000000 00000000 00010000
 * Double value is 32 and in binary it will be: 00000000 00000000 00000000 00100000
 * When we use the OR (|) operator on them we will end up with the value of 56 which
 * which will be in binary as: 00000000 00000000 00000000 00111000 then just to check
 * which type we got we will use the AND(&) operator with it, since we agreed it is a
 * float in the begging we will check with the float value as the following:
 * Float: 		   00000000 00000000 00000000 00010000
 * Resultant bits: 00000000 00000000 00000000 00111000
 * 				   -----------------------------------&
 * 				   00000000 00000000 00000000 00010000
 * Which is a Float, it is fast & easy since we are using bitwise operators.
 * [🤓🤓🤓]
 */
enum inputType{
	EMPTY_INPUT = 0,
	ISNAN = 1 << 0,
	INF = 1 << 1,
	CHARACTER = 1 << 2,
	INTEGER = 1 << 3,
	FLOAT = 1 << 4,
	DOUBLE = 1 << 5
};

class ScalarConverter{

	
	private:
	ScalarConverter();
		ScalarConverter(const ScalarConverter& right);
		ScalarConverter& operator=(const ScalarConverter& right);
		~ScalarConverter();
		// static int checkInputType(const std::string unit);
		
		public:
			static void	convert(const std::string& unit);
			
			class EmptyArgumentException: public std::exception{
				public:
					const char *what() const throw();
			};

			class InvalidUnitException: public std::exception{
				public:
					const char *what() const throw();
			};

};


#endif