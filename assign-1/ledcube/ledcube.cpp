#include <QtGui>
#include "ledcube.h"
/*
    For now, all this does is add a label and sets it as the
    central widget
*/

LedCube::LedCube(QWidget *parent)
    : QMainWindow(parent)
{
    dummyWidget = new QLabel("Hello, world!");
    setCentralWidget(dummyWidget);
}
