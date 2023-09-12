/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:10:17 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 18:18:42 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *RPN::NoValueException::what() const throw() {
  return "There's no value to pick.";
}

const char *RPN::UnexpectedTokenException::what() const throw() {
  return "Unexpected token.";
}

RPN::RPN() : m_input(""), m_stack(), m_cursor(0) {}

RPN::RPN(const std::string &input) : m_input(input), m_stack(), m_cursor(0) {}

int RPN::pop() {
  if (m_stack.size() == 0) {
    throw NoValueException();
  }

  int value = m_stack.top();
  m_stack.pop();

  return value;
}

RPN::RPN(const RPN &other)
    : m_input(other.m_input), m_stack(other.m_stack), m_cursor(other.m_cursor) {
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    m_input = other.m_input;
    m_stack = other.m_stack;
    m_cursor = other.m_cursor;
  }
  return *this;
}

bool RPN::isoperator(char chr) {
  return chr == '+' || chr == '-' || chr == '*' || chr == '/';
}

int RPN::calculate() {
  while (m_cursor <= m_input.size()) {
    char chr = m_input[m_cursor];

    if (chr == '\0') {
      break;
    }

    if (std::isspace(chr)) {
      m_cursor++;
      continue;
    }

    if (std::isdigit(chr)) {
      m_stack.push(chr - '0');
      m_cursor++;
      continue;
    }

    if (isoperator(chr)) {
      int rhs = pop();
      int lhs = pop();

      switch (chr) {
      case '+':
        m_stack.push(lhs + rhs);
        break;
      case '-':
        m_stack.push(lhs - rhs);
        break;
      case '*':
        m_stack.push(lhs * rhs);
        break;
      case '/':
        m_stack.push(lhs / rhs);
        break;
      }

      m_cursor++;
      continue;
    }

    throw UnexpectedTokenException();
  }

  if (m_stack.size() == 0) {
    return 0;
  }

  return m_stack.top();
}
