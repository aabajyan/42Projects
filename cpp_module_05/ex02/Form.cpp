/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:05:59 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 17:30:35 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"
#include "Bureaucrat.h"

Form::Form(const Form &other)
    : m_name(other.m_name), m_target(other.m_target),
      m_sign_grade(other.m_sign_grade), m_execute_grade(other.m_execute_grade),
      m_signed(other.m_signed) {}

Form &Form::operator=(const Form &other) {
  if (this != &other)
    m_signed = other.m_signed;
  return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return m_name; }

const std::string &Form::getTarget() const { return m_target; }

int Form::getSignGrade() const { return m_sign_grade; }

int Form::getExecuteGrade() const { return m_execute_grade; }

bool Form::getSigned() const { return m_signed; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= m_sign_grade) {
    m_signed = true;
    std::cout << m_name << " has signed " << bureaucrat.getName() << "\n";
    return;
  }
  throw GradeTooLowException();
}

void Form::execute(const Bureaucrat &executor) const {
  if (m_signed == false)
    throw Form::NotSigned();
  if (executor.getGrade() > m_execute_grade)
    throw Form::GradeTooLowException();
  doExecute();
  std::cout << executor.getName() << " has executed " << m_name << "\n";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  std::cout << "=============\nForm\nname: " << form.getName()
            << "\nexecution grade: " << form.getExecuteGrade()
            << "\nsign grade: " << form.getSignGrade()
            << "\nsigned: " << (form.getSigned() ? "true" : "false")
            << "\n=============";
  return os;
}

Form::Form(const std::string &name, const std::string &target, int sign_grade,
           int execute_grade)
    : m_name(name), m_target(target), m_sign_grade(sign_grade),
      m_execute_grade(execute_grade), m_signed(false) {
  if (m_sign_grade > BUREAUCRAT_MAX_GRADE ||
      m_execute_grade > BUREAUCRAT_MAX_GRADE)
   throw GradeTooLowException();
  if (m_sign_grade < BUREAUCRAT_MIN_GRADE ||
      m_execute_grade < BUREAUCRAT_MIN_GRADE)
    throw GradeTooHighException();
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Exception: grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Exception: grade too low";
}

const char *Form::NotSigned::what() const throw() {
  return "Exception: not signed";
}
