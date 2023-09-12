/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:53:35 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 18:43:44 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__
#include <exception>
#include <iomanip>
#include <map>
#include <string>

#ifndef DATABASE_PATH
#define DATABASE_PATH "./database.csv"
#endif

class BitcoinExchange {
public:
  class Date {
  public:
    class InvalidDate : public std::exception {
    public:
      const char *what() const throw();
    };

  public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(const std::string &string);
    Date(const Date &other);
    virtual ~Date();

    Date &operator=(const Date &other);

    void setYear(unsigned int value);
    void setMonth(unsigned int value);
    void setDay(unsigned int value);

    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;

    bool operator<(const Date &other) const;
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;

  private:
    unsigned int m_year;
    unsigned int m_month;
    unsigned int m_day;
  };

public:
  class EmptyDatabase : public std::exception {
  public:
    const char *what() const throw();
  };

  class UnableToOpenFile : public std::exception {
  public:
    const char *what() const throw();
  };

  class UnexpectedFormat : public std::exception {
  public:
    const char *what() const throw();
  };

  class InvalidExchangeRate : public std::exception {
  public:
    const char *what() const throw();
  };

  class NumberTooLarge : public std::exception {
  public:
    const char *what() const throw();
  };

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  ~BitcoinExchange();

  BitcoinExchange &operator=(const BitcoinExchange &other);

  void calculate(const std::string &path) const;

private:
  double get_exchange_rate(const std::string &input) const;
  std::pair<Date, double> get_line_data(const std::string &line,
                                        char seperator = ',') const;

private:
  std::map<Date, double> m_values;
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange::Date &date);

#endif // __BITCOIN_EXCHANGE_HPP__
