#include "Menu.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <qcombobox.h>

Menu::Menu(QWidget* parent)
	: QMainWindow(parent)
{
	// Créer les boutons Exit et Start

	QPushButton* startButton = new QPushButton("Start", this);
	QPushButton* exitButton = new QPushButton("Exit", this);
	QLabel* configurationLabel = new QLabel("Configuration de jeu", this);

	mGameType = new QComboBox(this);
	mGameType->addItem("SnakeOrigin");
	mGameType->addItem("SnakeBlockade");
	mGameType->addItem("Snakify");

	mKeyboardPlayer1 = new QComboBox(this);
	mKeyboardPlayer1->addItem("Absolu (WASD)");
	mKeyboardPlayer1->addItem("Relatif (AD)");

	mKeyboardPlayer2 = new QComboBox(this);
	mKeyboardPlayer2->addItem("Absolu (IJKL)");
	mKeyboardPlayer2->addItem("Relatif (JL)");

	QLabel* player1Label = new QLabel("Configuration clavier du joueur 1", this);
	QLabel* player2Label = new QLabel("Configuration clavier du joueur 2", this);

	auto line = new QFrame;
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);

	mGame = new SnakeGameApplication;

	// Créer un layout vertical
	QVBoxLayout* layout = new QVBoxLayout;

	// Ajouter les boutons au layout

	layout->addWidget(configurationLabel);
	layout->addWidget(mGameType);
	layout->addWidget(line);
	layout->addWidget(player1Label);
	layout->addWidget(mKeyboardPlayer1);
	layout->addWidget(player2Label);
	layout->addWidget(mKeyboardPlayer2);
	layout->addWidget(startButton);
	layout->addWidget(exitButton);


	// Créer un widget central pour la fenêtre
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);

	// Définir le widget central de la fenêtre principale
	setCentralWidget(centralWidget);

	// Connecter les signaux des boutons aux slots de la classe
	connect(exitButton, &QPushButton::clicked, this, &Menu::Exit);
	connect(startButton, &QPushButton::clicked, this, &Menu::Start);
}

void Menu::Exit()
{
	close();
}

void Menu::Start()
{
	// Récupérer le texte sélectionné dans le QComboBox
	QString selectedText = mGameType->currentText();

	// Clavier 1
	if (mKeyboardPlayer1->currentText() == "Absolu (WASD)")
		mGame->setKeyboardType1({ Qt::Key_W, Qt::Key_D, Qt::Key_S, Qt::Key_A });
	else
		mGame->setKeyboardType1({ Qt::Key_D, Qt::Key_A });

	// Clavier 2
	if (mKeyboardPlayer2->currentText() == "Absolu (IJKL)")
		mGame->setKeyboardType2({ Qt::Key_I, Qt::Key_L, Qt::Key_K, Qt::Key_J });
	else
		mGame->setKeyboardType2({ Qt::Key_L, Qt::Key_J });

	// On lance le jeu avec la configuration sélectionnée
	if (selectedText == "SnakeOrigin")
		mGame->setGameType(SnakeGameApplication::GameType::Origin);
	else if (selectedText == "SnakeBlockade")
		mGame->setGameType(SnakeGameApplication::GameType::Blockade);

	mGame->show();
	close();
}