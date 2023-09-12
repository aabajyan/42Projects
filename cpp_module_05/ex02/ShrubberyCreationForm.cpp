/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:58:03 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/19 19:31:38 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(SHRUBBERY_CREATION_FORM_NAME, "None", SHRUBBERY_CREATION_FORM_SIGN,
           SHRUBBERY_CREATION_FORM_EXECUTE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form(SHRUBBERY_CREATION_FORM_NAME, target, SHRUBBERY_CREATION_FORM_SIGN,
           SHRUBBERY_CREATION_FORM_EXECUTE) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(other) {}

void ShrubberyCreationForm::doExecute() const {
  std::ofstream out((getTarget() + "_shrubbery").c_str(),
                    std::ofstream::in | std::ofstream::trunc);

  out << "               ,@@@@@@@,\n"
         "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
         "    ,&%&&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
         "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
         "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
         "   %&&%/ %&%&&&@@\\ V /@@' `88\\8 `/88'\n"
         "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
         "       |o|        | |         | |\n"
         "       |.|        | |         | |\n"
         "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
}
