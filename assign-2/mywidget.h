#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

/*
class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;
class QLabel;
class QSpinBox;
class QRadioButton;
class QSlider;
class MainWidget;
*/

class QSpinBox;
class QDoubleSpinBox;
class QButtonGroup;
class MainWidget;
class QGroupBox;

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);

private:
    //transform controls
    QSpinBox *zoom;
    QSpinBox *xRot;
    QSpinBox *yRot;
    QSpinBox *zRot;

    //count controls
    QSpinBox *length;
    QSpinBox *width;
    QSpinBox *height;

    //distance controls
    QDoubleSpinBox *distance;

    //color controls
    QButtonGroup *color;

    //simulation
    MainWidget *mainWidget; 

    //helper functions for constructor
    QGroupBox *createTransformControls();
    QGroupBox *createCountControls();
    QGroupBox *createSpacingControls();
    QGroupBox *createColorControls();
    void setConnections();
};
#endif
