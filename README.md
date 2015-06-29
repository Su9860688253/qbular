# Qbular#
`qbular` is a simulation tool for a LED Cube and LED Cube animation design. An [LED Cube][instructables] is a common hobbyist electronic device. Their purpose is to display animation, or simple graphics, in an immersive, 3D way. Another way to describe them is "a poor man's hologram." They look something like this:

![Photo of LED cube](http://cdn.instructables.com/FUX/O1RW/GICYBAOS/FUXO1RWGICYBAOS.MEDIUM.jpg)

This tool makes it possible to design cube graphics without having to grab a soldering iron or deploying code to your cube. Instead, all you need to do is 1) start the simulator, 2) choose an animation file, and 3) hit the play button.

This is what `qbular` looks like:

<< TODO: insert animated GIF>>

This program is written in [C++][cpp wiki], and it uses the [Qt framework][qt wiki] for the graphical interface and [OpenGL][opengl project] for the graphical simulation.

### Origin ###
My work on `qbular` began as a coursework for the class [Software Design Lab][csc class] (CSC-221), which I took at [City College][ccny website] during the Spring 2014 semester with [Prof. George Wolberg][wolberg website].

Development of `qbular` began in this [Bitbucket repo][bitbucket repo] on Feb 27 2014. Ninety commmits were clocked in on that repo before I ported the finished work to this GitHub repo. I chose not to retain the old commit history because the I used a sloppy file structure in that repo.

### Installation ###

```bash
# install dependencies
git clone https://github.com/ian-s-mcb/qbular
cd qbular
qmake
make
./ledcube
```
### Dependencies ####
* [Qt library][qt download] version 4.x or higher
* [OpenGL][opengl version] version 2.1 or higher


[instructables]: http://www.instructables.com/id/Led-Cube-8x8x8/
[cpp wiki]: http://en.wikipedia.org/wiki/C%2B%2B
[qt wiki]: http://en.wikipedia.org/wiki/Qt_%28software%29
[opengl project]: http://www.opengl.org/
[csc class]: http://www-cs.ccny.cuny.edu/~wolberg/cs221/index.html
[ccny website]: http://www.ccny.cuny.edu/
[wolberg website]: http://www-cs.engr.ccny.cuny.edu/~wolberg
[bitbucket repo]: https://bitbucket.org/ian_s_mcb/software-design-spring2014
[qt download]: https://qt-project.org/downloads
[opengl version]: http://www.opengl.org/documentation/implementations/
