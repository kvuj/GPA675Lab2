#include "Menu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <qcombobox.h>

Menu::Menu( QWidget* parent) 
	: QMainWindow(parent)
{
	// Créer les boutons Exit et Start

	QPushButton* startButton = new QPushButton("Start", this);
	QPushButton* exitButton = new QPushButton("Exit", this);
	QLabel* configurationLabel = new QLabel("Configuration de jeu", this);

	mConfigurationComboBox = new QComboBox(this);
	mConfigurationComboBox->addItem("SnakeOrigin");
	mConfigurationComboBox->addItem("SnakeBlockade");
	mConfigurationComboBox->addItem("Snakify");

	mGame = new SnakeGameApplication;
	
	// Créer un layout vertical
	QVBoxLayout* layout = new QVBoxLayout;

	// Ajouter les boutons au layout

    layout->addWidget(configurationLabel);
    layout->addWidget(mConfigurationComboBox);
	layout->addWidget(startButton);
	layout->addWidget(exitButton);
	

	// Créer un widget central pour la fenêtre
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);

	// Définir le widget central de la fenêtre principale
	setCentralWidget(centralWidget);

	// Connecter les signaux des boutons aux slots de la classe
	connect(exitButton, &QPushButton::clicked, this,&Menu::Exit  );
	connect(startButton, &QPushButton::clicked, this, &Menu::Start);

	
}

void Menu::Exit()
{
	
	close();
}

void Menu::Start()
{
	// Récupérer le texte sélectionné dans le QComboBox
	QString selectedText = mConfigurationComboBox->currentText();
	//On lance le jeu avec la configuration sélectionnée
	mGame->show();
	close();
}