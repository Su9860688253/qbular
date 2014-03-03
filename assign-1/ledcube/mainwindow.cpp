#include <QtGui>
#include "mainwindow.h"
#include "ledcube.h"

//#include "ledcube.h"
/*
    Creates an instance of the LedCube class, sets it as the
    central widget, and sets a window icon.
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ledCube = new LedCube();
    setCentralWidget(ledCube);

    //set window icon
    QIcon *icon_ptr = new QIcon(":/images/icon.png");
    const QIcon &icon_ref = *icon_ptr;
    setWindowIcon(icon_ref);
}
