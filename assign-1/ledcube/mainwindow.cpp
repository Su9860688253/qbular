#include <QtGui>
#include "mainwindow.h"
/*
    For now, all this does is add a label and sets it as the
    central widget
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    dummyWidget = new QLabel("Hello, world!", centralWidget);
}
