/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:42:27 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 16:51:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter{

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& right);
		ScalarConverter& operator=(const ScalarConverter& right);
		~ScalarConverter();

	public:
		static void	convert(const std::string unit);
};
#endif