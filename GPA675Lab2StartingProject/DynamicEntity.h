#pragma once
#ifndef DYNAMICENTITY_H
#define DYNAMICENTITY_H

#include "Entity.h" // Inclure la classe de base Entity


class DynamicEntity : public Entity {
public:
    DynamicEntity(Game& board); // Constructeur prenant une référence à un objet Game
    ~DynamicEntity(); // Destructeur par défaut
 
};

#endif // DYNAMICENTITY_H