/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:40:10 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 20:13:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__
#include <string>

#define INTERN_FORMS_COUNT 3

class Form;
class Intern {
public:
  Intern();
  Intern(const Intern &other);
  ~Intern();

  Intern &operator=(const Intern &other);

  Form *makeForm(const std::string &name, const std::string &target);

private:
  Form *createShrubberyCreationForm(const std::string &target) const;
  Form *createRobotomyRequestForm(const std::string &target) const;
  Form *createPresidentialPardonForm(const std::string &target) const;

  typedef Form *(Intern::*Forms[INTERN_FORMS_COUNT])(const std::string &) const;
};

#endif // __INTERN_H__
