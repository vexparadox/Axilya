# closedFrameworks v0.4 MAKE VERSION

A basic 2D game framework written in C++, runnable with Make. To see the initial production of this project see: `https://github.com/vexparadox/closedFrameworks`

Note that the wiki is currently out of date for this Make version, run using make NOT xCode.

Core.cpp and Core.hpp is the user entry point into the framework. The methods contained are explained in the wiki.

## v0.5 COMING SOON

- Entity Component System (alpha stage)

- General error fixing

## v0.4 Changelog

- Push pop Matrixes

- Matrix translation

- Fixes to the timer

- New Wiki pages!

- Ellipse rendering and collision

- Colour fills, you can now easily colour shapes

- Increased perforamce other collisions

## v0.3 Changelog

- Optimised shape drawing
 
- Added text rendering! Only uses glyphmaps at the moment

- Fixed lines being drawn around images, they weren't being clamped properly

- Added exitCalled() call back in the Core

- Commented a lot of the collision and Math code

- mousePressed and keyPressed should now be accurate and take account to multiple presses

- Added a Timer class

- Cleaned up Vector code

- Added GLEW for text rendering

## v0.2 Changelog

- Finalised the CSV Reader

- You can normalise 3D Vectors

- Triangles are now labelled properly