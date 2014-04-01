LEDCube
====

About
----
This program is an updated version of the program from Assignment 2. 
This program has an custom-made [OpenGL][1] simulation, unlike the 
program from Assignment 2, which contained a stock simulation. The 
simulation consists of a lattice of cubes that can be modififed by 
both the controls from Assignment 1 and mouse movements.

Just to recap: this program is a simulation tool for a popular 
electronics project called an [LED cube][2]. An LED cube is a 
lattice-shaped structure of Light Emitting Diodes (LED) that are 
controlled by a microcontroller, like an [Arduino][3], for the 
purpose of putting on a 3D light show. This simulation tool for 
LED cubes is helpful for two reasons. 1) It makes it possible to 
design custom light shows without dealing with hardware details. 
2) It helps gauge how large of a cube is needed to properly 
display a given light show.

This program is written in [C++][4], and it uses the 
[Qt framework][5] for the Graphical User Interface (GUI) widgets 
and [OpenGL][1] for the graphics simulation.

Installation
----
    hg clone https://bitbucket.org/ian_s_mcb/software-design-spring2014
    cd software-design-spring2014/assign-3
    qmake
    make
    ./ledcube

Prerequisites
----
* [Qt library][6] version 4.x or higher
* [OpenGL][7] version 2.1 or higher


[1]: http://www.opengl.org/
[2]: http://www.instructables.com/id/Led-Cube-8x8x8/
[3]: http://en.wikipedia.org/wiki/Arduino
[4]: http://en.wikipedia.org/wiki/C%2B%2B
[5]: http://en.wikipedia.org/wiki/Qt_%28software%29
[6]: https://qt-project.org/downloads
[7]: http://www.opengl.org/documentation/implementations/
