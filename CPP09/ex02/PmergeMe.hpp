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

class PmergeMe{

	private:
		std::string inputNumbers;
		PmergeMe();
		PmergeMe(const PmergeMe& right);
		PmergeMe& operator=(const PmergeMe& right);
	
	
	public:
		PmergeMe(const std::string& inputNumbers);
		~PmergeMe();

		class EmptyInputException: public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif