/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:02:01 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/17 22:02:01 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <string>
# include <sstream>
# include <limits>

class PmergeMe{

	private:
		std::vector<int> vec;
		std::deque<int> deq;

		PmergeMe();
		PmergeMe(const PmergeMe& right);
		PmergeMe& operator=(const PmergeMe& right);

		void	populateContainers(int ac, char** av);
		bool	elementExsist(long num);
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void	FordJohnsonSortVec(void);
		void	FordJohnsonSortDeq(void);

		class GenericErrorException: public std::exception{
			public:
				const char *what() const throw();
		};
};

#endif