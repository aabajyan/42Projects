/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:08:13 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 20:12:49 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_H__
#define __SHRUBBERY_CREATION_FORM_H__
#include "Form.h"
#include <string>

#define SHRUBBERY_CREATION_FORM_NAME "Shrubbery creation"
#define SHRUBBERY_CREATION_FORM_SIGN 145
#define SHRUBBERY_CREATION_FORM_EXECUTE 137

class ShrubberyCreationForm : public Form {
public:
  using Form::operator=;

  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  void doExecute() const;

private:
  ShrubberyCreationForm();
};

#endif // __SHRUBBERY_CREATION_FORM_H__
