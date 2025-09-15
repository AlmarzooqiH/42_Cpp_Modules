/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:09:38 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/15 18:01:36 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& right){
	this->expression = right.expression;
	this->data = right.data;
}

RPN& RPN::operator=(const RPN& right){
	if (this != &right){
		this->expression = right.expression;
		this->data = right.data;
	}
	return (*this);
}

RPN::RPN(std::string& expression){
	this->expression = expression;
}


const char *RPN::InvalidNumberRangeException::what() const throw(){
	return ("Invalid number. Range is (0 - 9)");
}

const char *RPN::InvalidOperationException::what() const throw(){
	return ("Invalid Operation");
}

const char *RPN::EmptyExpressionException::what() const throw(){
	return ("Expression cannot be empty");
}
