#include <QtGui>
#include "mywidget.h"
#include "mainwidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layoutMain = new QVBoxLayout();
    setLayout(layoutMain);

    QLabel *aLabel = new QLabel("bla bla bla", this);
    layoutMain->addWidget(aLabel);

    MainWidget *mainWidget = new MainWidget();
    layoutMain->addWidget(mainWidget);
}
