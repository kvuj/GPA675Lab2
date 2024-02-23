#pragma once
#ifndef MENU_H
#define MENU_H
#include <QMainWindow>
#include "ui_Menu.h"


#include <QPushButton>


class Menu : public QMainWindow
{
	Q_OBJECT



    public:
        Menu(QWidget* parent = nullptr);

    private slots:
        void Exit();
        void Start();

	private:

};

#endif // MENU_H
