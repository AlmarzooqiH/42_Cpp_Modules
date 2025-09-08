/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:02:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/08 22:36:17 by hamalmar         ###   ########.fr       */
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

# define DBLOC "./data.csv"

class BitcoinExchange{

    private:
        std::string fName;
        std::ifstream inputFile;
        std::map<std::string, float> database;
        BitcoinExchange();
        void parseInputFile(void);

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