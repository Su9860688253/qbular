#ifndef SIMULATIONWIDGET_H
#define SIMULATIONWIDGET_H

#include <QtOpenGL/QGLWidget>


class QPoint;


class SimulationWidget : public QGLWidget 
{
    Q_OBJECT;
public:
    SimulationWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void normalizeAngle(int &angle);
    void paintCube();

private:
    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;

public slots:
    void setXRot(int angle);
    void setYRot(int angle);
    void setZRot(int angle);

signals:
    void xRotChanged(int angle);
    void yRotChanged(int angle);
    void zRotChanged(int angle);

    void zoomChanged(int zoom);
};
#endif
