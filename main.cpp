#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameWindow w;
    w.DisplayGame();
    w.show();
    return a.exec();
}
