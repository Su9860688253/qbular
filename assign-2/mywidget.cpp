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
leftVLayout = new QVBoxLayout();
leftVLayout->addWidget(transformGroupBox);
leftVLayout->addWidget(countGroupBox);
leftVLayout->addWidget(spacingGroupBox);
leftVLayout->addWidget(colorGroupBox);
leftVLayout->addStretch();

//creates simulation and adds it the right layout
QSize simulationSize(500, 500);
mainWidget = new MainWidget();
mainWidget->setMinimumSize(simulationSize);
rightHLayout = new QHBoxLayout();
rightHLayout->addWidget(mainWidget);

//adds controls and simulation to main layout
mainHLayout = new QHBoxLayout();
mainHLayout->addLayout(leftVLayout);
mainHLayout->addLayout(rightHLayout);
setLayout(mainHLayout);
}
