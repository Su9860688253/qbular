#ifndef PROPERTIES_H
#define PROPERTIES_H

class QString;


typedef struct properties
{
    int zoom;
    int xRot;
    int yRot;
    int zRot;

    int length;
    int width;
    int height;

    double spacing;

    QString color;
} Properties;
#endif
