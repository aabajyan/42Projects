/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 01:09:03 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/21 18:23:53 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <exception>

template <typename T> class Array {
public:
  Array() : m_ptr(NULL), m_size(0) {}
  Array(size_t size) : m_ptr(new T[size]), m_size(size) {}
  Array(const Array &other) : m_ptr(new T[other.m_size]), m_size(other.m_size) {
    for (size_t i = 0; i < m_size; ++i)
      m_ptr[i] = other.m_ptr[i];
  }
  ~Array() { delete[] m_ptr; }

  Array &operator=(const Array &other) {
    if (this != &other) {
      if (m_size != other.m_size) {
        delete[] m_ptr;
        m_ptr = new T[other.m_size];
        m_size = other.m_size;
      }
      for (size_t i = 0; i < m_size; ++i)
        m_ptr[i] = other.m_ptr[i];
    }
    return *this;
  }

  T &operator[](size_t index) {
    if (index < m_size)
      return m_ptr[index];
    throw OutOfRange();
  }

  const T &operator[](size_t index) const {
    if (index < m_size)
      return m_ptr[index];
    throw OutOfRange();
  }

  size_t size() const { return m_size; }

private:
  class OutOfRange : public std::exception {
  public:
    const char *what() const throw() { return "Out of range"; }
  };

  T *m_ptr;
  size_t m_size;
};

#endif // __ARRAY_H__
