/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:02:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/03 18:28:13 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
            ########  #### ########  ######   #######  #### ##    ##    ######## ##     ##  ######  ##     ##    ###    ##    ##  ######   ######## 
            ##     ##  ##     ##    ##    ## ##     ##  ##  ###   ##    ##        ##   ##  ##    ## ##     ##   ## ##   ###   ## ##    ##  ##       
            ##     ##  ##     ##    ##       ##     ##  ##  ####  ##    ##         ## ##   ##       ##     ##  ##   ##  ####  ## ##        ##       
            ########   ##     ##    ##       ##     ##  ##  ## ## ##    ######      ###    ##       ######### ##     ## ## ## ## ##   #### ######   
            ##     ##  ##     ##    ##       ##     ##  ##  ##  ####    ##         ## ##   ##       ##     ## ######### ##  #### ##    ##  ##       
            ##     ##  ##     ##    ##    ## ##     ##  ##  ##   ###    ##        ##   ##  ##    ## ##     ## ##     ## ##   ### ##    ##  ##       
            ########  ####    ##     ######   #######  #### ##    ##    ######## ##     ##  ######  ##     ## ##     ## ##    ##  ######   ######## 
 */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <exception>
# include <fstream>
# include <string>

class BitcoinExchange{

    private:
        std::string fName;
        std::ifstream inputFile;
        std::map<std::string, float> dateAndValues;
        

    public:
        BitcoinExchange();
        BitcoinExchange(std::string& filename);
        BitcoinExchange(const BitcoinExchange& right);
        BitcoinExchange& operator=(const BitcoinExchange& right);
        ~BitcoinExchange();

        void    parseInput();
        class InvalidDateException: public std::exception{
            public:
                const char *what() const throw();
        };

        class InvalidDateFormatException: public std::exception{
            public:
                const char *what() const throw();
        };

        class InvalidBitcoinValueException: public std::exception{
            public:
                const char *what() const throw();
        };

        class FileDoesNotExistException: public std::exception{
            public:
                const char *what() const throw();
        };
};


#endif