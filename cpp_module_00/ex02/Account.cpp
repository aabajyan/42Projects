/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:41:03 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 16:28:24 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.h"
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit
            << ";created\n";
}

Account::Account() {
  _accountIndex = _nbAccounts++;
  _amount = 0;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:0;created\n";
}

Account::~Account() {
  _displayTimestamp();
  _nbAccounts--;
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";closed\n";
}

void Account::_displayTimestamp() {
  struct tm *time_info;
  time_t raw_time;

  time(&raw_time);
  time_info = localtime(&raw_time);
  std::cout << std::setfill('0') << "[" << time_info->tm_year + 1900
            << std::setw(2) << time_info->tm_mon + 1 << std::setw(2)
            << time_info->tm_mday << "_" << std::setw(2) << time_info->tm_hour
            << std::setw(2) << time_info->tm_min << std::setw(2)
            << time_info->tm_sec << "] ";
}

void Account::displayStatus() const {
  Account::_displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << "\n";
}

void Account::displayAccountsInfos() {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts
            << ";total:" << Account::_totalAmount
            << ";deposits:" << Account::_totalNbDeposits
            << ";withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  _totalAmount += deposit;
  _totalNbDeposits++;
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  _amount += deposit;
  std::cout << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << ++_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";";
  if (_amount < withdrawal) {
    std::cout << "withdrawal:refused\n";
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  _nbWithdrawals++;
  std::cout << "withdrawal:" << withdrawal << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << "\n";
  return true;
}
