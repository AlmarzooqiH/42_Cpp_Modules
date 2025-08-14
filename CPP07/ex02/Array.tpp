/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:23:42 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/14 20:46:23 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


template <typename T>
Array<T>::Array() : arr(NULL), tSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n){
    if (n <= 0){
        this->arr = NULL;
        this->tSize = 0;
        return ;
    }
    this->arr = new T[n];
    tSize = n;
}

template <typename T>
Array<T>::Array(const Array& right){
    if (right.tSize == 0){
        this->arr = NULL;
        this->tSize = 0;
        return ;
    }
    this->tSize = right.tSize;
    this->arr = new T[this->tSize];
    for (unsigned int i = 0; i < this->tSize; i++){
        this->arr[i] = right.arr[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& right){
    if (this != &right){
        if (right.tSize == 0){
            delete[] this->arr;
            this->arr = NULL;
            this->tSize = 0;
            return (*this);
        }
        delete[] this->arr;
        this->tSize = right.tSize;
        this->arr = new T[this->tSize];
        for (unsigned int i = 0; i < this->tSize; i++){
            this->arr[i] = right.arr[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(){
    delete[] this->arr;
    this->tSize = 0;
}

template <typename T>
unsigned int Array<T>::size(void) const{
    return (this->tSize);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
    if (index >= this->tSize)
        throw std::exception();
    return (this->arr[index]);
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
    if (index >= this->tSize)
        throw std::exception();
    return (this->arr[index]);
}