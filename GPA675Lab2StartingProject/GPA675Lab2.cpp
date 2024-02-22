#include "GPA675Lab2.h"
#include "Snake.h"

#include <QDebug>
#include <QKeyEvent>
#include <QPainter>


GPA675Lab2::GPA675Lab2()
    : QWidget(nullptr)
    , mWindowSize(1024, 1024)
    , mTimer()
    , mElapsedTimer()
    , mPressedKeys()
    , mGame(mWindowSize)
    , mMenu()
{
    mMenu.show();
    // Configuration de la barre de titre de l'application
    setWindowTitle("Snake++");
    //setWindowIcon(...)

    // Configuration générale : taille et focus
    setFixedSize(mWindowSize);
    setFocusPolicy(Qt::StrongFocus);

    // Configuration de la boucle générale via l'objet 'timer'.
    mTimer.setSingleShot(true);
    connect(&mTimer, &QTimer::timeout, this, &GPA675Lab2::tic);
    mTimer.start();
}

void GPA675Lab2::keyPressEvent(QKeyEvent * event)
{
    if (!event->isAutoRepeat()) {
        mPressedKeys.push_back(static_cast<Qt::Key>(event->key()));
    }
}

void GPA675Lab2::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        auto it = std::find(mPressedKeys.begin(), mPressedKeys.end(), event->key());
        if (it != mPressedKeys.end()) {
            mPressedKeys.erase(it);
        }
    }
}

void GPA675Lab2::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    mGame.draw(painter);
}

void GPA675Lab2::tic()
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };

    mGame.process(elapsedTime, mPressedKeys);
    repaint();

    mTimer.start();
}