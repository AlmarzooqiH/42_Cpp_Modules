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

PmergeMe::PmergeMe(const PmergeMe& right)
:
vec(right.vec),
deq(right.deq)
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& right){
	if (this != &right){
		this->vec = right.vec;
		this->deq = right.deq;
	}
	return (*this);
}

bool	PmergeMe::elementExsist(long num){
	for (std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end(); ++it){
		if (*it == num)
			return (true);
	}
	return (false);
}

static bool	containsNonDigits(const std::string& str){
	for (size_t i = 0; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return (true);
	}
	return (false);
}

void	PmergeMe::populateContainers(int ac, char** av){
	for (int i = 1; i < ac; i++){
		long currentElement = 0;
		std::string argument(av[i]);
		if (argument.empty() || containsNonDigits(argument))
			throw (PmergeMe::GenericErrorException());
		std::istringstream(argument) >> currentElement;
		if (currentElement <= 0 || currentElement > std::numeric_limits<int>::max() || elementExsist(currentElement))
			throw (PmergeMe::GenericErrorException());
		this->vec.push_back(static_cast<int>(currentElement));
		this->deq.push_back(static_cast<int>(currentElement));
	}
}

PmergeMe::PmergeMe(int ac, char** av){
	if (ac < 2)
		throw (PmergeMe::GenericErrorException());
	populateContainers(ac, av);
}

PmergeMe::~PmergeMe(){}


void	PmergeMe::FordJohnsonSortVec(void){

}

void	PmergeMe::FordJohnsonSortDeq(void){

}

const char	*PmergeMe::GenericErrorException::what() const throw(){
	return ("Error");
}