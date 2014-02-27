C++ Version of the prototype
============================

This is the first version of the prototype built with C++ and
particularly using the new C++11 standard.

Requirements
============

* CMake
* Clang 3.2+/gcc 4.7.3
* OpenGL and Freeglut3 ("apt-get install freeglut3-dev mesa-common-dev" should be enough)
* Boost (preferably 1.53) (no longer necesary, but it's always nice to have boost at hand)
* GLM (apt-get install libglm-dev)
* For using SFML: libxrandr-dev, libfreetype6-dev, libglew-dev, libjpeg-dev, libopenal-dev, libsndfile-dev


How to build
============

* Get the source code. 
* Create a folder where you want to build
* Inside that folder run "cmake <path to root of project>". 
* Run it again.
* Run "make"
* Inside the "src" folder will be the executable.
* If you want to make a debug build, instead of plain cmake use "cmake -DCMAKE_BUILD_TYPE=Debug <path>". The default is a "Release" build. 


Overview
========

The idea is to build a component driven system. 

A component is any piece of logic that can be thought as a "feature", "capability" or even "property"
of an actor in the system

An entity is a particular grouping of components that have some logic meaning. For example an entity
for the player may have some ModelComponent, SpatialLocationComponent, InputComponent, etc.

Entities and components cant be created freely, they must use their respective factory functions
(::Create) so they are registered in the managers immediately for future garbage collection. I'm
still unsure how to handle further pointer bookkeeping between components/entities.

After you create the entities with the desired components to start your simulation, calling 
engine::run will enter into a common loop of updates for each component that needs to be updated. The
engine will call managers for each type of component and other special objects, like the event handler
so it can dispatch all event notifications.


TO DO
=====

* Add queues to the eventManager to handle events.
* Create some basic pre-made model components (like the cube being a cube, a sphere, etc).
* Create a generic way to save-load entities so we can save maps.
* Improve the way the keys are read. Probably create a system a la Xna for storing key presses and releases.
* 

