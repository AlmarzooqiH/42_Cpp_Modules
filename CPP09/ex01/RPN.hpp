/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:11:29 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/14 11:11:29 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <exception>
# include <algorithm>
# include <sstream>
# define VALID_INPUT "1234567890+-/*"

class RPN{

	private:
		std::string expression;
		std::stack<char> data;
		RPN();
		RPN(const RPN& right);
		RPN& operator=(const RPN& right);
		void	parseExpression(void);


	public:
		RPN(std::string& expression);
		void	calculateExpression();
		~RPN();

		class InvalidNumberRangeException: public std::exception{
			public:
				const char *what() const throw();
		};

		class InvalidOperationException: public std::exception{
			public:
				const char *what() const throw();
		};

		class EmptyExpressionException: public std::exception{
			public:
				const char *what() const throw();
		};
		class DivisionByZeroException: public std::exception{
			public:
				const char *what() const throw();
		};
		class NotEnoughElementsInExpressionException: public std::exception{
			public:
				const char *what() const throw();
		};
		
};

#endif