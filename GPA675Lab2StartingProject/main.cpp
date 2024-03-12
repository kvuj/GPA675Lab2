#include "Menu.h"
#include "Tests.h"
#include "SnakeGameApplication.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    Tests t;
    t.runTests();
#endif

    QApplication application(argc, argv);
    SnakeGameApplication snakeGameApp = SnakeGameApplication();
	try
	{
		snakeGameApp.show();
		return application.exec();
	}
	catch (...)
	{
		return 0;
	}
    
	return 0;
}
