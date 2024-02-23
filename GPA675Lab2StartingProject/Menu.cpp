#include "Menu.h"
#include <QPushButton>
#include <QVBoxLayout>

Menu::Menu(QWidget* parent)
	: QMainWindow(parent)
{
	// Cr�er les boutons Exit et Start
	QPushButton* exitButton = new QPushButton("Exit", this);
	QPushButton* startButton = new QPushButton("Start", this);

	
	// Cr�er un layout vertical
	QVBoxLayout* layout = new QVBoxLayout;

	// Ajouter les boutons au layout
	layout->addWidget(exitButton);
	layout->addWidget(startButton);

	// Cr�er un widget central pour la fen�tre
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);

	// D�finir le widget central de la fen�tre principale
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