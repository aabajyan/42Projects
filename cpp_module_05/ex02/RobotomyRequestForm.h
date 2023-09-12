/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:14:43 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 20:12:43 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_H__
#define __ROBOTOMY_REQUEST_FORM_H__
#include "Form.h"
#include <string>

#define ROBOTOMY_REQUEST_FORM_NAME "Robotomy request"
#define ROBOTOMY_REQUEST_FORM_SIGN 72
#define ROBOTOMY_REQUEST_FORM_EXECUTE 45

class RobotomyRequestForm : public Form {
public:
  using Form::operator=;

  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();

  void doExecute() const;

private:
  RobotomyRequestForm();
};

#endif // __ROBOTOMY_REQUEST_FORM_H__
