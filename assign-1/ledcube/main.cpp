#include <QApplication>
#include "ledcube.h"

/*
    Entry point for LedCube application
*/
int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LedCube *cube= new LedCube();
    cube->show();

    return app.exec();
}
