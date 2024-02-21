#pragma once
#ifndef PELLET_H
#define PELLET_H
#include "StaticEntity.h"
#include "Snake.h"

//Les pastilles sont des entités statiques.Elles sont des items qui peuvent être consommés par les entités dynamiques.Elles présentent ces caractéristiques :
//elles sont de la taille d’une seule cellule
//il peut y avoLes pastilles sont des entités statiques.Elles sont des items qui peuvent être consommés par les entités dynamiques.Elles présentent ces caractéristiques :
//elles sont de la taille d’une seule cellule
//il peut y avoir np pastilles présentes dans l’arène(np ≥ 0)
//elles peuvent être insérées à n’importe quel moment de la partie
//une pastille, lorsque consommée, applique un effet sur l’entité dynamique concernée :
//l’effet de la pastille est paramétrable en amplitude
//suivant le type d’effet et son amplitude, un pointage lui est assigné
//le type d’effet est reconnaissable par sa couleur :
//rouge : accroissement de la longueur du serpent
//orange : réduction de la longueur du serpent
//magenta : accroissement de la vitesse du serpent
//violet : réduction de la vitesse du serpent
//vert : empoisonnement du serpent – ce dernier ne peut plus changer de direction pendant un certain temps
//bleu : téléportation de la tête du serpent

//prenez note que seules les pastilles rouge et magenta sont obligatoires à réaliser, les autres sont là à titre d’indication
//lorsqu’une entité dynamique se déplace sur la pastille :
//la pastille est consommée par l’entité dynamique
//l’entité dynamique est modifiée par l’effet de la pastille
//l’entité dynamique s’approprie le pointage de la pastille
//la pastille étant consommée est retirée de la partie
//même si la pastille est généralement présente tant qu’une entité ne l’ait pas consommée, sa durée de vie peut être limitée
class Pellet : public StaticEntity
{
public:
	Pellet() = default;
	~Pellet() = default;
	int score() const { return mScore; }
	void setScore(int score) { mScore = score; }
	virtual void applyEffectOnSnake(Snake& snake);
private:
	int mScore;

};
#endif //PELLET_H