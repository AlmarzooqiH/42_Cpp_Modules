/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:21:49 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 14:27:10 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>

bool	validateContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecret);
bool	ft_isdigit(char c);
#endif