#pragma once
#ifndef MENU_H
#define MENU_H
#include <QMainWindow>
#include "ui_Menu.h"
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qtimer.h>
#include <qpushbutton.h>
#include <QLabel>
#include <QLCDNumber>
#include <QGraphicsRectItem>
#include <qslider.h>
#include <QHash>
#include <QList>
#include "qspinbox.h"


class Menu : public QMainWindow
{
	Q_OBJECT

public:

	explicit Menu (QWidget *parent = 0);
protected:
	void closeEvent(QCloseEvent *event);
private slots:
	void start();                   ///< Gèrer le bouton start.
	void pauseOrResume();           ///< Gèrer bouton pause/resume.
	void stop();                    ///< Gèrer bouton stop.

private:
	enum class SimulationState { Stopped, Running, Paused }; // les différents états de la simualtino
	SimulationState simulationState;
	void createWidgets();           ///< Créer les widgets du GUI.
	void createProxyWidgets();      ///< Ajouter les widgets dans la "scène".
	void createLayout();            ///< Ajouter les layouts pour la disposition des widgets.
	void createConnections();       ///< Créer les connexions signaux/slots.

	QPushButton* startButton;       ///< Démarrage..
	QPushButton* stopButton;        ///< Arrêt.
	QPushButton* quitButton;        ///< Quitter.

	QGraphicsScene* mScene;
	QGraphicsView* mView;
};

#endif // MENU_H
