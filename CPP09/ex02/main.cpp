/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:25:35 by hamalmar          #+#    #+#             */
/*   Updated: 2025/12/12 16:00:00 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void printVectorSpace(const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 != v.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av) {
    try {
        PmergeMe pmerge(ac, av);
        std::vector<int> vec = pmerge.getVec();
        std::deque<int> deq = pmerge.getDeq();

        std::cout << "Before: ";
        printVectorSpace(vec);

		clock_t vecStart = clock();
        vec = pmerge.FordJohnsonSortVec(vec);
        clock_t vecEnd = clock();
        double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1e6;

        std::cout << "After: ";
        printVectorSpace(vec);

        clock_t deqStart = clock();
        deq = pmerge.FordJohnsonSortDeq(deq);
        clock_t deqEnd = clock();
        double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
        
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
