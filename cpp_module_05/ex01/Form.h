/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:05:40 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 13:28:14 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;
class Form {
public:
  Form(const std::string &name, int sign_grade, int execute_grade);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  const std::string &getName() const;
  int getSignGrade() const;
  int getExecuteGrade() const;
  bool getSigned() const;

  void beSigned(const Bureaucrat &bureaucrat);

private:
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  const std::string m_name;
  const int m_sign_grade;
  const int m_execute_grade;
  bool m_signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // __FORM_H__
