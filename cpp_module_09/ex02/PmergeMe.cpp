/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:20:15 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 19:05:24 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>

const char *PmergeMe::NotSortedException::what() const throw() {
  return "Error: Data is not sorted.";
}

const char *PmergeMe::DuplicateValues::what() const throw() {
  return "Error: Duplicate values.";
}

const char *PmergeMe::InvalidArgument::what() const throw() {
  return "Error: Invalid argument.";
}

void PmergeMe::insertion_sort_vector(std::vector<int> &values) {
  for (size_t i = 1; i < values.size(); ++i) {
    int current = values[i];
    int j = i - 1;

    while (j > -1 && current < values[j]) {
      values[j + 1] = values[j];
      j--;
    }

    values[j + 1] = current;
  }
}

void PmergeMe::insertion_sort_list(std::list<int> &values) {
  std::list<int>::iterator first = values.begin();
  std::list<int>::iterator last = values.end();

  for (std::list<int>::iterator i = first; i != last; i++) {
    for (std::list<int>::iterator j = i; j != first; j--) {
      std::list<int>::iterator previous = j;
      --previous;
      if (*j < *previous) {
        std::swap(*j, *previous);
        continue;
      }

      break;
    }
  }
}

void PmergeMe::merge_vector(std::vector<int> &values, size_t start, size_t mid,
                            size_t end) {
  std::vector<int> temp(end - start + 1);
  size_t index1 = start;
  size_t index2 = mid + 1;

  for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
    if (index1 > mid) {
      *it = values[index2++];
    } else if (index2 > end) {
      *it = values[index1++];
    } else {
      if (values[index1] < values[index2]) {
        *it = values[index1++];
      } else {
        *it = values[index2++];
      }
    }
  }

  size_t s = start;
  for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
    values[s++] = *it;
  }
}

void PmergeMe::merge_list(std::list<int> &left, std::list<int> &right,
                          std::list<int> &result) {
  std::list<int>::iterator left_it = left.begin();
  std::list<int>::iterator right_it = right.begin();

  while (left_it != left.end() && right_it != right.end()) {
    if (*left_it < *right_it) {
      result.push_back(*left_it);
      ++left_it;
    } else {
      result.push_back(*right_it);
      ++right_it;
    }
  }

  while (left_it != left.end()) {
    result.push_back(*left_it);
    ++left_it;
  }

  while (right_it != right.end()) {
    result.push_back(*right_it);
    ++right_it;
  }
}

void PmergeMe::merge_sort_vector(std::vector<int> &list, size_t start,
                                 size_t end) {

  if (end - start <= PMERGEME_THRESHOLD) {
    insertion_sort_vector(list);
    return;
  }

  if (start < end) {
    size_t mid = (start + end) / 2;
    merge_sort_vector(list, start, mid);
    merge_sort_vector(list, mid + 1, end);
    merge_vector(list, start, mid, end);
  }
}

void PmergeMe::merge_sort_list(std::list<int> &list) {
  size_t size = list.size();

  if (size <= 1) {
    return;
  }

  if (size <= PMERGEME_THRESHOLD) {
    insertion_sort_list(list);
    return;
  }

  int middle = size / 2;
  std::list<int> left, right, result;
  std::list<int>::iterator it = list.begin();

  for (int i = 0; i < middle; ++i) {
    left.push_back(*it);
    ++it;
  }

  while (it != list.end()) {
    right.push_back(*it);
    ++it;
  }

  merge_sort_list(left);
  merge_sort_list(right);
  merge_list(left, right, result);

  list = result;
}

PmergeMe::PmergeMe(int count, char **values) : m_list(), m_vector() {
  fill_values(count, values);
}

void PmergeMe::fill_values(int count, char **values) {
  m_vector.reserve(count);

  for (int i = 0; i < count; ++i) {
    int value = std::atoi(values[i]);
    if (value <= 0) {
      throw InvalidArgument();
    }

    m_vector.push_back(value);
    m_list.push_back(value);
  }

  for (size_t i = 0; i < m_vector.size(); ++i) {
    for (size_t j = 0; j < m_vector.size(); ++j) {
      if (i != j && m_vector[i] == m_vector[j]) {
        throw DuplicateValues();
      }
    }
  }
}

void PmergeMe::sort_vector() {
  clock_t begin = std::clock();
  merge_sort_vector(m_vector, 0, m_vector.size());
  m_vector_time = std::clock() - begin;
}

void PmergeMe::sort_list() {
  clock_t begin = std::clock();
  merge_sort_list(m_list);
  m_list_time = std::clock() - begin;
}

void PmergeMe::print_data(bool sorted) const {
  std::cout << (sorted ? "After: " : "Before:");
  for (std::vector<int>::const_iterator it = m_vector.begin();
       it != m_vector.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

void PmergeMe::print_time(bool vector) const {
  std::string name = ((vector) ? "vector" : "list");
  double time = static_cast<double>(((vector) ? m_vector_time : m_list_time)) /
                static_cast<double>(CLOCKS_PER_SEC);

  std::cout << "Time to process a range of " << m_vector.size()
            << " elements with std::" << name << " : " << std::fixed
            << std::setprecision(5) << time << " us" << std::endl;
}

void PmergeMe::sort_and_print() {
  print_data(false);

  sort_vector();
  sort_list();

  ensure_numbers_are_sorted();

  print_data(true);

  print_time(true);
  print_time(false);
}

void PmergeMe::ensure_numbers_are_sorted() const {
  for (std::vector<int>::const_iterator it = m_vector.begin();
       it != m_vector.end(); ++it) {
    std::vector<int>::const_iterator next = it + 1;
    if (next != m_vector.end() && *it > *next) {
      throw NotSortedException();
    }
  }

  for (std::list<int>::const_iterator it = m_list.begin(); it != m_list.end();
       ++it) {
    std::list<int>::const_iterator next = it;
    ++next;
    if (next != m_list.end() && *it > *next) {
      throw NotSortedException();
    }
  }
}

PmergeMe::PmergeMe() : m_list(), m_vector() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : m_list(other.m_list), m_vector(other.m_vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    m_list = other.m_list;
    m_vector = other.m_vector;
  }
  return *this;
}
