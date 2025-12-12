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

std::vector<int>&	PmergeMe::getVec(void){ return (this->vec);}
std::deque<int>&	PmergeMe::getDeq(void){ return (this->deq);}

std::vector<int>	PmergeMe::FordJohnsonSortVec(std::vector<int>& vec){
	if (vec.size() == 1)
		return (vec);
	int alone = 0;
	if (vec.size() % 2 == 1){
		alone = vec.back();
		vec.pop_back();
	}
	std::vector<int> big;
	std::vector<int> smol;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it +=2 ){
		if (*it > *(it + 1)) {
			big.push_back(*it);
			smol.push_back(*(it + 1));
		} else {
			big.push_back(*(it + 1));
			smol.push_back(*it);
		}
	}
	big = FordJohnsonSortVec(big);
	
	return (big);
}

std::deque<int>	PmergeMe::FordJohnsonSortDeq(std::deque<int>& deq){
	if (deq.size() == 1)
		return (deq);
	int alone = 0;
	if (deq.size() % 2 == 1){
		alone = deq.back();
		deq.pop_back();
	}
	std::deque<int> big;
	std::deque<int> smol;

	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it +=2 ){
		if (*it > *(it + 1)) {
			big.push_back(*it);
			smol.push_back(*(it + 1));
		} else {
			big.push_back(*(it + 1));
			smol.push_back(*it);
		}
	}
	big = FordJohnsonSortDeq(big);
	return (big);
}

const char	*PmergeMe::GenericErrorException::what() const throw(){
	return ("Error");
}