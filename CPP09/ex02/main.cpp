/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:25:35 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/21 15:25:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

template <typename Hamad>
void printContainer(Hamad& vec) {
    std::cout << "container = {";

    typename Hamad::iterator it = vec.begin();
    for (; it != vec.end(); ++it) {
        typename Hamad::iterator next = it;
        ++next;
        std::cout << *it;
        if (next != vec.end())
            std::cout << ", ";
    }

    std::cout << "}" << std::endl;
}


int main(int ac, char **av){
	if (ac < 2){
		std::cerr << "Input mustt be ./PmergeMe n1 n2 n2 .... Nn" << std::endl;
		return (2);
	}
	try{
		PmergeMe yes(ac, av);
		
		std::vector<int> vContainer = yes.getVector();
		// std::cout << "Before: "; printContainer(vContainer);
		clock_t vectorStart = clock();
		// yes.myMergeSort(vContainer);
		yes.fordJhonsonSort(vContainer);
		clock_t vectorEnd = clock();
		std::cout << "After: "; printContainer(vContainer);
		std::cout << "Time to process a range of " << vContainer.size() \
			<< " elements with std::vector: " <<  (static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC) << "us" << std::endl;
		std::deque<int> dContainer = yes.getDeque();
		clock_t deqStart = clock();
		yes.fordJhonsonSort(dContainer);
		clock_t deqEnd = clock();
		std::cout << "Time to process a range of " << dContainer.size() \
			<< " elements with std::deque: " <<  (static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC) << "us" << std::endl;
		
	} catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
