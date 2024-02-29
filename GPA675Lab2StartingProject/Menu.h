#pragma once
#ifndef MENU_H
#define MENU_H
#include <QMainWindow>
#include <QComboBox>


#include <QPushButton>
#include "SnakeGameApplication.h"


class Menu : public QMainWindow
{
	Q_OBJECT

public:
	Menu(QWidget* parent = nullptr);
	// Créer les widgets du GUI

private slots:
	void Exit();
	void Start();


private:
	SnakeGameApplication* mGame;
	QComboBox* mGameType;
	QComboBox* mKeyboardPlayer1;
	QComboBox* mKeyboardPlayer2;
};

#endif // MENU_H
