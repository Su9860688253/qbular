#include <QtGui>
#include <QtOpenGL>

#include "simulationWidget.h"


SimulationWidget::SimulationWidget(QWidget *parent)
    :   QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
        xRot(0),
        yRot(0),
        zRot(0),
        zoom(100),
        length(1),
        width(1),
        height(1),
        color("green")
{}//end constructor


void
SimulationWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}//end initializeGL


void
SimulationWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);

    //set x/y/z rotation
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);

    //set color
    float opacity = 0.75;
    if (this->color == "red")
        glColor4f(1.0, 0.0, 0.0, opacity);
    else if (this->color == "green")
        glColor4f(0.0, 1.0, 0.0, opacity);
    else if (this->color == "blue")
        glColor4f(0.0, 0.0, 1.0, opacity);
    else
        glColor4f(1.0, 1.0, 1.0, opacity);
/*
    int i, j, k, spacing = 1.5;
    for (i = 0; i < this->height; i++)
    {
        for (j = 0; j < this->width; j++)
        {
            for (k = 0; k < this->length; k++)
            {
                paintCube();
                glTranslatef(spacing, 0.0, 0.0);
            }
            glTranslatef(0.0, spacing, 0.0);
        }
        glTranslatef(0.0, 0.0, spacing);
    }
*/

/*
int i, j, direction, spacing = 2.0; 
for (i = 0, direction = 1; i < 5; i++, direction = -direction)
{
    for (j = 0; j < 5; j++)
    {
        paintCube();
        glTranslatef(direction * spacing, 0.0, 0.0);
    }
    glTranslatef(-spacing, spacing, 0.0);
}
*/

    paintCube();
}//end paintGL


void
SimulationWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}//end resizeGL


void
SimulationWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}//end mousePressEvent


void
SimulationWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - this->lastPos.x();
    int dy = event->y() - this->lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRot(this->xRot + dy);
        setYRot(this->yRot + dx);
    }
     else if (event->buttons() & Qt::RightButton) {
        setZRot(this->zRot + dx);
    }

    this->lastPos = event->pos();
}//end mouseMoveEvent


void
SimulationWidget::normalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360; 
    while (angle > 360)
        angle -= 360; 
}//end normalizeAngle


void
SimulationWidget::paintCube()
{
	//bottom
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

    //front
    glBegin(GL_POLYGON);
    glVertex3f( -0.5, -0.5, -0.5);
    glVertex3f( -0.5,  0.5, -0.5);
    glVertex3f(  0.5,  0.5, -0.5);
    glVertex3f(  0.5, -0.5, -0.5);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
}//end paintCube 


void
SimulationWidget::setXRot(int angle)
{
    normalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotChanged(angle);
        updateGL();
    }
}//end setXRot


void
SimulationWidget::setYRot(int angle)
{
    normalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotChanged(angle);
        updateGL();
    }
}//end setYRot


void
SimulationWidget::setZRot(int angle)
{
    normalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotChanged(angle);
        updateGL();
    }
}//end setZRot


void
SimulationWidget::setZoom(int zoom)
{

    if (zoom != this->zoom)
    {
        this->zoom = zoom;
        float z = this->zoom / 100.0;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glScalef(z, z, z);
        glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, 15.0);
        glMatrixMode(GL_MODELVIEW);
        updateGL();
    }
}//end setZoom


void
SimulationWidget::setLength(int l)
{
    if (l != this->length)
    {
        this->length = l;
        updateGL();
    }
}//end set


void
SimulationWidget::setWidth(int w)
{
    if (w != this->width)
    {
        this->width = w;
        updateGL();
    }
}//end set


void
SimulationWidget::setHeight(int h)
{
    if (h != this->height)
    {
        this->height = h;
        updateGL();
    }
}//end set


void
SimulationWidget::setColor(QAbstractButton *button)
{
    QString buttonText, newColor;

    //identify the pressed button
    buttonText = button->text();

    //trim off last character of buttonText
    newColor = buttonText.left(buttonText.length() - 1);

    //make text lowercase
    newColor = newColor.toLower();

    //store new color and redraw simulation if necessary
    if (newColor != this->color)
    {
        this->color = newColor;
        this->updateGL();
    }
}//end setColor
