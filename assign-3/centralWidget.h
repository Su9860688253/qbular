#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>


class QSpinBox;
class QDoubleSpinBox;
class QButtonGroup;
class SimulationWidget;
class QGroupBox;


class CentralWidget : public QWidget
{
public:
    CentralWidget(QWidget *parent = 0);

private:
    //transform controls
    QSpinBox *zoom;
    QSpinBox *xRot;
    QSpinBox *yRot;
    QSpinBox *zRot;

    //led count controls
    QSpinBox *length;
    QSpinBox *width;
    QSpinBox *height;

    //led spacing controls
    QDoubleSpinBox *spacing;

    //led color controls
    QButtonGroup *color;

    //simulation
    SimulationWidget *simulationWidget; 

    //helper functions for constructor
    QGroupBox *createTransformControls();
    QGroupBox *createCountControls();
    QGroupBox *createSpacingControls();
    QGroupBox *createColorControls();
    void setConnections();
};
#endif
