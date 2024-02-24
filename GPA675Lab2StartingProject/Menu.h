#pragma once
#ifndef MENU_H
#define MENU_H
#include <QMainWindow>
#include "ui_Menu.h"


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

    signals:


	private:
        SnakeGameApplication* mGame;
        QComboBox* mConfigurationComboBox;

};

#endif // MENU_H
