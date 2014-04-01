#include <QtGui>
#include <QtOpenGL>

#include "simulationWidget.h"


SimulationWidget::SimulationWidget(Properties *prop, QWidget *parent)
    :   QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
        zoom(prop->zoom),
        xRot(prop->xRot),
        yRot(prop->yRot),
        zRot(prop->zRot),
        length(prop->length),
        width(prop->width),
        height(prop->height),
        spacing(prop->spacing),
        color(prop->color),
        draw(prop->draw),
        source(prop->source),
        function(prop->function)
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
    
    //set zoom
    float fraction = this->zoom / 100.0;
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glScalef(fraction, fraction, fraction);
    //glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, 15.0);
    //glMatrixMode(GL_MODELVIEW);

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

    //makes points larger
    glPointSize(2);

    //loop over lattice dimensions
    int i, j, k;
    for (i = 0; i < this->height; i++)
    {
        for (j = 0; j < this->width; j++)
        {
            for (k = 0; k < this->length; k++)
            {
                if (this->draw == "cubes")
                    paintCube();
                else
                {
                    glBegin(GL_POINTS);
                    glVertex3f(0, 0, 0);
                    glEnd();
                }
                //advance in the x direction
                glTranslatef(this->spacing, 0.0, 0.0);
            }

            //retreat in the x direction and advance in the
            //y direction
            glTranslatef(-1 * this->length * this->spacing,
                this->spacing, 0.0);
        }

        //retreat in the y direction and advance in the z direction
        glTranslatef(0.0, -1 * this->width * this->spacing,
            this->spacing);
    }
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
    this->lastPos = event->pos();
}//end mousePressEvent


void
SimulationWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - this->lastPos.x();
    int dy = event->y() - this->lastPos.y();

    if (event->buttons() & Qt::LeftButton)
    {
        setXRot(this->xRot + dy);
        setYRot(this->yRot + dx);
    }
    else if (event->buttons() & Qt::RightButton)
        setZRot(this->zRot + dx);

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
SimulationWidget::setZoom(int z)
{
    this->zoom = z;
    updateGL();
}//end setZoom


void
SimulationWidget::setXRot(int a)
{
    normalizeAngle(a);
    if (a != xRot) {
        xRot = a;
        emit xRotChanged(a);
        updateGL();
    }
}//end setXRot


void
SimulationWidget::setYRot(int a)
{
    normalizeAngle(a);
    if (a != yRot) {
        yRot = a;
        emit yRotChanged(a);
        updateGL();
    }
}//end setYRot


void
SimulationWidget::setZRot(int a)
{
    normalizeAngle(a);
    if (a != zRot) {
        zRot = a;
        emit zRotChanged(a);
        updateGL();
    }
}//end setZRot


void
SimulationWidget::setLength(int l)
{
    this->length = l;
    updateGL();
}//end set


void
SimulationWidget::setWidth(int w)
{
    this->width = w;
    updateGL();
}//end set


void
SimulationWidget::setHeight(int h)
{
    this->height = h;
    updateGL();
}//end set


void
SimulationWidget::setSpacing(double s)
{
    this->spacing = s;
    updateGL();
}//end setSpacing


void
SimulationWidget::setColor(const QString &c)
{
    this->color = c.toLower();
    this->updateGL();
}//end setColor


void
SimulationWidget::setDraw(const QString &d)
{
    this->draw = d.toLower();
    this->updateGL();
}//end setDraw
