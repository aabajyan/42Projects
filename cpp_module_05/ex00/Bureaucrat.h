/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:08:37 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 13:23:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__
#include <exception>
#include <iostream>
#include <string>

#define BUREAUCRAT_MAX_GRADE 150
#define BUREAUCRAT_MIN_GRADE 1

class Bureaucrat {
public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &other);

  void increment(int quantity = 1);
  void decrement(int quantity = 1);

  const std::string &getName() const;
  int getGrade() const;

private:
  Bureaucrat();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  const std::string m_name;
  int m_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &x);

#endif // __BUREAUCRAT_H__
