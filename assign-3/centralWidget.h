#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include "properties.h"

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
    Properties *defaultProperties;

    //transform controls
    QSpinBox *zoom;
    QSpinBox *xRot;
    QSpinBox *yRot;
    QSpinBox *zRot;

    //lattice size controls
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
    void setDefaultProperties();
    QGroupBox *createTransformControls();
    QGroupBox *createSizeControls();
    QGroupBox *createSpacingControls();
    QGroupBox *createColorControls();
    void setConnections();
};
#endif
