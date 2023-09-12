/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:28:36 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 18:00:50 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_H__
#define __RPN_H__
#include <exception>
#include <stack>
#include <string>

class RPN {
public:
  class NoValueException : public std::exception {
  public:
    const char *what() const throw();
  };

  class UnexpectedTokenException : public std::exception {
  public:
    const char *what() const throw();
  };

public:
  RPN();
  RPN(const std::string &input);
  RPN(const RPN &other);
  virtual ~RPN();

  RPN &operator=(const RPN &other);

  int calculate();

private:
  bool isoperator(char chr);
  int pop();

private:
  std::string m_input;
  std::stack<int> m_stack;
  size_t m_cursor;
};

#endif // __RPN_H__
