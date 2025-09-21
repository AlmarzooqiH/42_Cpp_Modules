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

void PmergeMe::myInsertionSort(std::vector<int>& vec){
	for (size_t i = 1; i < vec.size(); i++){
		int key = vec[i];

		int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
	}
}

void PmergeMe::myMerge(std::vector<int>& vec, std::vector<int>& leftVec, std::vector<int>& rightVec){
	size_t leftPos = 0;
	size_t rightPos = 0;
	for (size_t i = 0; i < vec.size(); i++) {
        if (leftPos < leftVec.size() && (rightPos >= rightVec.size() || leftVec[leftPos] <= rightVec[rightPos])) {
            vec[i] = leftVec[leftPos];
			leftPos++;
        } else {
            vec[i] = rightVec[rightPos];
			rightPos++;
        }
	}
}

void PmergeMe::myMergeSort(std::vector<int>& vec){
	if (vec.size() <= 1)
		return ;
	if (vec.size() <= SWITCH_THRESHOLD){
		myInsertionSort(vec);
		return ;
	}
	std::vector<int> leftVec;
	std::vector<int> rightVec;

	size_t	midPos = vec.size() / 2;
	for (size_t i = 0; i < vec.size(); i++){
		if (i < midPos){
			leftVec.push_back(vec[i]);
		} else {
			rightVec.push_back(vec[i]);
		}
	}
	myMergeSort(leftVec);
	myMergeSort(rightVec);
	myMerge(vec, leftVec, rightVec);
}

/* OVERLOADING FUNCTIONS*/

void PmergeMe::myInsertionSort(std::deque<int>& deq){
	for (size_t i = 1; i < deq.size(); i++){
		int key = deq[i];

		int j = i - 1;
        while (j >= 0 && deq[j] > key) {
            deq[j + 1] = deq[j];
            j = j - 1;
        }
        deq[j + 1] = key;
	}
}

void PmergeMe::myMerge(std::deque<int>& deq, std::deque<int>& leftDeq, std::deque<int>& rightDeq){
	size_t leftPos = 0;
	size_t rightPos = 0;
	for (size_t i = 0; i < deq.size(); i++) {
        if (leftPos < leftDeq.size() && (rightPos >= rightDeq.size() || leftDeq[leftPos] <= rightDeq[rightPos])) {
            deq[i] = leftDeq[leftPos];
			leftPos++;
        } else {
            deq[i] = rightDeq[rightPos];
			rightPos++;
        }
	}
}

void PmergeMe::myMergeSort(std::deque<int>& deq){
	if (deq.size() <= 1)
		return ;
	if (deq.size() <= SWITCH_THRESHOLD){
		myInsertionSort(deq);
		return ;
	}
	std::deque<int> leftDeq;
	std::deque<int> rightDeq;

	size_t	midPos = deq.size() / 2;
	for (size_t i = 0; i < deq.size(); i++){
		if (i < midPos){
			leftDeq.push_back(deq[i]);
		} else {
			rightDeq.push_back(deq[i]);
		}
	}
	myMergeSort(leftDeq);
	myMergeSort(rightDeq);
	myMerge(deq, leftDeq, rightDeq);
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
