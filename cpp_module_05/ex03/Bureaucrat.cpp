/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:09:56 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 17:27:51 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : m_name(name), m_grade(grade) {
  if (m_grade < BUREAUCRAT_MIN_GRADE)
    throw GradeTooHighException();
  if (m_grade > BUREAUCRAT_MAX_GRADE)
   throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : m_name(other.m_name), m_grade(other.m_grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other)
    m_grade = other.m_grade;
  return *this;
}

void Bureaucrat::increment(int quantity) {
  const int result = m_grade + quantity;
  if (result > BUREAUCRAT_MAX_GRADE)
   throw GradeTooLowException();
  m_grade = result;
}

void Bureaucrat::decrement(int quantity) {
  const int result = m_grade - quantity;
  if (result < BUREAUCRAT_MIN_GRADE)
    throw GradeTooHighException();
  m_grade = result;
}

const std::string &Bureaucrat::getName() const { return m_name; }

int Bureaucrat::getGrade() const { return m_grade; }

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << m_name << " signed " << form.getName() << "\n";
  } catch (const std::exception &e) {
    std::cout << m_name << " couldn't sign, because " << e.what() << " \n";
  }
}

void Bureaucrat::executeForm(Form const &form) {
  try {
    form.execute(*this);
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }
}

Bureaucrat::Bureaucrat() : m_name(""), m_grade(0) {}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &x) {
  os << x.getName() << ", bureaucrat grade " << x.getGrade();
  return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Exception: grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Exception: grade too low";
}
