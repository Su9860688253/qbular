#include <QtGui>
#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *aLabel = new QLabel("bla bla bla", this);

    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addWidget(aLabel);
    setLayout(layoutMain);
}
