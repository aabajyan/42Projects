/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:31:40 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/23 20:08:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

Span::Span() : m_size(0) {}

Span::Span(size_t size) : m_size(size) { m_values.reserve(m_size); }

Span::~Span() {}

Span::Span(const Span &other)
    : m_values(other.m_values), m_size(other.m_size) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    m_values = other.m_values;
    m_size = other.m_size;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (m_values.size() >= m_size)
    throw SpanIsFull();
  m_values.push_back(n);
  std::sort(m_values.begin(), m_values.end());
}

size_t Span::shortestSpan() const {
  if (m_values.size() < 2 || m_values.size() < 2)
    throw SizeTooSmall();
  int min = *(m_values.begin() + 1) - *m_values.begin();
  for (std::vector<int>::const_iterator it = m_values.begin();
       it != m_values.end() - 1; ++it)
    if (*(it + 1) - *it < min)
      min = *(it + 1) - *it;
  return min;
}

size_t Span::longestSpan() const {
  if (m_size < 2 || m_values.size() < 2)
    throw SizeTooSmall();
  return m_values.back() - m_values.front();
}

size_t Span::size() const { return m_size; }

const char *Span::SizeTooSmall::what() const throw() {
  return "Span size is too small";
}

const char *Span::IteratorTooLarge::what() const throw() {
  return "Iterator is too large";
}

const char *Span::SpanIsFull::what() const throw() { return "Span is full"; }
