/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:25:23 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 20:13:16 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm()
    : Form(RESIDENTIAL_PARDON_FORM_NAME, "None", RESIDENTIAL_PARDON_FORM_SIGN,
           RESIDENTIAL_PARDON_FORM_EXECUTE) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form(RESIDENTIAL_PARDON_FORM_NAME, target, RESIDENTIAL_PARDON_FORM_SIGN,
           RESIDENTIAL_PARDON_FORM_EXECUTE) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : Form(other) {}

void PresidentialPardonForm::doExecute() const {
  std::cout << getName() << " has been pardoned by Zafod Beeblebrox\n";
}
