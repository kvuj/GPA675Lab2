#include "Menu.h"
#include "Tests.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    Tests t;
    t.runTests();
#endif

    QApplication application(argc, argv);
    Menu window;
    window.show();
    return application.exec();
}
