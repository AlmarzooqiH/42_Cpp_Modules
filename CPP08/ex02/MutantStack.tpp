/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:32:13 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/27 20:01:54 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& right)
: std::stack<T>(right) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& right) {
    if (this != &right)
        std::stack<T>::operator=(right);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void){return (this->c.begin());}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void){return (this->c.end());}

template <typename T>
typename MutantStack<T>::revIterator MutantStack<T>::rbegin(void){return (this->c.rbegin());}

template <typename T>
typename MutantStack<T>::revIterator MutantStack<T>::rend(void){return (this->c.rend());}

