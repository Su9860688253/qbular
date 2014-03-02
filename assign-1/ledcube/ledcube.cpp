#include <QtGui>
#include "ledcube.h"

LedCube::LedCube(QWidget *parent)
    : QWidget(parent)
{
    simPlaceholder = new QLabel(tr("Placeholder"), this);
}
