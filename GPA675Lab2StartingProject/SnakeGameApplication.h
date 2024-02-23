#pragma once
#ifndef GPA675_LAB2
#define GPA675_LAB2

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QElapsedTimer>

#include "SnakeGameEngine.h"
#include "Entity.h"
#include "Menu.h"

// 
// Classe SnakeGameApplication
// Classe principale pour le projet de laboratoire du cours GPA675.
// 
// Cette classe hérite de QWidget et constitue le point d'entrée principal de l'application.
// Elle gère les événements clés, l'affichage du widget et la boucle de simulation du jeu.
class SnakeGameApplication : public QWidget
{
    Q_OBJECT

public:
    // 
    // Constructeur par défaut.
    // Initialise la fenêtre, configure le timer et prépare l'environnement du jeu.
    SnakeGameApplication();
    // 
    // Destructeur par défaut.
    // Nettoie les ressources utilisées par l'application. L'implémentation par défaut est suffisante.
    ~SnakeGameApplication() override = default;

protected:
    // 
    // Gestionnaire d'événements pour les appuis de touches du clavier.
    // Enregistre les touches actuellement pressées pour gérer les commandes de jeu.
    // 
    // * On remarque que la fonction est une substitution de la classe parent.
    // 
    // > event Détails de l'événement d'appui de touche.
    void keyPressEvent(QKeyEvent* event) override;
    // 
    // Gestionnaire d'événements pour les relâchements de touches du clavier.
    // Met à jour l'état des touches pour refléter les touches relâchées.
    // 
    // * On remarque que la fonction est une substitution de la classe parent.
    // 
    // > event Détails de l'événement de relâchement de touche.
    void keyReleaseEvent(QKeyEvent* event) override;
    // 
    // Gestionnaire d'événements pour l'affichage du widget.
    // Dessine le contenu du jeu dans la fenêtre de l'application.
    // 
    // * On remarque que la fonction est une substitution de la classe parent.
    // 
    // > event Détails de l'événement de peinture.
    void paintEvent(QPaintEvent* event) override;

   

private slots:
    // 
    // Slot appelé à chaque tic du timer.
    // 
    // Met à jour l'état du jeu et déclenche un rafraîchissement de l'affichage.
    void tic();

private:
    QSize const mWindowSize;        // Taille immuable de la fenêtre de l'application.
    QTimer mTimer;                  // Timer pour gérer la boucle de simulation à intervalles réguliers.
    QElapsedTimer mElapsedTimer;    // Chronomètre pour mesurer les intervalles de temps entre les tics.
    PressedKeys mPressedKeys;       // Structure pour gérer l'état des touches du clavier pressées.

    SnakeGameEngine mGame;                     // Instance de l'engin de jeu gérant la logique et l'état du jeu.
    Menu mMenu;
};



#endif // GPA675_LAB2