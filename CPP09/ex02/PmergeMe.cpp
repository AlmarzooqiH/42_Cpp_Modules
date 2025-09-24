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
input(right.input),
vectorContainer(right.vectorContainer),
dequeContainer(right.dequeContainer)
{}

void	PmergeMe::fordJhonsonMerge(std::vector<int>& vec, int val){
		std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), val);
		vec.insert(pos, val);
}

void	PmergeMe::fordJhonsonSort(std::vector<int>& vec){
	if (vec.size() <= 1)
		return ;
	int oneElement = -1;
	if (vec.size() % 2 != 0){
		oneElement = vec.at(vec.size() - 1);
		vec.pop_back();
	}

	std::vector<int> bigger;
	std::vector<int> smaller;
	for (size_t i = 0; i < vec.size(); i += 2){
		if (vec[i] > vec[i + 1]){
			bigger.push_back(vec[i]);
			smaller.push_back(vec[i + 1]);
		}
		else{
			bigger.push_back(vec[i + 1]);
			smaller.push_back(vec[i]);
		}
	}

	fordJhonsonSort(bigger);
	for (size_t i = 0; i < smaller.size(); i++){
		fordJhonsonMerge(bigger, smaller[i]);
	}

	if (oneElement != -1){
		fordJhonsonMerge(bigger, oneElement);
	}
	vec = bigger;
}

/* OVERLOADING FUNCTIONS*/

void	PmergeMe::fordJhonsonMerge(std::deque<int>& deq, int val){
		std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), val);
		deq.insert(pos, val);
}

void	PmergeMe::fordJhonsonSort(std::deque<int>& deq){
	if (deq.size() <= 1)
		return ;
	int oneElement = -1;
	if (deq.size() % 2 != 0){
		oneElement = deq.at(deq.size() - 1);
		deq.pop_back();
	}

	std::deque<int> bigger;
	std::deque<int> smaller;
	for (size_t i = 0; i < deq.size(); i += 2){
		if (deq[i] > deq[i + 1]){
			bigger.push_back(deq[i]);
			smaller.push_back(deq[i + 1]);
		}
		else{
			bigger.push_back(deq[i + 1]);
			smaller.push_back(deq[i]);
		}
	}

	fordJhonsonSort(bigger);
	for (size_t i = 0; i < smaller.size(); i++){
		fordJhonsonMerge(bigger, smaller[i]);
	}

	if (oneElement != -1){
		fordJhonsonMerge(bigger, oneElement);
	}
	deq = bigger;
}

void	PmergeMe::parseInput(void){
	int iMin = std::numeric_limits<int>::min();
	int iMax = std::numeric_limits<int>::max();
	for (size_t i = 0; i < this->input.size(); i++){
		long tmp = 0;
		std::istringstream(this->input[i]) >> tmp;
		if (tmp < 0)
			throw (PmergeMe::NegativeNumberException());
		else if (tmp < iMin || tmp > iMax)
			throw (PmergeMe::IntegerOverFlowException());
		int iTmp = static_cast<int>(tmp);
		this->vectorContainer.push_back(iTmp);
		this->dequeContainer.push_back(iTmp);
	}

	for (size_t i = 0; i < this->vectorContainer.size(); i++){
		int tmp = this->vectorContainer[i];
		for (size_t j = i + 1; j < this->vectorContainer.size(); j++){
			if (this->vectorContainer[j] == tmp)
				throw (PmergeMe::DuplicateNumberException());
		}
	}
}

PmergeMe::PmergeMe(int ac, char **av){
	if (!av || !av[0] || !av[0][0])
		throw (PmergeMe::EmptyInputException());
	for (int i = 1; i < ac; i++){
		this->input.push_back(av[i]);
	}
	parseInput();
}

PmergeMe& PmergeMe::operator=(const PmergeMe& right){
	if (this != &right){
		this->input = right.input;
		this->vectorContainer = right.vectorContainer;
		this->dequeContainer = right.dequeContainer;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

std::vector<int>	PmergeMe::getVector(void) const {return (this->vectorContainer);}
std::deque<int>	PmergeMe::getDeque(void) const {return (this->dequeContainer);}

const char	*PmergeMe::EmptyInputException::what() const throw(){
	return ("Input cannot be Empty. Example input: ./PmergeMe \"10 8 2003 42 199 2342 3\"");
}

const char	*PmergeMe::IntegerOverFlowException::what() const throw() {
	return ("Integer has overflown.");
}

const char	*PmergeMe::NegativeNumberException::what() const throw(){
	return ("Input must have only positive numbers");
}

const char	*PmergeMe::DuplicateNumberException::what() const throw(){
	return ("Numbers musn\'t be duplicated");
}
