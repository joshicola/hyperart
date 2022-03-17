# HyperArt
HyperArt is a program to view and create repeating hyperbolic patterns using algorithm developed by [Dr Douglas Dunham](http://hyperart.sourceforge.net/www.d.umn.edu/~ddunham/). The patterns are similar to those created by the venerable Dutch artist M. C. Escher. While this might not be of immediate practical use, it is very interesting from mathematical and artistic viewpoints.

This project is a port of Ajit Datar's original [HyperArt](http://hyperart.sourceforge.net/) project with Dr. Douglas Duhnam in 2005 to Qt 5.12. As the original code was written for Qt 3.3 it is no longer supported by modern operating systems. His [Master's Thesis](docs/Generating_Hyperbolic_Patterns_for_Regular_and_Non-Regular_P-Gons.pdf) is contained within. I am grateful for his work and continued friendship.

## Resources
This work is based off of [Dr. Dunhams original paper](http://www.d.umn.edu/~ddunham/isis4/index.html). You can see more of his work on his [University of Minnesota Duluth webpage](http://www.d.umn.edu/~ddunham/).

The purpose of this repository is to have this code available for those wanting to extend this in other frameworks.

## Building
Install Qt 5 and QMake on your operating system.

Debian operating system instructions:

`sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools`

Then, in the `src` directory:

`qmake -o Makefile hyperart.pro`

And finally,

`make`

## NOTES:
- This work was motivated by getting [Dr. Joseph Gallian](https://www.d.umn.edu/~jgallian/) a replacement to a Flash animation that became unsupported. I am grateful for his mentorship and friendship.
- Some features have been disabled from the original (e.g. printing) while others have yet to be implemented (e.g. editing).
- Collaborations, Forks, clones, and outright stealing are welcomed. Please keep the header in each file acknowledging Ajit Datar's and Dr. Dunham's contributions.