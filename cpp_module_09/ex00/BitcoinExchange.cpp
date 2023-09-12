/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:53:50 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 19:11:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

const char *BitcoinExchange::EmptyDatabase::what() const throw() {
  return "Error: Empty database.";
}

const char *BitcoinExchange::UnableToOpenFile::what() const throw() {
  return "Error: Unable to open file.";
}

const char *BitcoinExchange::UnexpectedFormat::what() const throw() {
  return "Error: Bad format.";
}

const char *BitcoinExchange::InvalidExchangeRate::what() const throw() {
  return "Error: Invalid exchange rate.";
}

const char *BitcoinExchange::Date::InvalidDate::what() const throw() {
  return "Error: Invalid date.";
}

const char *BitcoinExchange::NumberTooLarge::what() const throw() {
  return "Error: Number too large";
}

BitcoinExchange::Date::Date() : m_year(1800), m_month(01), m_day(01) {}

BitcoinExchange::Date::Date(unsigned int year, unsigned int month,
                            unsigned int day)
    : m_year(year), m_month(month), m_day(day) {}

BitcoinExchange::Date::Date(const std::string &input) {
  std::stringstream stream(input);
  char temp;

  stream >> m_year;
  if (!(m_year >= 1800 && m_year <= 9999)) {
    throw InvalidDate();
  }

  stream >> temp;
  if (temp != '-') {
    throw InvalidDate();
  }

  stream >> m_month;
  if (!(m_month >= 1 && m_month <= 12)) {
    throw InvalidDate();
  }

  stream >> temp;
  if (temp != '-') {
    throw InvalidDate();
  }

  stream >> m_day;
  if (!(m_day >= 1 && m_day <= 31)) {
    throw InvalidDate();
  }

  // February
  if (m_month == 2) {
    if (((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0)) {
      // It's a leap year
      if (!(m_day <= 29)) {
        throw InvalidDate();
      }
    } else {
      if (!(m_day <= 28)) {
        throw InvalidDate();
      }
    }
  }

  // April, June, September and November
  if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11) {
    if (!(m_day <= 30)) {
      throw InvalidDate();
    }
  }
}

BitcoinExchange::Date::Date(const BitcoinExchange::Date &other)
    : m_year(other.m_year), m_month(other.m_month), m_day(other.m_day) {}

BitcoinExchange::Date::~Date() {}

BitcoinExchange::Date &
BitcoinExchange::Date::operator=(const BitcoinExchange::Date &other) {
  if (this != &other) {
    m_year = other.m_year;
    m_month = other.m_month;
    m_day = other.m_day;
  }
  return *this;
}

void BitcoinExchange::Date::setYear(unsigned int value) { m_year = value; }

void BitcoinExchange::Date::setMonth(unsigned int value) { m_month = value; }

void BitcoinExchange::Date::setDay(unsigned int value) { m_day = value; }

unsigned int BitcoinExchange::Date::getYear() const { return m_year; }

unsigned int BitcoinExchange::Date::getMonth() const { return m_month; }

unsigned int BitcoinExchange::Date::getDay() const { return m_day; }

bool BitcoinExchange::Date::operator<(
    const BitcoinExchange::Date &other) const {
  if (m_year < other.m_year) {
    return true;
  }

  if (m_year == other.m_year && m_month < other.m_month) {
    return true;
  }

  if (m_year == other.m_year && m_month == other.m_month &&
      m_day < other.m_day) {
    return true;
  }

  return false;
}

bool BitcoinExchange::Date::operator==(
    const BitcoinExchange::Date &other) const {
  return m_day == other.m_day && m_month == other.m_month &&
         m_year == other.m_year;
}

bool BitcoinExchange::Date::operator!=(
    const BitcoinExchange::Date &other) const {
  return !operator==(other);
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange::Date &date) {
  os << date.getYear() << '-' << std::setw(2) << std::setfill('0')
     << date.getMonth() << '-' << std::setw(2) << std::setfill('0')
     << date.getDay();
  return os;
}

std::pair<BitcoinExchange::Date, double>
BitcoinExchange::get_line_data(const std::string &line, char seperator) const {
  if (std::count(line.begin(), line.end(), seperator) != 1) {
    throw UnexpectedFormat();
  }

  return std::make_pair(
      Date(line.substr(0, line.find(seperator))),
      get_exchange_rate(line.substr(line.find(seperator) + 1)));
}

double BitcoinExchange::get_exchange_rate(const std::string &input) const {
  std::stringstream stream(input);
  double exchange_rate;

  if (!(stream >> exchange_rate)) {
    throw InvalidExchangeRate();
  }

  if (exchange_rate < 0) {
    throw InvalidExchangeRate();
  }

  if (exchange_rate >= std::numeric_limits<int>::max()) {
    throw NumberTooLarge();
  }

  return exchange_rate;
}

void BitcoinExchange::calculate(const std::string &path) const {
  std::ifstream file;

  file.open(path.c_str());

  if (!file.is_open()) {
    throw UnableToOpenFile();
  }

  bool header = true;
  std::string line;
  while (std::getline(file, line)) {
    try {
      if (header == true) {
        if (std::count(line.begin(), line.end(), '|') != 1) {
          throw UnexpectedFormat();
        }

        header = false;
        continue;
      }

      std::pair<Date, double> data = get_line_data(line, '|');
      if (!(data.second >= 0 && data.second <= 1000)) {
        throw NumberTooLarge();
      }

      std::map<Date, double>::const_iterator it =
          m_values.lower_bound(data.first);

      if (it->first != data.first && it != m_values.begin()) {
        --it;
      }

      double exchange_rate = it->second;
      double result = data.second * exchange_rate;

      std::cout << data.first << " => " << data.second << " = " << std::fixed
                << std::setprecision(2) << result << std::endl;

    } catch (const std::exception &error) {
      std::cout << error.what() << std::endl;
    }
  }
}

BitcoinExchange::BitcoinExchange() {
  std::ifstream file;

  file.open(DATABASE_PATH);

  if (file.bad()) {
    throw UnableToOpenFile();
  }

  bool header = true;
  std::string line;
  while (std::getline(file, line)) {
    if (header == true) {
      if (std::count(line.begin(), line.end(), ',') != 1) {
        throw UnexpectedFormat();
      }

      header = false;
      continue;
    }

    m_values.insert(get_line_data(line));
  }

  if (m_values.empty()) {
    throw EmptyDatabase();
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : m_values(other.m_values) {}

BitcoinExchange::~BitcoinExchange() {}
