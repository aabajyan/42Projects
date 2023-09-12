/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:14:52 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 17:54:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : Form(ROBOTOMY_REQUEST_FORM_NAME, "None", ROBOTOMY_REQUEST_FORM_SIGN,
           ROBOTOMY_REQUEST_FORM_EXECUTE) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form(ROBOTOMY_REQUEST_FORM_NAME, target, ROBOTOMY_REQUEST_FORM_SIGN,
           ROBOTOMY_REQUEST_FORM_EXECUTE) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(other) {}

void RobotomyRequestForm::doExecute() const {
  std::srand(std::time(NULL));
  std::cout << "* SOME DRILLING NOISES *\n";
  if (std::rand() % 2 == 0) {
    std::cout << getTarget() << " has been robotomized succesfully\n";
    return;
  }
  std::cout << "Failed to robotomized " << getTarget() << "\n";
}
