#include "Menu.h"
#include <QApplication>
#include <QCheckBox>
#include <QGraphicsLinearLayout>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QLCDNumber>
#include <QList>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>

Menu::Menu(QWidget *parent)
	: QMainWindow(parent)
	, simulationState(SimulationState::Stopped)
{
	mScene = new QGraphicsScene;
	mScene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // Cr�er les widgets du GUI
    createWidgets();
    // Ajouter les widgets dans la sc�ne par methode proxy
    createProxyWidgets();
    // Ajouter des layouts appropri�s pour le GUI
    createLayout();
    // Cr�er les connexions signaux / slots
    createConnections();

}

void Menu::closeEvent(QCloseEvent* event)
{
	// Fermer l'application
	QApplication::quit();
}

void Menu::start()
{
	// Changer l'�tat de la simulation
	simulationState = SimulationState::Running;
}

void Menu::pauseOrResume()
{
	// Changer l'�tat de la simulation
	if (simulationState == SimulationState::Running)
	{
		simulationState = SimulationState::Paused;
	}
	else if (simulationState == SimulationState::Paused)
	{
		simulationState = SimulationState::Running;
	}
}

void Menu::stop()
{
	// Changer l'�tat de la simulation
	simulationState = SimulationState::Stopped;
}

void Menu::createWidgets()
{
	// Cr�er les boutons
	startButton = new QPushButton(tr("St&art"));
	stopButton = new QPushButton(tr("St&op"));
	quitButton = new QPushButton(tr("Qu&it"));
}

void Menu::createProxyWidgets()
{
	mScene->addWidget(startButton);
}

void Menu::createLayout()
{
}

void Menu::createConnections()
{
	// Connecter les signaux / slots
	connect(startButton, &QPushButton::clicked, this, &Menu::start);
	connect(stopButton, &QPushButton::clicked, this, &Menu::stop);
	connect(quitButton, &QPushButton::clicked, this, &Menu::close);
}
