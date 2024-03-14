#include "Menu.h"
#include "Tests.h"
#include "SnakeGameApplication.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
#ifdef _DEBUG
	Tests t;
	t.runTests();
#endif

	QApplication application(argc, argv);
	SnakeGameApplication snakeGameApp = SnakeGameApplication();
	snakeGameApp.show();
	return application.exec();
}
