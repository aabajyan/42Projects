/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:25:18 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/15 23:52:03 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_H__
#define __PRESIDENTIAL_PARDON_FORM_H__
#include "Form.h"
#include <string>

#define RESIDENTIAL_PARDON_FORM_NAME "Presidential Pardon"
#define RESIDENTIAL_PARDON_FORM_SIGN 25
#define RESIDENTIAL_PARDON_FORM_EXECUTE 5

class PresidentialPardonForm : public Form {
public:
  using Form::operator=;

  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();

  void doExecute() const;

private:
  PresidentialPardonForm();
};

#endif // __PRESIDENTIAL_PARDON_FORM_H__
