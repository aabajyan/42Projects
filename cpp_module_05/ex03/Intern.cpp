/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:41:29 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/16 01:32:50 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &) { return *this; }

Form *Intern::makeForm(const std::string &name, const std::string &target) {
  static const char *names[INTERN_FORMS_COUNT] = {
      "shrubbery creation",
      "robotomy request",
      "presidential pardon",
  };
  static Forms forms = {
      &Intern::createShrubberyCreationForm,
      &Intern::createRobotomyRequestForm,
      &Intern::createPresidentialPardonForm,
  };

  for (int i = 0; i < INTERN_FORMS_COUNT; ++i)
    if (names[i] == name) {
      std::cout << "Intern creates form " << name << "\n";
      return (this->*forms[i])(target);
    }

  std::cout << "Intern was not able to find the form " << name << "\n";
  return NULL;
}

Form *Intern::createShrubberyCreationForm(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}

Form *Intern::createRobotomyRequestForm(const std::string &target) const {
  return new RobotomyRequestForm(target);
}

Form *Intern::createPresidentialPardonForm(const std::string &target) const {
  return new PresidentialPardonForm(target);
}
