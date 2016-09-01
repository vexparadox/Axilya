# closedFrameworks v0.6

A basic 2D game framework written in C++, runnable with Make. To see the initial production of this project see: https://github.com/vexparadox/closedFrameworks

This framework is going to be the base of the yet-to-be-named 2D engine I am making for my third year at University, this is the reason for going towards a Unity styled ECS.

Please see the WIKI on how to use this framework. It's not very scary once you get started.

See https://github.com/vexparadox/CFServer for the server module of closedFrameworks. This is still in early development.

## Coming Soon

- Good inter-Entity collisions
- Better Client-Server intergration (setting Entities to sync etc)
- Better physics on RigidBodies
- Handling random key presses in the Input class

## v0.6 Changelog

- Lots of back end stablising
- Changed the way scenes work to allow proper collisions
- Added new inter-entity-componet retrival (getComponent<>())
- Added new Component calls (onHover, onClick)
- Added mouse input into the Input class
- New ResourceManager class for safely and effciently reusing assets
- Added networked Client and Server intergration (using ENet)

## v0.495 Changelog

- New wiki updates!

- New example code!

- Entity Component System implemented (alpha stage)

- Framework has been re-worked to fit the new ECS 

- General error fixing

- Now uses Make not xCode

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