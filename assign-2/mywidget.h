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
class QButtonGroup;
class MainWidget;
class QGroupBox;

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);

private:
/*
    QHBoxLayout *mainHLayout;
    QVBoxLayout *leftVLayout;
    QHBoxLayout *rightHLayout;

    QGroupBox *transformGroupBox;
    QGroupBox *countGroupBox;
    QGroupBox *spacingGroupBox;
    QGroupBox *colorGroupBox;

    MainWidget *mainWidget;
*/
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
    QSpinBox *distance;

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
