/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:09:38 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/16 22:32:43 by hamalmar         ###   ########.fr       */
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
	std::string operationsSet(VALID_INPUT);
	for (size_t i = this->expression.length(); i-- > 0;){
        if (std::isspace(static_cast<unsigned char>(this->expression[i])))
            continue;
		if (!isInSet(this->expression[i], operationsSet))
			throw (RPN::InvalidOperationException());
		this->data.push(this->expression[i]);
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

static void performCalculation(double n1, double n2, double& res, char operation){
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
}

static bool validateExpression(std::stack<char>& data){
	std::stack<char> dataCopy = data;
	if (dataCopy.size() < 2)
		throw (RPN::NotEnoughElementsInExpressionException());
	else if (isOperation(dataCopy.top()))
		throw (RPN::CannotStartWithAnOperationException());
	bool n1 = false, n2 = false, isOp = false;
	while (!dataCopy.empty()){
		bool digit = std::isdigit(static_cast<unsigned char>(dataCopy.top()));
		if (!n1 && digit){
			n1 = true;
			dataCopy.pop();
			continue ;
		}
		if (!n2 && digit){
			n2 = true;
			dataCopy.pop();
			continue ;
		}
		if (digit && dataCopy.size() == 1)
			throw (RPN::InvalidExpression());

		if (n1 && n2){
			if (isOp && isOperation(dataCopy.top()))
				throw (RPN::InvalidExpression());
			if (isOperation(dataCopy.top())) {
				isOp = true;
				dataCopy.pop();
				continue ;
			}
			if (isOp && digit){
				isOp = false;
				dataCopy.pop();
				continue;
			}
		}else {
			throw (RPN::InvalidExpression());
		}
		dataCopy.pop();
	}
	return (true);
}

void	RPN::calculateExpression(void){
	if (!validateExpression(this->data))
		throw (RPN::InvalidExpression());
	std::stack<char> tmp = this->data;
	double result = 0.0;
	bool resFlag = false, firstTimeFlag = false;
	while (!tmp.empty()){
		double n1 = 0.0;
		double n2 = 0.0;
		if (resFlag)
			n1 = result;
		if (!firstTimeFlag){
			std::istringstream(std::string(1, tmp.top())) >> n1;
			tmp.pop();
			std::istringstream(std::string(1, tmp.top())) >> n2;
			tmp.pop();
			firstTimeFlag = true;
			performCalculation(n1, n2, result, tmp.top());
			tmp.pop();
			resFlag = true;
			continue;
		}
		double n3 = 0.0;
		std::istringstream(std::string(1, tmp.top())) >> n3;
		tmp.pop();
		performCalculation(n1, n3, result, tmp.top());
		tmp.pop();
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

const char	*RPN::InvalidExpression::what() const throw(){
	return ("Expression is Invalid");
}

const char	*RPN::CannotStartWithAnOperationException::what() const throw(){
	return ("Cannot start RPN with an operation.");
}
