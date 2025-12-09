/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:06:36 by hamalmar          #+#    #+#             */
/*   Updated: 2025/12/10 01:00:42 by hamalmar         ###   ########.fr       */
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

/**
 * @brief This function will take the extracted date and will check if it is a valid one.
 * @param year The year that we will check.
 * @param month The month that we will check.
 * @param day The day that we will check.
 * @return True if the date is valid, false otherwise.
 * @author Hamad Almarzooqi
 */
bool	BitcoinExchange::checkPossibleDate(const std::string &year, const std::string &month, const std::string &day){
	if (year.empty() || month.empty() || day.empty())
		return (false);
	int iYear, iMonth, iDay = 0;
	std::stringstream(year) >> iYear;
	std::stringstream(month) >> iMonth;
	std::stringstream(day) >> iDay;
	if (iYear < 0)
		return (false);
	if (iMonth < 1 || iMonth > 12)
		return (false);

	if (iDay < 1 || iDay > 31)
		return (false);

	if (iMonth == 2){
		if ((iYear % 4 == 0) && (iYear % 100 != 0 || iYear % 400 == 0)){
			if (iDay > 29)
				return (false);
		} else {
			if (iDay > 28)
				return (false);
		}
		return (true);
	}
	if (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11){
		if (iDay > 30)
			return (false);
		return (true);
	}
	return (true);
}


/**
 * @brief This function will extract the date from the string that is the following format: YYYY-MM-DD.
 * @param date The date string that we want to extract it from.
 * @param year We will store the extracted year here.
 * @param month We will store the extracted month here.
 * @param day We will store the extracted day here.
 * @return True if everything is correct, false otherwise.
 * @author Hamad Almarzooqi
 */
bool	extractDate(const std::string& date, std::string& year, std::string& month, std::string& day){
	if (date.empty())
		return (false);
	size_t firstDashPos = date.find('-');
	if (firstDashPos == std::string::npos)
		return (false);
	size_t secondDashPos = date.find('-', firstDashPos + 1);
	if (secondDashPos == std::string::npos)
		return (false);
	year  = date.substr(0, firstDashPos);
	month = date.substr(firstDashPos + 1, secondDashPos - firstDashPos - 1);
	day   = date.substr(secondDashPos + 1);
	return (true);
}

bool	BitcoinExchange::checkDateFormat(const std::string& date, bool dboi){
	if (date.empty())
		return (false);
	std::string year;
	std::string month;
	std::string day;
	if (!extractDate(date, year, month, day)){
		std::cout << "Error: Could not extract the date from: " << date << std::endl;
		return (false);
	}
	if (!checkPossibleDate(year, month, day)){
		if (dboi)
			std::cout << "Error: Date is invalid: " << date << std::endl;
		return (false);
	}
	return (true);
}

std::string BitcoinExchange::getClosestDate(const std::string& inDate) {
	std::string closest = this->cryptoWallet.begin()->first;
	for(std::map<std::string, float>::iterator it = this->cryptoWallet.begin(); it != this->cryptoWallet.end(); ++it){
		if (it->first <= inDate && it->first > closest)
			closest = it->first;
	}
	return (closest);
}

/**
 * @brief This function will parse the input file and compute to the expected result.
 * @return void.
 * @author Hamad Almarzooqi
 */
void	BitcoinExchange::parseInputFile(void){
	if (!this->inputFile.is_open())
		throw (BitcoinExchange::FileDoesNotExistException());
	std::string dateBuffer;
	bool skipFirstLine = true;
	while (std::getline(this->inputFile, dateBuffer)){
		if (skipFirstLine){
			skipFirstLine = false;
			continue ;
		}
		if (dateBuffer.empty())
			break;
		size_t	pipePos = dateBuffer.find('|');
		std::string date = dateBuffer.substr(0, pipePos);

		if (pipePos == std::string::npos){
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!checkDateFormat(date, false)){
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		float value;
		std::istringstream(dateBuffer.substr(pipePos + 1)) >> value;
		if (value < 0){
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000){
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		std::cout << date << " => " << value << " = " << this->cryptoWallet[getClosestDate(date)] * value << std::endl;
	}
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
		if (skipFirstLine){
			skipFirstLine = false;
			continue ;
		}
		if (dateBuffer.empty())
			break;
		size_t	commaPos = dateBuffer.find(',');
		if (commaPos == std::string::npos){
			std::cout << "Invalid DB format: " << dateBuffer << std::endl;
			continue;
		}
		std::string date = dateBuffer.substr(0, commaPos);
		if (!checkDateFormat(date, true)){
			continue;
		}
		float value;
		std::istringstream(dateBuffer.substr(commaPos + 1)) >> value;
		if (value < 0){
			std::cout << "Invalid Value: " << value << std::endl;
			continue;
		}
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
	parseInputFile();
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
	if (this->inputFile.is_open())
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
