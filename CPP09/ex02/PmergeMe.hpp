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
# include <exception>
# include <vector>
# include <deque>
# include <ctime>
# include <string>
# include <sstream>
# include <limits>
# include <ctime>
# define SWITCH_THRESHOLD 32

class PmergeMe{

	private:
		PmergeMe();
		PmergeMe(const PmergeMe& right);
		PmergeMe& operator=(const PmergeMe& right);
		std::vector<std::string> input;
		std::vector<int>	vectorContainer;
		std::deque<int>		dequeContainer;
		void parseInput(void);
		void fordJhonsonMerge(std::vector<int>& vec, int val);
		void fordJhonsonMerge(std::deque<int>& deq, int val);

	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void fordJhonsonSort(std::vector<int>& vec);
		void fordJhonsonSort(std::deque<int>& deq);

		std::vector<int> getVector(void) const;
		std::deque<int> getDeque(void) const;

		class EmptyInputException: public std::exception {
			public:
				const char *what() const throw();
		};

		class IntegerOverFlowException: public std::exception{
			public:
				const char *what() const throw();
		};

		class NegativeNumberException: public std::exception{
			public:
				const char *what() const throw();
		};

		class DuplicateNumberException: public std::exception{
			public:
				const char *what() const throw();
		};
};

#endif