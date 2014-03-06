#include <QtGui>
#include "mywidget.h"
#include "mainwidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
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
