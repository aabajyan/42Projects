/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:29:47 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 19:23:04 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>

int main() {

  // TEST 1
  {
    std::cout << "=== IMateriaSource ===\n\n";
    IMateriaSource *src = new MateriaSource;
    src->learnMateria(new Ice);
    src->learnMateria(new Cure);

    ICharacter *me = new Character("me");

    std::cout << "\n\n=== CreateMaterial ===\n\n";

    AMateria *tmp = NULL;
    AMateria *first = NULL;
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    first = tmp;
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(NULL);
    delete tmp;

    std::cout << "\n\n=== Charecter Use ===\n\n";

    ICharacter *bob = new Character("bob");
    me->use(-1, *bob);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);

    std::cout << "\n\n=== Unequip ===\n\n";

    me->unequip(0);
    me->use(0, *bob);
    me->use(3, *bob);
    me->unequip(-1);
    me->equip(first);
    delete bob;
    delete me;
    delete src;
  }

  // TEST 2
  {

    std::cout << "\n\n=== IMateriaSource ===\n\n";

    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character *me = new Character("me");
    AMateria *tmp;

    std::cout << "\n\n=== Create Material & Equip ===\n\n";

    tmp = src->createMateria("ice");
    me->equip(tmp);
 
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->equip(NULL);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));

    me->unequip(-1);
    me->unequip(5);
    me->unequip(1);
    me->unequip(0);

    Character *A = new Character(*me);
    Character *B = new Character();

    *B = *A;

    delete tmp;
    delete B;
    delete A;
    delete bob;
    delete me;
    delete src;
  }

  return 0;
}
