#ifndef SIMULATIONWIDGET_H
#define SIMULATIONWIDGET_H

#include <QtOpenGL/QGLWidget>


class QPoint;
class QAbstractButton;


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
    int zoom;
    int xRot;
    int yRot;
    int zRot;

    int length;
    int width;
    int height;

    double spacing;

    QString color;

    QPoint lastPos;

public slots:
    void setZoom(int z);
    void setXRot(int a);
    void setYRot(int a);
    void setZRot(int a);

    void setLength(int l);
    void setWidth(int w);
    void setHeight(int h);

    void setSpacing(double s);

    void setColor(QAbstractButton *b);

signals:
    void xRotChanged(int angle);
    void yRotChanged(int angle);
    void zRotChanged(int angle);
};
#endif
