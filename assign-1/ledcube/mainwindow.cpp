#include <QtGui>
#include "mainwindow.h"
#include "ledcube.h"

//#include "ledcube.h"
/*
    For now, all this does is add a label and sets it as the
    central widget
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ledCube = new LedCube();
    setCentralWidget(ledCube);
}