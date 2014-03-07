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
}//constructor

QGroupBox *
MyWidget::createTransformControls()
{
    //Stores the text for each label. Each row represents a
    //different label.
    const int numOfSpinBoxes = 4, numOfProperties = 3;
    QString labelText[numOfSpinBoxes] = {
        "Zoom:",
        "X Rotation:",
        "Y Rotation:",
        "Z Rotation:"};

    //Stores the values of the spinbox properties. Each row
    //representes a different spinbox. The column 0 is the
    //default value, column 1 is the min value, and column
    //2 is the max value.
    int spinBoxValues[numOfSpinBoxes][numOfProperties] = {
        {100,   30,     400},
        {0,     -360,   360}, 
        {0,     -360,   360}, 
        {0,     -360,   360} };

    QGridLayout *grid = new QGridLayout();
    QLabel *label;
    QSlider *slider;
    QSpinBox *spinBoxes[4];

    //for each spin box
    int i;
    for (i = 0; i < numOfSpinBoxes; i++)
    {
        //create label
        label = new QLabel(labelText[i]);
        grid->addWidget(label, i, 0);

        //create slider
        slider = new QSlider(Qt::Horizontal);
        slider->setMinimum(spinBoxValues[i][0]);
        slider->setMinimum(spinBoxValues[i][1]);
        slider->setMaximum(spinBoxValues[i][2]);
        grid->addWidget(slider, i, 1);

        //create spin box
        spinBoxes[i] = new QSpinBox();
        spinBoxes[i]->setMinimum(spinBoxValues[i][0]);
        spinBoxes[i]->setMinimum(spinBoxValues[i][1]);
        spinBoxes[i]->setMaximum(spinBoxValues[i][2]);
        grid->addWidget(spinBoxes[i], i, 2);

        //set signal/slot connections
        QObject::connect(slider, SIGNAL(valueChanged(int)),
                spinBoxes[i], SLOT(setValue(int)));
        QObject::connect(spinBoxes[i], SIGNAL(valueChanged(int)),
                slider, SLOT(setValue(int)));
    }

    //stores spin boxes as member variables
    this->zoom = spinBoxes[0];
    this->xRot = spinBoxes[1];
    this->yRot = spinBoxes[2];
    this->zRot = spinBoxes[3];

    QGroupBox *groupBox = new QGroupBox("Transform");
    groupBox->setLayout(grid);
    groupBox->setFixedWidth(400);

    return groupBox;
}//method createTransformControls()

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
