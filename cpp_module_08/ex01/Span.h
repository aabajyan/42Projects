/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:31:00 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:57:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
#define __SPAN_H__
#include <cstddef>
#include <exception>
#include <vector>
#include <algorithm>

class Span {
public:
  Span();
  Span(size_t size);
  Span(const Span &other);
  ~Span();

  Span &operator=(const Span &other);

  void addNumber(int n);

  template<class Iterator>
  void addNumber(Iterator begin, Iterator end);

  size_t shortestSpan() const;
  size_t longestSpan() const;

  size_t size() const;

private:
  class SpanIsFull : public std::exception {
  public:
    const char *what() const throw();
  };

  class IteratorTooLarge : public std::exception {
    const char *what() const throw();
  };

  class SizeTooSmall : public std::exception {
  public:
    const char *what() const throw();
  };

  std::vector<int> m_values;
  size_t m_size;
};

template<class Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
  if (m_values.size() + std::distance(begin, end) > m_size)
    throw IteratorTooLarge();
  m_values.insert(m_values.end(), begin, end);
  std::sort(m_values.begin(), m_values.end());
}

#endif // __SPAN_H__
