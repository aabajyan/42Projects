/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:19:59 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 19:04:44 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_H__
#define __PMERGEME_H__
#include <ctime>
#include <exception>
#include <list>
#include <vector>

#define PMERGEME_THRESHOLD 16

class PmergeMe {
public:
  class NotSortedException : public std::exception {
  public:
    const char *what() const throw();
  };

  class DuplicateValues : public std::exception {
  public:
    const char *what() const throw();
  };

  class InvalidArgument : public std::exception {
  public:
    const char *what() const throw();
  };

public:
  PmergeMe();
  PmergeMe(int count, char **values);
  PmergeMe(const PmergeMe &other);
  virtual ~PmergeMe();

  PmergeMe &operator=(const PmergeMe &other);

public:
  void fill_values(int count, char **values);
  void sort_and_print();

private:
  void insertion_sort_vector(std::vector<int> &values);

  void insertion_sort_list(std::list<int> &values);

  void merge_vector(std::vector<int> &values, size_t start, size_t mid,
                    size_t end);

  void merge_list(std::list<int> &left, std::list<int> &right,
                  std::list<int> &result);

  void merge_sort_vector(std::vector<int> &list, size_t start, size_t end);

  void merge_sort_list(std::list<int> &list);

  void sort_vector();

  void sort_list();

  void print_data(bool sorted) const;

  void print_time(bool vector) const;

  void ensure_numbers_are_sorted() const;

private:
  std::list<int> m_list;
  std::vector<int> m_vector;

  clock_t m_list_time;
  clock_t m_vector_time;
};

#endif // __PMERGEME_H__
