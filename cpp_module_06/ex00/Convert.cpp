/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:54:21 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:21:01 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.h"
#include <cmath>
#include <cstdlib>
#include <iomanip>

Convert::Convert(const std::string &value) : m_value(value) {}

Convert::Convert(const Convert &other) : m_value(other.m_value) {}

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &other) {
  if (this != &other)
    m_value = other.m_value;
  return *this;
}

const std::string &Convert::get_value() const { return m_value; }

void Convert::set_value(const std::string &value) { m_value = value; }

char Convert::to_char() const {

  char *end = NULL;
  int value = std::strtol(m_value.c_str(), &end, 10);

  if (!end || end == m_value.c_str()) {
    if (m_value.length() == 1 && std::isprint(m_value[0]))
      return static_cast<int>(m_value[0]);
    throw ImplossibleException();
  }

  if (value <= 0 || value > 255 || !std::isprint(value))
    throw NonDisplayableException();

  return value;
}

int Convert::to_int() const {

  char *end = NULL;
  int value = std::strtol(m_value.c_str(), &end, 10);

  if (!end || end == m_value.c_str()) {
    if (m_value.length() == 1 && std::isprint(m_value[0]))
      return static_cast<int>(m_value[0]);
    throw ImplossibleException();
  }

  return value;
}

float Convert::to_float() const {
  char *end = NULL;
  float value = std::strtof(m_value.c_str(), &end);

  if (!end || end == m_value.c_str()) {
    if (m_value.length() == 1 && std::isprint(m_value[0]))
      return static_cast<float>(m_value[0]);
    throw ImplossibleException();
  }

  return value;
}

double Convert::to_double() const {
  char *end = NULL;
  double value = std::strtod(m_value.c_str(), &end);

  if (!end || end == m_value.c_str()) {
    if (m_value.length() == 1 && std::isprint(m_value[0]))
      return static_cast<double>(m_value[0]);
    throw ImplossibleException();
  }

  return value;
}

Convert::Convert() : m_value("") {}

const char *Convert::ImplossibleException::what() const throw() {
  return "impossible";
}

const char *Convert::NonDisplayableException::what() const throw() {
  return "Non displayable";
}

std::ostream &operator<<(std::ostream &os, const Convert &convert) {

  os << std::fixed;
  os << "char: ";
  try {
    char chr = convert.to_char();
    os << "'" << chr << "'";
  } catch (const std::exception &ex) {
    os << ex.what();
  }

  os << "\n"
        "int: ";
  try {
    os << convert.to_int();
  } catch (const std::exception &ex) {
    os << ex.what();
  }

  os << "\n"
        "float: ";
  try {
    os << convert.to_float() << "f";
  } catch (const std::exception &ex) {
    os << ex.what();
  }

  os << "\n"
        "double: ";
  try {
    os << convert.to_double();
  } catch (const std::exception &ex) {
    os << ex.what();
  }

  return os;
}
