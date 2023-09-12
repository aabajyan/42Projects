/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:20:53 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 17:28:37 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::s_bits = 8;

Fixed::Fixed(): m_value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): m_value(value << s_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value): m_value(roundf(value * (1 << s_bits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): m_value(other.m_value) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    m_value = other.m_value;
  return *this;
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
