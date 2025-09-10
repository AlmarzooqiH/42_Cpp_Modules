/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:02:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/10 22:29:34 by hamalmar         ###   ########.fr       */
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
# include <sstream>
# include <limits>

# define DBLOC "./data.csv"

class BitcoinExchange{

    private:
        std::string fName;
        std::ifstream inputFile;
        std::map<std::string, float> database;
        BitcoinExchange();
        void parseInputFile(void);
        float getClosestValue(const std::string& date) const;

    public:
        BitcoinExchange(std::string& filename);
        BitcoinExchange(const BitcoinExchange& right);
        BitcoinExchange& operator=(const BitcoinExchange& right);
        ~BitcoinExchange();

        class DatabaseMissingException: public std::exception{
            public:
                const char *what() const throw();
        };

        class InvalidDatabaseFormatException: public std::exception{
            public:
                const char *what() const throw();
        };

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

        class InvalidInputFileException: public std::exception{
            public:
                const char *what() const throw();
        };
};


#endif