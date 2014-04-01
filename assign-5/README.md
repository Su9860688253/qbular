LEDCube
====

About
----
This program is an updated version of the program from Assignment 4. 
<<DESCRIPTION_HERE>>

Just to recap: this program is a simulation tool for a popular 
electronics project called an [LED cube][1]. An LED cube is a 
lattice-shaped structure of Light Emitting Diodes (LED) that are 
controlled by a microcontroller, like an [Arduino][2], for the 
purpose of putting on a 3D light show. This simulation tool for 
LED cubes is helpful for two reasons. 1) It makes it possible to 
design custom light shows without dealing with hardware details. 
2) It helps gauge how large of a cube is needed to properly 
display a given light show.

This program is written in [C++][3], and it uses the 
[Qt framework][4] for the Graphical User Interface (GUI) widgets 
and [OpenGL][5] for the graphics simulation.

Installation
----
    hg clone https://bitbucket.org/ian_s_mcb/software-design-spring2014
    cd software-design-spring2014/assign-5
    qmake
    make
    ./ledcube

Prerequisites
----
* [Qt library][6] version 4.x or higher
* [OpenGL][7] version 2.1 or higher


[1]: http://www.instructables.com/id/Led-Cube-8x8x8/
[2]: http://en.wikipedia.org/wiki/Arduino
[3]: http://en.wikipedia.org/wiki/C%2B%2B
[4]: http://en.wikipedia.org/wiki/Qt_%28software%29
[5]: http://www.opengl.org/
[6]: https://qt-project.org/downloads
[7]: http://www.opengl.org/documentation/implementations/
