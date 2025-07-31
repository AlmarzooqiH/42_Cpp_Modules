/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:51:45 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 16:54:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& right){
	(void)right;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& right){
	(void)right;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::convert(const std::string unit){
	
}
