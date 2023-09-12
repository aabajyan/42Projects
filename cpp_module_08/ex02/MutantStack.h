/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:25:25 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/22 21:47:50 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_H__
#define __MUTANT_STACK_H__
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack() : std::stack<T, Container>() {}
  MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

  MutantStack &operator=(const MutantStack &other) {
    if (this != &other)
      this->c = other.c;
    return *this;
  }

  typedef typename std::stack<T, Container>::container_type::iterator iterator;
  typedef typename std::stack<T, Container>::container_type::reverse_iterator
      reverse_iterator;
  typedef typename std::stack<T, Container>::container_type::const_iterator
      const_iterator;
  typedef
      typename std::stack<T, Container>::container_type::const_reverse_iterator
          const_reverse_iterator;

  iterator begin() { return std::stack<T, Container>::c.begin(); }

  iterator end() { return std::stack<T, Container>::c.end(); }

  reverse_iterator rbegin() { return std::stack<T, Container>::c.rbegin(); }

  reverse_iterator rend() { return std::stack<T, Container>::c.rend(); }

  const_iterator begin() const { return std::stack<T, Container>::c.begin(); }

  const_iterator end() const { return std::stack<T, Container>::c.end(); }

  const_reverse_iterator rbegin() const {
    return std::stack<T, Container>::c.begin();
  }

  const_reverse_iterator rend() const {
    return std::stack<T, Container>::c.end();
  }
};

#endif // __MUTANT_STACK_H__
