/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:36:15 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:39:29 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"
#include <iostream>
#include <list>

int main() {

  std::cout << "\n\n=== MutantStack<int> ===\n\n";

  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    std::cout << "\nMutantStack<int>::iterator\n\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "\nMutantStack<int>::reverse_iterator\n\n";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite) {
      std::cout << *rit << std::endl;
      ++rit;
    }

    std::cout << "\nMutantStack<int>::const_iterator\n\n";
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    ++it;
    --it;
    while (cit != cite) {
      std::cout << *cit << std::endl;
      ++cit;
    }

    std::cout << "\nMutantStack<int>::const_reverse_iterator\n\n";
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    ++rit;
    --rit;
    while (crit != crite) {
      std::cout << *crit << std::endl;
      ++crit;
    }


  }

  std::cout << "\n\n=== std::list<int> ===\n\n";

  {
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);

    std::cout << "\nstd::list<int>::iterator\n\n";
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "\nstd::list<int>::reverse_iterator\n\n";
    std::list<int>::reverse_iterator rit = mlist.rbegin();
    std::list<int>::reverse_iterator rite = mlist.rend();
    ++rit;
    --rit;
    while (rit != rite) {
      std::cout << *rit << std::endl;
      ++rit;
    }

    std::cout << "\nstd::list<int>::const_iterator\n\n";
    std::list<int>::const_iterator cit = mlist.begin();
    std::list<int>::const_iterator cite = mlist.end();
    ++it;
    --it;
    while (cit != cite) {
      std::cout << *cit << std::endl;
      ++cit;
    }

    std::cout << "\nstd::list<int>::const_reverse_iterator\n\n";
    std::list<int>::const_reverse_iterator crit = mlist.rbegin();
    std::list<int>::const_reverse_iterator crite = mlist.rend();
    ++rit;
    --rit;
    while (crit != crite) {
      std::cout << *crit << std::endl;
      ++crit;
    }


    std::cout << "\n\n";
  }

  return 0;
}
