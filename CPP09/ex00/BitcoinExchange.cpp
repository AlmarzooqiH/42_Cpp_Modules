/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:06:36 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/08 17:50:32 by hamalmar         ###   ########.fr       */
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


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string& fileName){
	this->fName = fileName;
	this->inputFile.open(this->fName.c_str());
	if (!this->inputFile)
		throw (BitcoinExchange::FileDoesNotExistException());
	std::ifstream databaseCSV(DBLOC);
	if (!databaseCSV)
		throw (BitcoinExchange::DatabaseMissingException());
	std::string tmpLine;
	while (std::getline(databaseCSV, tmpLine)){
		if (tmpLine.empty())
			continue ;
		size_t commaPos = tmpLine.find(',');
		if (commaPos == std::string::npos)
			throw (BitcoinExchange::InvalidDatabaseFormatException());
		float value = 0;
		std::string date = tmpLine.substr(0, commaPos);
		std::istringstream(tmpLine.substr(commaPos + 1)) >> value;
		this->database[date] = value;
	}
	databaseCSV.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& right){
	this->database = right.database;
	this->fName = right.fName;
	if (this->inputFile.is_open())
		this->inputFile.close();
	this->inputFile.open(this->fName.c_str());
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& right){
	if (this != &right){
		this->fName = right.fName;
		this->database = right.database;
		if (this->inputFile.is_open())
			this->inputFile.close();
		this->inputFile.open(this->fName.c_str());
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
	this->inputFile.close();

}

void BitcoinExchange::parseInput(){
}

const char	*BitcoinExchange::DatabaseMissingException::what() const throw() {
	return ("Database file is missing. (data.csv)");
}

const char	*BitcoinExchange::InvalidDatabaseFormatException::what() const throw() {
	return ("Database format is invalid");
}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
	return ("The date is wrong");
}

const char *BitcoinExchange::InvalidDateFormatException::what() const throw() {
	return ("The provided date is in the wrong format, it should be in the following format: YYYY-MM-DD");
}

const char *BitcoinExchange::InvalidBitcoinValueException::what() const throw() {
	return ("Bitcoin value must be from 0 to 1000");
}

const char *BitcoinExchange::FileDoesNotExistException::what() const throw() {
	return ("File does not exist");
}
