# Qbular#
`qbular` is a simulation tool for a LED Cube and LED Cube animation design. An [LED Cube][instructables] is a common hobbyist electronic device. Their purpose is to display animation, or simple graphics, in an immersive, 3D way. Another way to describe them is "a poor man's hologram." They look something like this:

![Photo of LED cube](http://cdn.instructables.com/FUX/O1RW/GICYBAOS/FUXO1RWGICYBAOS.MEDIUM.jpg)

This tool makes it possible to design cube graphics without having to grab a soldering iron or deploying code to your cube. Instead, all you need to do is 1) start the simulator, 2) choose an animation file, and 3) hit the play button.

This is what `qbular` looks like (for more screenshots, check out [this gallery][screenshot gallery]):

![Photo of LED cube](http://i.imgur.com/lHvbi8t.png)

This program is written in [C++][cpp wiki], and it uses the [Qt framework][qt wiki] for the graphical interface and [OpenGL][opengl project] for the graphical simulation.

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

### Origin ###
My work on `qbular` began as a individual coursework for the class [Software Design Lab][csc class] (CSC-221), which I took at [City College][ccny website] during the Spring 2014 semester with [Prof. George Wolberg][wolberg website]. Development of `qbular` began on Feb 27 2014 in this [Bitbucket repo][bitbucket repo], which was converted to Git on Jun 29 2015.

[instructables]: http://www.instructables.com/id/Led-Cube-8x8x8/
[screenshot gallery]: http://imgur.com/a/0aGPX
[cpp wiki]: http://en.wikipedia.org/wiki/C%2B%2B
[qt wiki]: http://en.wikipedia.org/wiki/Qt_%28software%29
[opengl project]: http://www.opengl.org/
[csc class]: http://www-cs.ccny.cuny.edu/~wolberg/cs221/index.html
[ccny website]: http://www.ccny.cuny.edu/
[wolberg website]: http://www-cs.engr.ccny.cuny.edu/~wolberg
[bitbucket repo]: https://bitbucket.org/ian_s_mcb/software-design-spring2014
[qt download]: http://www.qt.io/download/
[opengl version]: http://www.opengl.org/documentation/implementations/
