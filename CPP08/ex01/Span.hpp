/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:22:43 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/22 09:22:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span{

	private:
		std::vector<int> v;
		unsigned int N;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& right);
		Span& operator=(const Span& right);
		~Span();

		void addNumber(int n);
		template <typename Hamad>
		void addNumber(Hamad start, Hamad end){
			for (Hamad i = start; i != end; i++){
				try{
				this->addNumber(*i);
				} catch (std::exception& err){
					std::cerr << err.what() << std::endl;
				}
			}
		}

		int shortestSpan(void) const;
		int longestSpan(void) const;

		class SpanIsFullException: public std::exception{
			public:
				const char *what() const throw();
		};

		class NotEnoughElementsToBeASpanException: public std::exception{
			public:
				const char *what() const throw();
		};
};
#endif