#pragma once
#ifndef TESTS_H
#define TESTS_H

#include <cassert>
#include <functional>
#include <vector>

#include "Body.h"

// On ajoute un pointeur de la fonction au vecteur vec. Cela permet de
// tout exécuter de façon propre.
//
// On utilise une struct avec un constructeur qui se fait appeler par
// défaut à sa construction. Lors de celle-ci, on met le pointeur dans
// le vecteur.
//
// Pour ajouter un test, simplement faire une déclaration de fonction
// avec ce macro dans le fichier Tests.cpp
#define ADD_TEST(name) \
        void name(); \
        struct name##_adder { \
            name##_adder() { \
                Tests::vec.push_back(&name); \
            } \
        } name##_instance; \
        void name()

class Tests {
public:
	Tests();
	void runTests();
	static std::vector<void(*)()> vec;
};


#endif //TESTS_H
