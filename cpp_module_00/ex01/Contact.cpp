/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:50:34 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 16:26:42 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(void)
    : m_first_name(""), m_last_name(""), m_nickname(""), m_phone(""),
      m_secret("") {}

Contact::~Contact(void) {}

void Contact::set_first_name(const std::string &first_name) {
  m_first_name = first_name;
}

void Contact::set_last_name(const std::string &last_name) {
  m_last_name = last_name;
}

void Contact::set_nickname(const std::string &nickname) {
  m_nickname = nickname;
}

void Contact::set_phone(const std::string &phone) { m_phone = phone; }

void Contact::set_secret(const std::string &secret) { m_secret = secret; }

const std::string &Contact::get_first_name(void) const { return m_first_name; }

const std::string &Contact::get_last_name(void) const { return m_last_name; }

const std::string &Contact::get_nickname(void) const { return m_nickname; }

const std::string &Contact::get_phone(void) const { return m_phone; }

const std::string &Contact::get_secret(void) const { return m_secret; }
