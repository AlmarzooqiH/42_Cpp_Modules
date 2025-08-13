/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:31:49 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/13 18:31:08 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): arr(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int size){
    this->arr = new T[size];
    this->_size = size;
}

template <typename T>
Array<T>::Array(const Array& right){
    if (right.arr == NULL){
        this->arr = NULL;
        this->_size = right._size;
        return ;
    }
    this->_size = right._size;
    this->arr = new T[this->_size];
    for (unsigned int i = 0; i < right._size; i++){
        this->arr[i] = right.arr[i];
    }
}

template <typename T>
T& Array<T>::operator=(const Array& right){
    if (this != *right){
        if (right.arr == NULL){
            this->arr = NULL;
            this->_size = right._size;
            return (*this);
        }
        this->_size = right._size;
        this->arr = new T[this->_size];
        for (unsigned int i = 0; i < right._size; i++){
            this->arr[i] = right.arr[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(){
    this->_size = 0;
    delete[] this->array;
}

template <typename T>
unsigned int Array<T>::size(void) const{return (this->_size);}