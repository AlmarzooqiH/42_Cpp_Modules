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

#include <iostream>
#include <stack>
#include <exception>
#include <algorithm>

class RPN{
	public:
		RPN();
		RPN(const RPN& right);
		RPN& operator=(const RPN& right);
		~RPN();

		class InvalidNumberRangeException: public std::exception{
			public:
				const char *what() const throw();
		};

		class InvalidOperationException: public std::exception{
			public:
				const char *what() const throw();
		};
};

#endif