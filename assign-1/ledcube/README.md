LEDCube
====

About
----
This program is a demo of the user interface for application that simulates an popular electronics project called an [LED cube][1]. An LED cube is a lattice-shaped structure of Light Emitting Diodes (LED) that are controlled by a microcontroller, like an [Arduino][2], for the purpose of putting on a 3D light show. This program is written in [C++][3] and uses the [Qt framework][4].

Installation
----
    hg clone https://bitbucket.org/ian_s_mcb/software-design-spring2014
    cd software-design-spring2014/assign-1/ledcube
    qmake
    make
    ./ledcube

Prerequisites
----
* [Qt library][5] version 4.x or higher

Specs
----
* one panel for the OpenGL simulation
    * serves as a placehold for now
    * eventually will contain a QGlWidget object
* group boxes for options that control the following:
    * transforms
    * resolution
    * LED spacing
    * LED color
* transforms options
    * specifies the x/y/z rotation and zoom
    * uses sliders + spinbox widgets
* resolution controls
    * specifies the dimension of the cube (in terms of number of LEDs)
    * uses spinbox widgets
* LED spacing controls
    * units are inches
    * default value: 0.5"
* LED color controls
    * color choices: red, blue, green, white
    * uses radio button widgets
* sliders and spinboxes should be hooked together with signals/slots
* transform options should be in class of its own
* the other options should be grouped together in one class

[1]: http://www.instructables.com/id/Led-Cube-8x8x8/
[2]: http://en.wikipedia.org/wiki/Arduino
[3]: http://en.wikipedia.org/wiki/C%2B%2B
[4]: http://en.wikipedia.org/wiki/Qt_%28software%29
[5]: https://qt-project.org/downloads
