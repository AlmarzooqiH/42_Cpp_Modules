/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:21:49 by hamad             #+#    #+#             */
/*   Updated: 2025/03/17 08:32:42 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>

bool	validateContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecret);
bool	ft_isdigit(char c);
#endif