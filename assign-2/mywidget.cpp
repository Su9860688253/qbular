#include <QtGui>
#include "mywidget.h"
#include "mainwidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
/*
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
*/
    //adds group boxes to left layout
    QVBoxLayout *left = new QVBoxLayout();
    left->addWidget(this->createTransformControls());
    left->addWidget(this->createCountControls());
    left->addWidget(this->createSpacingControls());
    left->addWidget(this->createColorControls());
    left->addStretch();

    //creates simulation and adds it the right layout
    QSize simulationSize(500, 500);
    this->mainWidget = new MainWidget();
    mainWidget->setMinimumSize(simulationSize);
    QHBoxLayout *right = new QHBoxLayout();
    right->addWidget(mainWidget);

    //adds controls and simulation to main layout
    QHBoxLayout *main = new QHBoxLayout();
    main->addLayout(left);
    main->addLayout(right);
    setLayout(main);

    //set the signal/slot connections
    this->setConnections();
}

QGroupBox *
MyWidget::createTransformControls()
{
    QGroupBox *groupBox = new QGroupBox("Transform");
    QSize size(400, 125);
    groupBox->setMinimumSize(size);

    return groupBox;
}

QGroupBox *
MyWidget::createCountControls()
{
    QGroupBox *groupBox = new QGroupBox("LED Count");
    QSize size(400, 125);
    groupBox->setMinimumSize(size);

    return groupBox;
}

QGroupBox *
MyWidget::createSpacingControls()
{
    QGroupBox *groupBox = new QGroupBox("LED Spacing");
    QSize size(400, 125);
    groupBox->setMinimumSize(size);

    return groupBox;
}

QGroupBox *
MyWidget::createColorControls()
{
    QGroupBox *groupBox = new QGroupBox("LED Color");
    QSize size(400, 125);
    groupBox->setMinimumSize(size);

    return groupBox;
}

void
MyWidget::setConnections()
{

}
