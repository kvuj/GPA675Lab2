#pragma once
#ifndef PRESSED_KEY_H
#define PRESSED_KEY_H


#include <vector>
#include <Qt>


// 
// Alias PressedKeys
// Type alias pour une collection de touches clavier appuyées.
// 
// Cette définition utilise un std::vector pour stocker une séquence de touches clavier identifiées
// par leurs codes Qt::Key. Elle sert à représenter l'ensemble des touches actuellement pressées
// par l'utilisateur, facilitant ainsi la gestion des entrées dans le contexte du jeu.
// 
// L'utilisation d'un vector offre la flexibilité nécessaire pour ajouter ou retirer des touches
// dynamiquement, en fonction des actions de l'utilisateur, tout en permettant un accès itératif
// efficace aux éléments pour le traitement des entrées.
using PressedKeys = std::vector<Qt::Key>;



#endif //PRESSED_KEY_H