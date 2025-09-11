/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:06:36 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/11 23:39:00 by hamalmar         ###   ########.fr       */
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
 * @brief This function will check if the passed in date complies
 * with YYYY-MM-DD format.
 * 
 * @param date The date lol.
 * @return True if the date is in the proper format; false otherwise.
 */
static bool	checkDateFormat(std::string& date, size_t& mD, size_t& dD){
	if (date.empty())
		return (false);
	size_t i = 0;
	size_t yearCount = 0;
	size_t monthCount = 0;
	size_t dayCount = 0;
	while ((i < date.length()) && (date[i] != '-')){
		yearCount++;
		i++;
	}
	if ((i < date.length()) && date[i] == '-') {
		mD = i;
		i++;
	}
	while ((i < date.length()) && (date[i] != '-')){
		monthCount++;
		i++;
	}
	if ((i < date.length()) && date[i] == '-') {
		dD = i;
		i++;
	}
	while ((i < date.length()) && (date[i] != '-')){
		dayCount++;
		i++;
	}
	return (
		(yearCount >= 4) &&
		((monthCount > 0) && (monthCount <= 2)) &&
		((dayCount > 0) && (dayCount <= 2)) &&
		(i == date.length())
	);
}

/**
 * @brief This function will check if the passed in date is a proper date.
 * 
 * @param date The date lol.
 * @return True if the date is in the proper; false otherwise.
 */
static bool	checkPossibleDate(std::string& date, size_t& mD, size_t& dD){
	if (date.empty())
		return (false);
	int year = 1;
	int month = 1;
	int day = 1;

	std::istringstream(date.substr(0, mD)) >> year;
	std::istringstream(date.substr(mD + 1, date.length() - dD - 1)) >> month;
	std::istringstream(date.substr(dD + 1)) >> day;
	// std::cout << "Year substr: " << date.substr(0, mD) << std::endl;
	// std::cout << "Month substr: " << date.substr(mD + 1, date.length() - dD - 1) << std::endl;
	// std::cout << "Day substr: " << date.substr(dD + 1) << std::endl;
	// std::cout << "Year: " << year << std::endl;
	// std::cout << "Month: " << month << std::endl;
	// std::cout << "Day: " << day << std::endl << std::endl;

	if (year < 1 || ((month < 1) || (month > 12)))
		return (false);
	
	if (month == 2){
		if ((year % 4 != 0) && (year % 100 == 0) && (year % 400 == 0)) {
			if ((day < 1) || (day > 29))
				return (false);
			} else {
				if ((day < 1) || (day > 28))
					return (false);
			}
			return (true);
	}
	if ((day < 1) || (day > 31))
		return (false);
	return (true);
}
// std::cout << "Key: " << start->first << ": " << start->second << std::endl;
std::string BitcoinExchange::getClosestDate(const std::string& date) {
	std::map<std::string, float>::const_iterator start = this->database.begin();
	int dYear, dMonth, dDay,
		dbYear, dbMonth, dbDay;

	std::istringstream(date.substr(0, 4)) >> dYear;
	std::istringstream(date.substr(5, 2)) >> dMonth;
	std::istringstream(date.substr(8,2)) >> dDay;
	while (start != this->database.end()){

	std::istringstream(static_cast<std::string>(start->first).substr(0, 4)) >> dbYear;
	std::istringstream(static_cast<std::string>(start->first).substr(5, 2)) >> dbMonth;
	std::istringstream(static_cast<std::string>(start->first).substr(8,2)) >> dbDay;
		if ((dbYear == dYear) && (dbMonth == dMonth) && (dbDay > dDay)){
			if (start != this->database.begin())
				start--;
			return (start->first);
		}
		start++;
	}
	if (start == this->database.end())
		start = this->database.begin();
	return (start->first);
}

void	BitcoinExchange::parseInputFile(void){
	std::string inputTmp;
	float value = 0.0;
	size_t mD = 0;
	size_t dD = 0;
	bool hasValue = false;
	bool dateInDB = false;
	while (std::getline(this->inputFile, inputTmp)){
		if (inputTmp.empty() || !std::isdigit(static_cast<int>(inputTmp[0])))
			continue ;
		size_t pipePos = inputTmp.find('|');
		hasValue =  !(pipePos == std::string::npos);
		if (!hasValue)
			continue;
		std::string inputDate;
		if (hasValue)
			inputDate = inputTmp.substr(0, pipePos - 1);
		else
			inputDate = std::string(inputTmp);
		dateInDB = (this->database.find(inputDate) != this->database.end());
		if (!checkDateFormat(inputDate, mD, dD) || !checkPossibleDate(inputDate, mD, dD)){
			hasValue = false;
			std::cerr << "Error: bad input => " << inputDate << std::endl;
			continue ;
		}
		if (hasValue){
			std::istringstream(inputTmp.substr(pipePos + 1)) >> value;
			if (value <= std::numeric_limits<int>::min() || value >= std::numeric_limits<int>::max()){
				std::cerr << "Error: too large a number." << std::endl;
				hasValue = false;
				dateInDB = false;
				continue ;
			}
			if (value < 0 || value > 1000){
				std::cerr << "Error: not a positive number." << std::endl;
				hasValue = false;
				dateInDB = false;
				continue ;
			}

			if (!dateInDB) {
				std::cout << inputDate << " => " << value << " => " << this->database[getClosestDate(inputDate)] * value << std::endl;
			} else {
				std::cout << inputDate << " => " << value << " => " << this->database[inputDate] * value << std::endl;
			}
			hasValue = false;
			dateInDB = false;
			value = 0.0;
		}
	}
}
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
		if (tmpLine.empty() || !std::isdigit(static_cast<int>(tmpLine[0])))
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
	parseInputFile();
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

const char *BitcoinExchange::InvalidInputFileException::what() const throw(){
	return ("The input file is not in proper format. (Date | Value)");
}
