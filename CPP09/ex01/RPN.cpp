/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:09:38 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/15 22:25:19 by hamalmar         ###   ########.fr       */
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

static bool isInSet(char c, std::string& set){
	if (set.empty())
		return (false);
	for (size_t i = 0; i < set.length(); i++){
		if (set[i] == c)
			return (true);
	}
	return (false);
}

void	RPN::parseExpression(void){
	std::string set(VALID_INPUT);
	bool spaceFlag = false;
	for (size_t i = this->expression.length() - 1; i > 0; i--){
		if (i == 1){
			i--;
			if (spaceFlag && std::isspace(static_cast<int>(this->expression[i]))){
				spaceFlag = false;
			continue;
		}
		if (!isInSet(this->expression[i], set))
			throw (RPN::InvalidOperationException());
		double n = 0;
		std::string tmp(1, this->expression[i]);
		std::istringstream(tmp) >> n;
		if (n < 0 || n > 9)
			throw (RPN::InvalidNumberRangeException());
		this->data.push(this->expression[i]);
		spaceFlag = true;
		break;
	}
	if (spaceFlag && std::isspace(static_cast<int>(this->expression[i]))){
		spaceFlag = false;
		continue;
	}
	if (!isInSet(this->expression[i], set))
		throw (RPN::InvalidOperationException());
	double n = 0;
	std::string tmp(1, this->expression[i]);
	std::istringstream(tmp) >> n;
	if (n < 0 || n > 9)
	throw (RPN::InvalidNumberRangeException());
	this->data.push(this->expression[i]);
	spaceFlag = true;
}
}

RPN::RPN(std::string& expression){
	this->expression = expression;
	parseExpression();
}

static bool isOperation(char c){
	return (
		c == '+' ||
		c == '-' ||
		c == '/' ||
		c == '*'
	);
}

static double performCalculation(double n1, double n2, char operation){
	std::cout << "Calculating" << std::endl;
	double res = 0.0;
	switch (operation)
	{
	case '+':
		res = (n1 + n2);
		break ;
	case '-':
		res = (n1 - n2);
		break ;
	case '*':
		res = (n1 * n2);
		break;
	case '/':
		if (n2 == 0)
			throw (RPN::DivisionByZeroException());
		res = (n1 / n2);
		break ;
	}
	return (res);
}

void	RPN::calculateExpression(void){
	double result = 0.0;
	bool resultFlag = false, n1Flag = false, n2Flag = false;
	if (this->data.size() < 2)
		throw (RPN::NotEnoughElementsInExpressionException());
	while (!this->data.empty()){
		double n1;
		if (resultFlag)
			n1 = result;
		else
			n1 = 0.0;
		double n2 = 0.0;
		char tmp = this->data.top();
		bool isOp = isOperation(tmp);
		if ((isOp && !n1Flag))
			throw (RPN::InvalidOperationException());
		if (resultFlag && n2Flag && isOp){
			result = performCalculation(n1, n2, tmp);
			n2Flag = false;
		}
		if (n1Flag && n2Flag){
			resultFlag = true;
			n2Flag = false;
		}
		if (!n1Flag){
			std::istringstream(std::string(1, tmp)) >> n1;
			n1Flag = true;
		} else if (!n2Flag) {
			std::istringstream(std::string(1, tmp)) >> n2;
			n2Flag = true;
		}
		std::cout << "isOp: " << isOp << ", resultFlag: " << resultFlag << ", n1Flag: " << n1Flag << ", n2Flag: " << n2Flag << std::endl;
		this->data.pop();
	}
	std::cout << result << std::endl;
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

const char *RPN::DivisionByZeroException::what() const throw(){
	return ("Cannot divide by zero");
}

const char *RPN::NotEnoughElementsInExpressionException::what() const throw(){
	return ("Elements in the exprssion are not enought. Good expression: ./RPN \"1 2 +\" or ./RPN \"1 2 * 2 / 2 * 2 4 - +\"");
}
