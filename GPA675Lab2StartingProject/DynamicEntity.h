#pragma once
#ifndef DYNAMICENTITY_H
#define DYNAMICENTITY_H

#include "Entity.h" // Inclure la classe de base Entity


class DynamicEntity : public Entity {
public:
    DynamicEntity(Game& board); // Constructeur prenant une r�f�rence � un objet Game
    ~DynamicEntity(); // Destructeur par d�faut
 
};

#endif // DYNAMICENTITY_H