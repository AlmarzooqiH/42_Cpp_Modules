/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:06:36 by hamalmar          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:38 by hamalmar         ###   ########.fr       */
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

size_t	countOccourance(const std::string& s, char c){
	size_t	count = 0;
	for (size_t i = 0; i < s.length(); i++){
		if (s[i] == c)
			count++;
	}
	return (count);
}


bool	BitcoinExchange::checkPossibleDate(const std::string& date){
	(void)date;
	return (false);
}

void	extractDate(const std::string& date, std::string& year, std::string& month, std::string& day){
	size_t	dashPos = date.find('-');
	size_t	begin = 0;
	size_t	tmp = 0;
	if (dashPos == std::string::npos)
		throw (BitcoinExchange::InvalidDatabaseFormatException());
	year = date.substr(begin, dashPos);
	tmp = begin;
	begin = dashPos;
	dashPos = date.substr(tmp, dashPos).find('-');
	if (dashPos == std::string::npos)
		throw (BitcoinExchange::InvalidDatabaseFormatException());
	month = date.substr(begin, dashPos);
	day = date.substr(dashPos, date.size());
}

bool	BitcoinExchange::checkDateFormat(const std::string& date){
	if (date.empty())
		return (false);
	std::string year;
	std::string month;
	std::string day;
	extractDate(date, year, month, day);
	std::cout << "Date is: {" << year << ", " << month << ", " << day << "}" << std::endl;
	return (true);
}

std::string BitcoinExchange::getClosestDate(const std::string& date) {
	(void)date;
	return ("");
}

/**
 * @brief This function will parse the input file and compute to the expected result.
 * @return void.
 * @author Hamad Almarzooqi
 */
void	BitcoinExchange::parseInputFile(void){
}

BitcoinExchange::BitcoinExchange(){}

/**
 * @brief This function will parse the DB and store the dates with the corresp-
 * -onding values to the cryptoWallet.
 * @return void
 * @author Hamad Almarzooqi
 */
void	BitcoinExchange::parseDB(std::ifstream& databaseCSV){
	std::string dateBuffer;
	bool skipFirstLine = true;
	while (std::getline(databaseCSV, dateBuffer)){
		std::cout << "Here 1" << std::endl;
		if (skipFirstLine){
			skipFirstLine = false;
			continue ;
		}
		std::cout << "Here 2" << std::endl;
		if (dateBuffer.empty())
			break;
		std::cout << "Here 3" << std::endl;
		size_t	commaPos = dateBuffer.find(',');
		if (commaPos == std::string::npos)
			throw(BitcoinExchange::InvalidDatabaseFormatException());
		std::cout << "Here 4" << std::endl;
		std::string date = dateBuffer.substr(0, commaPos);
		if (!checkDateFormat(date))
			throw(BitcoinExchange::InvalidDatabaseFormatException());
		std::cout << "Here 5" << std::endl;
		float value;
		std::istringstream(dateBuffer.substr(commaPos)) >> value;
		if (value < 0)
			throw(BitcoinExchange::InvalidDatabaseFormatException());
		std::cout << "Here 6" << std::endl;
		this->cryptoWallet[date] = value;
		
	}
}

BitcoinExchange::BitcoinExchange(std::string& fileName){
	this->fName = fileName;
	this->inputFile.open(this->fName.c_str());
	if (!this->inputFile)
		throw (BitcoinExchange::FileDoesNotExistException());
	std::ifstream databaseCSV(DBLOC.c_str());
	if (!databaseCSV)
		throw (BitcoinExchange::DatabaseMissingException());
	parseDB(databaseCSV);
	databaseCSV.close();
	// parseInputFile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& right){
	this->cryptoWallet = right.cryptoWallet;
	this->fName = right.fName;
	if (this->inputFile.is_open())
		this->inputFile.close();
	this->inputFile.open(this->fName.c_str());
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& right){
	if (this != &right){
		this->fName = right.fName;
		this->cryptoWallet = right.cryptoWallet;
		if (this->inputFile.is_open())
			this->inputFile.close();
		this->inputFile.open(this->fName.c_str());
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
	this->inputFile.close();

}

const char	*BitcoinExchange::DatabaseMissingException::what() const throw() {
	return ("Database file is missing. (data.csv)");
}

const char	*BitcoinExchange::InvalidDatabaseFormatException::what() const throw() {
	return ("Database format is invalid");
}

const char *BitcoinExchange::FileDoesNotExistException::what() const throw() {
	return ("File does not exist");
}
