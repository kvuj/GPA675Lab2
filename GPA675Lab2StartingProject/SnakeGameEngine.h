#pragma once
#ifndef GAME_H
#define GAME_H

#include <array>
#include <cmath>
#include <list>
#include <memory>
#include <QSize>
#include <QPointF>
#include <QColor>

#include "Arena.h"
#include "PressedKeys.h"
#include "Entity.h"
#include "Snake.h"

class QPainter;

// 
// Classe SnakeGameEngine
// Classe représentant l'engin de jeu pour gérer la logique et l'affichage du jeu.
// 
// Cette classe encapsule l'état du jeu, y compris la position, la vitesse et l'apparence des éléments de jeu,
// et fournit des méthodes pour leur mise à jour et leur rendu.
class SnakeGameEngine
{
public:
	// 
	// Constructeur de la classe SnakeGameEngine.
	// Initialise l'état du jeu avec une taille spécifiée, configurant les paramètres par défaut pour les éléments du jeu.
	// 
	// > size Taille du canvas de jeu, généralement correspondant à la taille de la fenêtre de l'application.
	SnakeGameEngine(QSize const& size);
	// 
	// Destructeur par défaut.
	~SnakeGameEngine() = default;

	// 
	// Traite la logique du jeu pour un seul pas de simulation.
	// Met à jour l'état du jeu en fonction du temps écoulé et des entrées utilisateur (touches pressées).
	// 
	// > elapsedTime Temps écoulé depuis le dernier pas de simulation, en secondes.
	// > keys État actuel des touches pressées, utilisé pour contrôler les éléments de jeu.
	void process(qreal elapsedTime, PressedKeys const& keys);
	// 
	// Dessine les éléments du jeu sur le canvas fourni.
	// Utilise les paramètres actuels de l'état du jeu pour dessiner ses éléments sur le QPainter fourni.
	// 
	// > painter QPainter à utiliser pour le dessin, configuré avec le contexte graphique approprié.
	void draw(QPainter& painter);

	void addEntity(Entity* entity);
	std::list<Entity*>& entities();
	void clearAllEntities();

private:
	QSize mSize;        // Taille du canvas de jeu, en pixels, influençant la zone de mouvement des éléments de jeu.
	qreal mRadius;      // Rayon des éléments de jeu, en pixels, utilisé pour leur rendu.
	QPointF mPosition;  // Position actuelle de l'élément principal de jeu, en pixels, en coordonnées du canvas.
	qreal mSpeed;       // Vitesse de l'élément principal du jeu, en pixels par seconde.
	QColor mColor;      // Couleur de l'élément principal de jeu, utilisée lors du rendu.
	qreal mTotalElapsedTime; // Temps écoulé depuis le début du jeu, en secondes.
	static std::array<QColor, 2> mBackgroundColors; // Les couleurs définissant le fond de la scène. 

	// Liste des entités de jeu, utilisées pour gérer les éléments de jeu supplémentaires.
	//Utilisation de shared pointer interdite. 
	//utilisatino d'un pointeur classique en implémentant toute les fonctions virtuelle présente dans les Entity
	std::list<Entity*> mEntities;
	Arena mArena;


	//
	// Restreint la position fournie dans la scène.
	// 
	// Cette fonction ajuste la position pour s'assurer qu'elle reste dans la zone prédéterminée, 
	// les limites de l'espace de jeu.
	// 
	// Si la position dépasse les limites, elle est modifiée pour la ramener à l'intérieur de la 
	// zone autorisée. 
	// 
	// Cela peut impliquer la modification des coordonnées X et/ou Y de la position pour refléter 
	// la contrainte appliquée.
	void constrainPosition();

	// Fonctions utilitaires
	static QPointF getKeyboardDirection(PressedKeys const& keys);
	static QColor blendColorsHsl(QColor const& color1, QColor const& color2, qreal color1Ratio);
};


#endif // GAME_H