LEDCube
====

About
----
This program is an updated version of the program from Assignment 1.
This program has an actual [OpenGL][1] simulation, unlike the 
program from Assignment 1, which contained a placeholder for a 
simulation. The simulation consists of a 3D cube that can be 
rotated by clicking and dragging the cube. The code from this 
simulation was taken from [this Qt SDK example][2].

Just to recap: this program is a simulation tool for a popular 
electronics project called an [LED cube][3]. An LED cube is a 
lattice-shaped structure of Light Emitting Diodes (LED) that are 
controlled by a microcontroller, like an [Arduino][4], for the 
purpose of putting on a 3D light show. This simulation tool for 
LED cubes is helpful for two reasons. 1) It makes it possible to 
design custom light shows without dealing with hardware details. 
2) It helps gauge how large of a cube is needed to properly 
display a given light show.

This program is written in [C++][5], and it uses the 
[Qt framework][6] for the Graphical User Interface (GUI) widgets 
and [OpenGL][1] for the graphics simulation.

Installation
----
    hg clone https://bitbucket.org/ian_s_mcb/software-design-spring2014
    cd software-design-spring2014/assign-2
    qmake
    make
    ./ledcube

Prerequisites
----
* [Qt library][7] version 4.x or higher
* [OpenGL][8] version 2.1 or higher


[1]: http://www.opengl.org/
[2]: http://qt-project.org/doc/qt-4.8/opengl-cube.html
[3]: http://www.instructables.com/id/Led-Cube-8x8x8/
[4]: http://en.wikipedia.org/wiki/Arduino
[5]: http://en.wikipedia.org/wiki/C%2B%2B
[6]: http://en.wikipedia.org/wiki/Qt_%28software%29
[7]: https://qt-project.org/downloads
[8]: http://www.opengl.org/documentation/implementations/
