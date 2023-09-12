/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:20:53 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 17:28:49 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::s_bits = 8;

Fixed::Fixed(): m_value(0) {}

Fixed::Fixed(const int value): m_value(value << s_bits) {}

Fixed::Fixed(const float value): m_value(roundf(value * (1 << s_bits))) {}

Fixed::Fixed(const Fixed &other): m_value(other.m_value) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other)
    m_value = other.m_value;
  return *this;
}

bool Fixed::operator>(const Fixed &other) const {
  return m_value > other.m_value;
}

bool Fixed::operator<(const Fixed &other) const {
  return m_value < other.m_value;
}

bool Fixed::operator>=(const Fixed &other) const {
  return m_value >= other.m_value;
}

bool Fixed::operator<=(const Fixed &other) const {
  return m_value <= other.m_value;
}

bool Fixed::operator==(const Fixed &other) const {
  return m_value == other.m_value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return m_value != other.m_value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  result.setRawBits(m_value + other.m_value);
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  result.setRawBits(m_value - other.m_value);
  return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(toFloat() / other.toFloat());
}

Fixed Fixed::operator++() {
  ++m_value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}

Fixed Fixed::operator--() {
  --m_value;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
  out << value.toFloat();
  return out;
}

int Fixed::getRawBits(void) const { return m_value; }

void Fixed::setRawBits(const int raw) { m_value = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(m_value) / static_cast<float>(1 << s_bits);
}

int Fixed::toInt(void) const { return m_value >> s_bits; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a > b ? b : a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a > b ? b : a; }

const Fixed &min(const Fixed &a, const Fixed &b) { return Fixed::min(a, b); }

Fixed &min(Fixed &a, Fixed &b) { return Fixed::min(a, b); }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a > b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

const Fixed &max(const Fixed &a, const Fixed &b) { return Fixed::max(a, b); }

Fixed &max(Fixed &a, Fixed &b) { return Fixed::max(a, b); }
