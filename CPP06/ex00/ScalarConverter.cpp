/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:51:45 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/09 00:06:38 by hamalmar         ###   ########.fr       */
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



double	getNumber(const std::string& unit){
	if (unit.empty())
		throw ScalarConverter::EmptyArgumentException();
	double	out_val = 0.0;
	int sign = 1;
	double	fraction = 0.1;
	size_t i = 0;
	while (i < unit.length() && std::isspace(static_cast<unsigned char>(unit[i])))
    	i++;
	if (i < unit.length() && unit[i] == '-'){
		sign = -1;
		i++;
	} else if (i < unit.length() && unit[i] == '+'){
		i++;
	}
	while (i < unit.length() && std::isdigit(static_cast<unsigned char>(unit[i]))){
		out_val = (10 * out_val) + (unit[i] - '0');
		i++;
	}
	if (i < unit.length() && unit[i] == '.'){
		i++;
		while (i < unit.length() && std::isdigit(static_cast<unsigned char>(unit[i]))){
			out_val += (unit[i] - '0') * fraction;
			i++;
			fraction /= 10;
		}
	}
	return (out_val * sign);
}

/**************** Checking unit type functionality starts here ****************/

bool containsDigit(const std::string& unit){
	if (unit.empty())
		return (false);
	for (size_t i = 0; i < unit.length(); i++){
		if (std::isdigit(static_cast<unsigned char>(unit[i])))
			return (true);
	}
	return (false);
}

bool containsChar(const std::string& unit, const char c){
	if (unit.empty())
		return (false);
	for (size_t i = 0; i < unit.length(); i++){
		if (unit[i] == c)
			return (true);
	}
	return (false);
}

bool checkCharacterOnly(const std::string& unit){
	if (unit.empty())
		return (false);
	bool lenIsOne = unit.length() == 1;
	bool isChar = unit[0] >= std::numeric_limits<char>::min() && unit[0] <= std::numeric_limits<char>::max();
	bool hasDigit = std::isdigit(static_cast<unsigned char>(unit[0]));
	if (hasDigit)
		return (false);
	return (lenIsOne && isChar);
}

bool checkIsNan(const std::string& unit){
	if (unit.empty())
		return (false);
	size_t i = 0;
	while (i < unit.length() && std::isspace(static_cast<unsigned char>(unit[i])))
		i++;
	if (i + 3 > unit.length())
		return (false);
	if (unit[i] == 'n' && unit[i + 1] == 'a' && unit[i + 2] == 'n')
		return (true);
	return (false);
}

bool checkIsInf(const std::string& unit){
	if (unit.empty())
		return (false);
	size_t i = 0;
	while (i < unit.length() && std::isspace(static_cast<unsigned char>(unit[i])))
		i++;
	if (i < unit.length() && (unit[i] == '+' || unit[i] == '-'))
		i++;
	if (i + 3 > unit.length())
		return (false);
	if (unit[i] == 'i' && unit[i + 1] == 'n' && unit[i + 2] == 'f')
		return (true);
	return (false);
}

bool checkCharacterOccourence(const std::string& unit, unsigned char c, unsigned int count){
	if (unit.empty())
		return (false);
	size_t i = 0;
	while (i < unit.length() && std::isspace(static_cast<unsigned char>(unit[i])))
		i++;
	unsigned int occour = 0;
	while (i < unit.length()){
		if (unit[i] == c)
			occour++;
		i++;
	}
	return (occour == count);
}

int	getType(const std::string& unit){
	if (unit.empty())
		return (EMPTY_INPUT);
	int result = 0;
	bool hasF = containsChar(unit, 'f');
	bool hasDigit = containsDigit(unit);
	bool hasDot = containsChar(unit, '.');
	bool isOnlyCharacter = checkCharacterOnly(unit);
	bool isNan = checkIsNan(unit);
	bool isNanF = isNan && hasF;
	bool isINF = checkIsInf(unit);
	bool isINFF = isINF && checkCharacterOccourence(unit, 'f', 2);

	if (isNan)
		result |= ISNAN;
	if (isINF)
		result |=INF;
	if (isOnlyCharacter)
		result |= CHARACTER;
	if ((hasDigit && hasDot && hasF) || isNanF || isINFF)
		result |= FLOAT;
	if (hasDigit && hasDot)
		result |= DOUBLE;
	if (hasDigit)
		result |= INTEGER;
	return (result);
}

/**************** Checking unit type functionality end here ****************/

bool isIntOverflow(double n){
    return (
	n < static_cast<double>(std::numeric_limits<int>::min()) ||
	n > static_cast<double>(std::numeric_limits<int>::max())
		   );
}

bool isFloatOverFlow(double n){
	return (
		(n < -std::numeric_limits<float>::max()) ||
		(n > std::numeric_limits<float>::max())
		   );
}

char getSign(const std::string& unit){
	if (unit.empty())
		return ('H');
	size_t i = 0;
	while (i < unit.length() && std::isspace(static_cast<unsigned char>(unit[i])))
		i++;
	if (i < unit.length() && (unit[i] == '+' || unit[i] == '-'))
		return (unit[i]);	
	return ('H');
}

void	ScalarConverter::convert(const std::string& unit){
	int unitType = getType(unit);
	
	if (unitType & EMPTY_INPUT)
		throw ScalarConverter::EmptyArgumentException();

	if ((unitType & ISNAN) || ((unitType & ISNAN) && (unitType & FLOAT))){
		std::cout << "Character: Impossible" << std::endl;
		std::cout << "Integer: Impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
		return;
	}

	if (unitType & INF && !(unitType & FLOAT)){
		char sign = getSign(unit);
		std::cout << "Character: Impossible" << std::endl;
		std::cout << "Integer: Impossible" << std::endl;
		if (sign == '+' || sign == '-'){
			std::cout << "Float: " << sign << "Inf" << std::endl;
			std::cout << "Double: " << sign << "Inf" << std::endl;
		} else{
			std::cout << "Float: Inf" << std::endl;
			std::cout << "Double: Inf" << std::endl;
		}
		return ;
	}

	if ((unitType & INF) && (unitType & FLOAT)){
		char sign = getSign(unit);
		std::cout << "Character: Impossible" << std::endl;
		std::cout << "Integer: Impossible" << std::endl;
		if (sign == '+' || sign == '-'){
			std::cout << "Float: " << sign << "Inff" << std::endl;
			std::cout << "Double: " << sign << "Inf" << std::endl;
		} else{
			std::cout << "Float: Inff" << std::endl;
			std::cout << "Double: Inf" << std::endl;
		}
		return ;
	}
	if (unitType & CHARACTER){
		char c = unit[0];
		if ((c < std::numeric_limits<char>::min()) || (c > std::numeric_limits<char>::max())){
			std::cout << "Character: Impossible" << std::endl;
		} else if (!std::isprint(static_cast<unsigned char>(c))){
			std::cout << "Character: Not Displayable" << std::endl;
		} else{
			std::cout << "Character: \'" << (static_cast<char>(c)) << "\'" << std::endl;
		}
		std::cout << "Integer: " << (static_cast<int>(c)) << std::endl;
		std::cout << "Float: " << (static_cast<float>(c)) << ".0f" << std::endl;
		std::cout << "Double: " << (static_cast<double>(c)) << ".0" << std::endl;
		return ;
	}

	double	number = getNumber(unit);
	bool	isIOverFlow = isIntOverflow(number);
	bool	isFOverFlow = isFloatOverFlow(number);

	if ((unitType & DOUBLE) || (unitType & FLOAT)){
		if ((number < std::numeric_limits<char>::min()) || (number > std::numeric_limits<char>::max())){
			std::cout << "Character: Impossible" << std::endl;
		} else if (!std::isprint(static_cast<unsigned char>(number))){
			std::cout << "Character: Not Displayable" << std::endl;
		} else{
			std::cout << "Character: \'" << (static_cast<char>(number)) << "\'" << std::endl;
		}
			if (isIOverFlow){
				std::cout << "Integer: Impossible" << std::endl;
			} else{
				std::cout << "Integer: " << (static_cast<int>(number)) << std::endl;
			}
			if (isFOverFlow){
				std::cout << "Float: Impossible" << std::endl;
			} else{
				std::cout << "Float: " << (static_cast<float>(number)) << "f" << std::endl;
			}
			std::cout << "Double: " << number << std::endl;
		return ;
	}
	if (unitType & INTEGER){
		if ((number < std::numeric_limits<char>::min()) || (number > std::numeric_limits<char>::max())){
			std::cout << "Character: Impossible" << std::endl;
		} else if (!std::isprint(static_cast<char>(number))){
			std::cout << "Character: Not Displayable" << std::endl;
		} else{
			std::cout << "Character: \'" << (static_cast<char>(number)) << "\'" << std::endl;
		}
			if (isIOverFlow){
				std::cout << "Integer: Impossible" << std::endl;
			} else{
				std::cout << "Integer: " << (static_cast<int>(number)) << std::endl;
			}
			if (isFOverFlow){
				std::cout << "Float: Impossible" << std::endl;
			} else{
				std::cout << "Float: " << (static_cast<float>(number)) << ".0f" << std::endl;
			}
			std::cout << "Double: " << number << ".0" << std::endl;
		return ;
	}
	throw ScalarConverter::InvalidUnitException();
}

const char *ScalarConverter::EmptyArgumentException::what() const throw(){
	return ("Argument Is Empty");
}

const char *ScalarConverter::InvalidUnitException::what() const throw(){
	return ("Unit Is Invalid");
}
