/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:47:14 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/27 19:47:01 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
	public:
		MutantStack();
		MutantStack(const MutantStack& right);
		MutantStack& operator=(const MutantStack& right);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator revIterator;

		iterator begin(void);
		iterator end(void);

		revIterator rbegin(void);
		revIterator rend(void);

};

# include "MutantStack.tpp"

#endif