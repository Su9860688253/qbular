#include <QtGui>
#include "mywidget.h"
#include "mainwidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
/*
    QVBoxLayout *layoutMain = new QVBoxLayout();
    setLayout(layoutMain);

    QLabel *aLabel = new QLabel("bla bla bla", this);
    layoutMain->addWidget(aLabel);

    MainWidget *mainWidget = new MainWidget();
    layoutMain->addWidget(mainWidget);
*/
//creates group boxes
transformGroupBox = new QGroupBox("Transform");
countGroupBox = new QGroupBox("LED Count");
spacingGroupBox = new QGroupBox("LED Spacing");
colorGroupBox = new QGroupBox("LED Color");

//sets min and max size of group boxes
QSize groupBoxSize(250, 125);
transformGroupBox->setMinimumSize(groupBoxSize);
countGroupBox->setMinimumSize(groupBoxSize);
spacingGroupBox->setMinimumSize(groupBoxSize);
colorGroupBox->setMinimumSize(groupBoxSize);

transformGroupBox->setMaximumSize(groupBoxSize);
countGroupBox->setMaximumSize(groupBoxSize);
spacingGroupBox->setMaximumSize(groupBoxSize);
colorGroupBox->setMaximumSize(groupBoxSize);

//adds group boxes to left layout
leftLayout = new QVBoxLayout();
leftLayout->addWidget(transformGroupBox);
leftLayout->addWidget(countGroupBox);
leftLayout->addWidget(spacingGroupBox);
leftLayout->addWidget(colorGroupBox);
leftLayout->addStretch();

//creates simulation and adds it the right layout
QSize simulationSize(500, 500);
mainWidget = new MainWidget();
mainWidget->setMinimumSize(simulationSize);
rightLayout = new QHBoxLayout();
rightLayout->addWidget(mainWidget);

//adds controls and simulation to main layout
mainLayout = new QHBoxLayout();
mainLayout->addLayout(leftLayout);
mainLayout->addLayout(rightLayout);
setLayout(mainLayout);
}
