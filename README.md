![Alt text](examples/glfw/img/example.gif?raw=true "Example Motions")

## Overview

Trackball is a standalone C++ interactor for lightweight 3D programs.<br>
A TrackBall (aka ArcBall) orbits about an arbitrary world coordinate, although
this implementation also allows first-person pitch and yaw if desired.
A right-hand ZYX system is used, but can be easily ported to a left-hand system.

## Features
- Intuitive "lookAt" camera model with focal center point, eye and up vectors.
- Map three mouse buttons to either orbit, dolly (zoom), pan, first-person or roll.
- Map scroll to dolly (zoom) or roll.
- Adjust speed of all motions, such as with meta keys shift/ctrl/alt.
- Depends only on the GLM library.
- Cross-platform example with OpenGL and GLFW.

## Example

### Build

    $ mkdir -p build &&                                                  \
      cd build &&                                                        \
      cmake -DGLFW_INCLUDE_DIR:PATH=/usr/local/glfw-3.1.2/include        \
            -DGLFW_LIBRARY:FILEPATH=/usr/local/glfw-3.1.2/lib/libglfw.so \
            -DGLM_INCLUDE_DIR:PATH=/usr/local/glm-0.9.7.4/include        \
            -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON                             \
            .. &&                                                        \
      make

### Run

    $ ./examples/glfw/example

## References

* [GLM](http://glm.g-truc.net) (OpenGL) Graphics Library Mathematics
* [Object Mouse Trackball](https://www.opengl.org/wiki/Object_Mouse_Trackball) Concept

## License

trackball  Copyright (C) 2016  Remik Ziemlinski

This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it under the conditions of the GPLv3 license.
