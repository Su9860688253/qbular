#include <QtGui>
#include "centralWidget.h"
#include "simulationWidget.h"


CentralWidget::CentralWidget(QWidget *parent)
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
    this->simulationWidget = new SimulationWidget();
    simulationWidget->setMinimumSize(simulationSize);
    QHBoxLayout *right = new QHBoxLayout();
    right->addWidget(simulationWidget);

    //adds controls and simulation to main layout
    QHBoxLayout *main = new QHBoxLayout();
    main->addLayout(left);
    main->addLayout(right);
    main->setStretchFactor(left, 0);
    main->setStretchFactor(right, 1);
    setLayout(main);

    //sets the signal/slot connections
    this->setConnections();

    //sets window title and icon
    this->setWindowTitle("LED Cube Simulation");
    QIcon *icon_ptr = new QIcon(":/images/icon.png");
    const QIcon &icon_ref = *icon_ptr;
    this->setWindowIcon(icon_ref);
}//end constructor


QGroupBox *
CentralWidget::createTransformControls()
{
    const int numOfSpinBoxes = 4, numOfProperties = 4;

    //Stores the text for each label. Each row represents a
    //different label.
    QString labelText[numOfSpinBoxes] = {
        "Zoom:",
        "X Rotation:",
        "Y Rotation:",
        "Z Rotation:"};

    //Stores the values of the spinbox properties. Each row
    //representes a different spinbox. The column 0 is the
    //min value, column 1 is the max value, and column
    //2 is the default value, column 3 is the step size.
    int spinBoxValues[numOfSpinBoxes][numOfProperties] = {
        {1,     400,    100,    5},
        {0,     360,    0,      5}, 
        {0,     360,    0,      5}, 
        {0,     360,    0,      5}};

    QGridLayout *grid = new QGridLayout();
    QLabel *label;
    QSlider *slider;
    QSpinBox *spinBoxes[numOfSpinBoxes];

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
        slider->setMaximum(spinBoxValues[i][1]);
        slider->setValue(spinBoxValues[i][2]);
        slider->setSingleStep(spinBoxValues[i][3]);
        grid->addWidget(slider, i, 1);

        //create spin box
        spinBoxes[i] = new QSpinBox();
        spinBoxes[i]->setMinimum(spinBoxValues[i][0]);
        spinBoxes[i]->setMaximum(spinBoxValues[i][1]);
        spinBoxes[i]->setValue(spinBoxValues[i][2]);
        spinBoxes[i]->setSingleStep(spinBoxValues[i][3]);
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
}//end createTransformControls()


QGroupBox *
CentralWidget::createCountControls()
{
    const int numOfSpinBoxes = 3, numOfProperties = 4;
    QGridLayout *grid = new QGridLayout();
    QLabel *label;
    QSpinBox *spinBoxes[numOfSpinBoxes];

    //Stores the text for each label. Each row represents a
    //different label.
    QString labelText[numOfSpinBoxes] = {
        "Length:",
        "Width:",
        "Height:"};

    //Stores the values of the spinbox properties. Column 0
    //is the min value, column 1 is the max value, column 2
    //is the default value, and column 3 is the single step
    //amount.
    double spinBoxValues[numOfProperties] = {
        1, 100, 1, 1};

    //for each spin box
    int i;
    for (i = 0; i < numOfSpinBoxes; i++)
    {
        //create label
        label = new QLabel(labelText[i]);
        grid->addWidget(label, i, 0);

        //create spin box
        spinBoxes[i] = new QSpinBox();
        spinBoxes[i]->setMinimum(spinBoxValues[0]);
        spinBoxes[i]->setMaximum(spinBoxValues[1]);
        spinBoxes[i]->setValue(spinBoxValues[2]);
        spinBoxes[i]->setSingleStep(spinBoxValues[3]);
        grid->addWidget(spinBoxes[i], i, 1);
    }

    //stores spin boxes as member variables
    this->length = spinBoxes[0];
    this->width= spinBoxes[1];
    this->height = spinBoxes[2];

    QGroupBox *groupBox = new QGroupBox("LED Count");
    groupBox->setLayout(grid);
    groupBox->setFixedWidth(400);

    return groupBox;
}//end createCountControls()


QGroupBox *
CentralWidget::createSpacingControls()
{
    const int numOfProperties = 4;

    //Stores the values of the spinbox properties. Column 0
    //is the min value, column 1 is the max value, column 2
    //is the default value, and column 3 is the step size.
    double spinBoxValues[numOfProperties] = {
        2.0,     5.0,      2.0,    0.5};

    QGridLayout *grid = new QGridLayout();

    //create label
    QLabel *label = new QLabel("Spacing:");
    grid->addWidget(label, 0, 0);

    //create spin box
    QDoubleSpinBox *spinBox = new QDoubleSpinBox();
    spinBox->setMinimum(spinBoxValues[0]);
    spinBox->setMaximum(spinBoxValues[1]);
    spinBox->setValue(spinBoxValues[2]);
    spinBox->setSingleStep(spinBoxValues[3]);
    grid->addWidget(spinBox, 0, 1);

    //stores spin boxes as member variables
    this->spacing = spinBox;

    QGroupBox *groupBox = new QGroupBox("LED Spacing");
    groupBox->setLayout(grid);
    groupBox->setFixedWidth(400);

    return groupBox;
}//end createSpacingControls()


QGroupBox *
CentralWidget::createColorControls()
{
    const int numOfButtons = 4;

    //Stores the text for each label. Each row represents a
    //different label.
    QString buttonText[numOfButtons] = {
        "Red:",
        "Blue:",
        "Green:",
        "White:"};

    QGridLayout *grid = new QGridLayout();
    QButtonGroup *group = new QButtonGroup();
    QRadioButton *button;

    //for each button
    int i;
    for (i = 0; i < numOfButtons; i++)
    {
        //create label
        button = new QRadioButton(buttonText[i]);
        group->addButton(button);
        grid->addWidget(button, (i % 2), (i > 1));

        //mark the green button as checked
        if (i == 2)
            button->setChecked(true);
    }

    //stores button group as a member variable
    this->color = group;

    QGroupBox *groupBox = new QGroupBox("LED Color");
    groupBox->setLayout(grid);
    groupBox->setFixedWidth(400);

    return groupBox;
}//end createColorControls()


void
CentralWidget::setConnections()
{
    //connect xRot spinbox to centralWidget
    connect(this->xRot, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setXRot(int)));
    connect(this->simulationWidget, SIGNAL(xRotChanged(int)),
        this->xRot, SLOT(setValue(int)));

    //connect zRot spinbox to simulationWidget
    connect(this->yRot, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setYRot(int)));
    connect(this->simulationWidget, SIGNAL(yRotChanged(int)),
        this->yRot, SLOT(setValue(int)));

    //connect zRot spinbox to simulationWidget
    connect(this->zRot, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setZRot(int)));
    connect(this->simulationWidget, SIGNAL(zRotChanged(int)),
        this->zRot, SLOT(setValue(int)));

    //connect zoom spinbox to simulationWidget
    connect(this->zoom, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setZoom(int)));

    //connect count spinboxes to simulationWidget
    connect(this->length, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setLength(int)));
    connect(this->width, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setWidth(int)));
    connect(this->height, SIGNAL(valueChanged(int)),
        this->simulationWidget, SLOT(setHeight(int)));

    //connect distance spinbox to simulationWidget
    connect(this->spacing, SIGNAL(valueChanged(double)),
        this->simulationWidget, SLOT(setSpacing(double)));

    //connect color buttons to simulationWidget
    connect(this->color, SIGNAL(buttonClicked(QAbstractButton *)),
        this->simulationWidget, SLOT(setColor(QAbstractButton *)));
}//end setConnections
