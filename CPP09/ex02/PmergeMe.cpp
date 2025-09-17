/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:16:32 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/17 22:16:32 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& right):
inputNumbers(right.inputNumbers)
{}

PmergeMe::PmergeMe(const std::string& inputString){
	if (inputNumbers.empty())
		throw (PmergeMe::EmptyInputException());
	this->inputNumbers = inputNumbers;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& right){
	if (this != &right){
		this->inputNumbers = right.inputNumbers;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}


const char	*PmergeMe::EmptyInputException::what() const throw(){
	return ("Input cannot be Empty. Example input: ./PmergeMe \"10 8 2003 42 199 2342 3\"");
}
