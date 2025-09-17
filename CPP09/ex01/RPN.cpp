/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:09:38 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/17 18:11:26 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& right){
	this->expression = right.expression;
}

RPN& RPN::operator=(const RPN& right){
	if (this != &right){
		this->expression = right.expression;
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

RPN::RPN(std::string& expression)
{
	if (expression.empty())
		throw (RPN::EmptyExpressionException());
	this->expression = expression;
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

void	RPN::calculateExpression(void){
	std::string expCopy(this->expression);
	std::string operationsSet(VALID_INPUT);
	std::stack<double> stk;
	for (size_t i = 0; i < expCopy.length(); i++){
		if (std::isspace(static_cast<unsigned char>(this->expression[i])))
			continue;
		if (!isInSet(expCopy[i], operationsSet))
			throw (RPN::InvalidOperationException());
		if (isOperation(expCopy[i])){
			double n1 = 0.0, n2 = 0.0, res = 0.0;
			if (stk.size() < 2)
				throw (RPN::InvalidExpression());
			n2 = stk.top();
			stk.pop();
			n1 = stk.top();
			stk.pop();
			performCalculation(n1, n2, res, expCopy[i]);
			stk.push(res);
			continue;
		}
		if (std::isdigit(static_cast<unsigned char>(expCopy[i]))){
			double tmpNum = 0.0;
			size_t j = i;
			while (j < expCopy.length() && !std::isspace(static_cast<unsigned char>(expCopy[j])))
				j++;
			std::istringstream(expCopy.substr(i, j - i)) >> tmpNum;
			if (tmpNum > 9)
				throw (RPN::InvalidNumberRangeException());
			stk.push(tmpNum);
			i = j - 1;
		}
	}
	if (stk.size() == 1) {
		std::cout << stk.top() << std::endl;
		stk.pop();
		return ;
	}
	throw (RPN::InvalidExpression());
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

const char	*RPN::InvalidExpression::what() const throw(){
	return ("Expression is Invalid");
}
