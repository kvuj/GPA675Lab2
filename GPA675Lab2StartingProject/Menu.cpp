#include "Menu.h"
#include <QPushButton>
#include <QVBoxLayout>

Menu::Menu(QWidget* parent)
	: QMainWindow(parent)
{
	// Créer les boutons Exit et Start
	QPushButton* exitButton = new QPushButton("Exit", this);
	QPushButton* startButton = new QPushButton("Start", this);

	
	// Créer un layout vertical
	QVBoxLayout* layout = new QVBoxLayout;

	// Ajouter les boutons au layout
	layout->addWidget(exitButton);
	layout->addWidget(startButton);

	// Créer un widget central pour la fenêtre
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);

	// Définir le widget central de la fenêtre principale
	setCentralWidget(centralWidget);

	// Connecter les signaux des boutons aux slots de la classe
	connect(exitButton, &QPushButton::clicked, this,&Menu::Exit  );
	connect(startButton, &QPushButton::clicked, this,&Menu::Start);
}

void Menu::Exit()
{
	
	close();
}

void Menu::Start()
{
	hide();
}