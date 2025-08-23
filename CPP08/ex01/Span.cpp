/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:35:50 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/22 09:35:50 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): v(), N(0){}

Span::Span(unsigned int N): v(), N(N){
	this->v.reserve(N);
}

Span::Span(const Span& right){
	this->N = right.N;
	this->v = right.v;
}

Span& Span::operator=(const Span& right){
	if (this != &right){
		this->N = right.N;
		this->v = right.v;
	}
	return (*this);
}

Span::~Span(){
	this->N = 0;
}

void Span::addNumber(int n){
	if (this->v.size() == this->v.capacity())
		throw (Span::SpanIsFullException());
	this->v.push_back(n);
}

int Span::shortestSpan(void) const{
	if (this->v.size() < 2)
		throw (Span::NotEnoughElementsToBeASpanException());

	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	int shortest = tmp.at(1) - tmp.at(0);
	for (size_t i = 1; i < (tmp.size() - 1); i++){
		int tmpDiff = tmp.at(i + 1) - tmp.at(i); 
		if (tmpDiff< shortest)
			shortest = tmpDiff;
	}
	return (shortest);
}

int Span::longestSpan(void) const{
	if (this->v.size() < 2)
		throw (Span::NotEnoughElementsToBeASpanException());

	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}
//This function might be used in the evaluation for visualization only.
// void	Span::printSpan(void) const{
// 	std::cout << "Span{";
// 	for (size_t i = 0; i < this->v.size(); i++){
// 		if (i == this->v.size() - 1){
// 			std::cout << this->v[i];
// 			break ;
// 		}
// 		std::cout << this->v[i] << ", ";
// 	}
// 	std::cout << "}" << std::endl;
// }

const char *Span::SpanIsFullException::what() const throw(){
	return ("The Span is full. Cannot add more elements.");
}

const char *Span::NotEnoughElementsToBeASpanException::what() const throw(){
	return ("The Span does not have enough elements to be considered as a span.");
}