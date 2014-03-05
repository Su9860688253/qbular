LEDCube
====

About
----
This program is an expanded version of the demo user interface
from Assignment 1. This program has an actual [OpenGL][1]
simulation, unlike the program from Assignment 1, which
contained a placeholder for a simulation. The simulation
consists of a 3D cube that can be rotated by clicking and
dragging the cube. The code from this simulation is from
[this Qt SDK example][2].

Just to recap: This program is a demo of the user interface for
an application that simulates a popular electronics project
called an [LED cube][3]. An LED cube is a lattice-shaped
structure of Light Emitting Diodes (LED) that are controlled by
a microcontroller, like an [Arduino][4], for the purpose of
putting on a 3D light show. This program is written in [C++][5]
and uses the [Qt framework][6].

Installation
----
    hg clone https://bitbucket.org/ian_s_mcb/software-design-spring2014
    cd software-design-spring2014/assign-2/ledcube
    qmake
    make
    ./ledcube

Prerequisites
----
* [Qt library][7] version 4.x or higher


[1]: http://www.opengl.org/
[2]: http://qt-project.org/doc/qt-4.8/opengl-cube.html
[3]: http://www.instructables.com/id/Led-Cube-8x8x8/
[4]: http://en.wikipedia.org/wiki/Arduino
[5]: http://en.wikipedia.org/wiki/C%2B%2B
[6]: http://en.wikipedia.org/wiki/Qt_%28software%29
[7]: https://qt-project.org/downloads
