/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:07:49 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 20:13:13 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"
#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {

  try {
    Bureaucrat james("James", 2);
    std::cout << james << "\n";

    james.increment();
    std::cout << james << "\n";

    james.increment(2);
    std::cout << james << "\n";

    james.decrement(4);
    std::cout << james << "\n";

    james.increment(1000);

  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    Bureaucrat bob("Bob", 2);
    bob.decrement(100);

  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    Bureaucrat x("Test", -1);
    std::cout << "You shouldn't see this\n";
  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    Bureaucrat x("Test", 1000);
    std::cout << "You shouldn't see this\n";
  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    PresidentialPardonForm form("pardon");
    Bureaucrat x("Test", 5);

    form.beSigned(x);
    form.execute(x);

  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    RobotomyRequestForm form("robot");
    Bureaucrat x("Test", 5);

    form.beSigned(x);
    form.execute(x);

  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    ShrubberyCreationForm form("creation");
    Bureaucrat x("Test", 5);

    form.beSigned(x);
    form.execute(x);

  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  Intern someRandomIntern;
  Form *test1 = someRandomIntern.makeForm("robotomy request", "Bender");
  if (test1 != NULL)
    delete test1;

  Form *test2 = someRandomIntern.makeForm("presidential pardon", "Bender");
  if (test2 != NULL)
    delete test2;

  Form *test3 = someRandomIntern.makeForm("nothing lol", "Bender");
  if (test3 != NULL)
    delete test3;

  return 0;
}
