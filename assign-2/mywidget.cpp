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

    //sets the signal/slot connections
    this->setConnections();

    //sets window title and icon
    this->setWindowTitle("LED Cube Simulation");
    QIcon *icon_ptr = new QIcon(":/images/icon.png");
    const QIcon &icon_ref = *icon_ptr;
    this->setWindowIcon(icon_ref);
}//constructor

QGroupBox *
MyWidget::createTransformControls()
{
    const int numOfSpinBoxes = 4, numOfProperties = 3;

    //Stores the text for each label. Each row represents a
    //different label.
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
    //is the default value, column 1 is the min value,
    //column 2 is the max value, and column 3 is the single
    //step amount.
    double spinBoxValues[numOfProperties] = {
        8,     3,      100,    1};

    //for each spin box
    int i;
    for (i = 0; i < numOfSpinBoxes; i++)
    {
        //create label
        label = new QLabel(labelText[i]);
        grid->addWidget(label, i, 0);

        //create spin box
        spinBoxes[i] = new QSpinBox();
        spinBoxes[i]->setValue(spinBoxValues[0]);
        spinBoxes[i]->setMinimum(spinBoxValues[1]);
        spinBoxes[i]->setMaximum(spinBoxValues[2]);
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
}//method createCountControls()

QGroupBox *
MyWidget::createSpacingControls()
{
    const int numOfProperties = 4;

    //Stores the values of the spinbox properties. Column 0
    //is the default value, column 1 is the min value,
    //column 2 is the max value, and column 3 is the single
    //step amount.
    double spinBoxValues[numOfProperties] = {
        0.5,     0.25,      6.0,    0.5};

    QGridLayout *grid = new QGridLayout();

    //create label
    QLabel *label = new QLabel("Distance:");
    grid->addWidget(label, 0, 0);

    //create spin box
    QDoubleSpinBox *spinBox = new QDoubleSpinBox();
    spinBox->setValue(spinBoxValues[0]);
    spinBox->setMinimum(spinBoxValues[1]);
    spinBox->setMaximum(spinBoxValues[2]);
    spinBox->setSingleStep(spinBoxValues[3]);
    grid->addWidget(spinBox, 0, 1);

    //stores spin boxes as member variables
    this->distance = spinBox;

    QGroupBox *groupBox = new QGroupBox("LED Spacing");
    groupBox->setLayout(grid);
    groupBox->setFixedWidth(400);

    return groupBox;
}//method createSpacingControls()

QGroupBox *
MyWidget::createColorControls()
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

        //mark the first button as checked
        if (i == 0)
            button->setChecked(true);
    }

    //stores button group as a member variable
    this->color = group;

    QGroupBox *groupBox = new QGroupBox("LED Color");
    groupBox->setLayout(grid);
    groupBox->setFixedWidth(400);

    return groupBox;
}//method createColorControls()

void
MyWidget::setConnections()
{

}
