/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:28:29 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/15 02:31:38 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type) : m_type(type) {}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const { return m_type; }

void AMateria::use(ICharacter &) {}
