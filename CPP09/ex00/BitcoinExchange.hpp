/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:02:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/31 00:32:38 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <exception>

class BitcoinExchange{
    public:
        class InvalidInputException: public std::exception{
            public:
                const char *what() const throw();
        };

        class InvalidArgumentException: public std::exception{
            public:
                const char *what() const throw();
        };
};


#endif