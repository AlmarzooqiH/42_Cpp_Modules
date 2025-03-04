/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:19:13 by hamad             #+#    #+#             */
/*   Updated: 2025/03/04 14:04:47 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

static int account_id = 0;

Account::Account(void)
{
    _accountIndex = account_id;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    account_id++;
    _nbAccounts++;
}
Account::Account(int inital_deposit)
{
    if (inital_deposit > 0)
    {
        _amount = inital_deposit;
        _accountIndex = account_id;
        _nbDeposits = 1;
        _nbWithdrawals = 0;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
        account_id++;
        _nbAccounts++;
        _totalAmount += inital_deposit;
        return ;
    }
}
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void    Account::_displayTimestamp(void)
{
    std::cout << "[CurrentDate_CurrentTime] ";
}

void	Account::makeDeposit(int deposit){
    if (deposit > 0)
    {
        _displayTimestamp();
        _nbDeposits++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
        _amount += deposit;
        _totalNbDeposits++;
        _totalAmount += deposit;
        return ;
    }
}
bool	Account::makeWithdrawal(int withdrawal){
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    return (true);
}

int		Account::checkAmount(void) const{
    return (_amount);
}

void	Account::displayStatus(void) const{
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void){
    return (_nbAccounts);
}
int	Account::getTotalAmount(void){
    return (_totalAmount);
}
int	Account::getNbDeposits(void){
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void){
    return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}