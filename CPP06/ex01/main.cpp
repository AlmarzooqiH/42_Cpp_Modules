/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:58:00 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/10 22:50:41 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

void printAllData(Data* head) {
	if (!head)
		return ;

    Data* current = head;
	size_t	i = 0;
    while (current != NULL) {
		std::cout << "Data[" << i <<"]: " << current->contents << "\tAddress: " << current << std::endl;
		i++;
		current = current->next;
    }
}

int main(void){

    Data* head = new Data();
    Data* shoulders = new Data();
    Data* knees = new Data();
    Data* toes = new Data();
    uintptr_t headSerialized = 0;
    head->contents = "Head";
    head->next = shoulders;
    shoulders->contents = "Shoulders";
    shoulders->next = knees;
    knees->contents = "Knees";
    knees->next = toes;
    toes->contents = "Toes";
    toes->next = NULL;
    std::cout << "Data Before Serialization" << std::endl;
    printAllData(head);
    std::cout << std::endl;
    headSerialized = Serializer::serializer(head);
    std::cout << "Serialized head: " << headSerialized << std::endl;
    std::cout << std::endl;
    
    Data* headDeSerialized = Serializer::deserialize(headSerialized);
    std::cout << "Data After Serialization" << std::endl;
    printAllData(headDeSerialized);
    std::cout << std::endl;
    delete head;
    delete shoulders;
    delete knees;
    delete toes;
    return (0);
}
