## Coming Soon
- Better Client-Server intergration (setting Entities to sync etc)
- Better physics on RigidBodies

## v0.7.2 Change Log

- Added fullscreen mode and display information
- Added mouse click callbacks to BaseCore
- Multiple Controller support!

## v0.7.1

- Moved to GPU sprite rendering
- Much more effcient drawing
- Added Offsets to scene rendering
- More key mappings

## v0.7

- Now has an onDestory in Component
- Moved to SDL, stb_image, glad
- Removed SOIL, GLEW, drawtext-noft, GLFW, Enet
- Temporarily removed networking

## v0.6.9 
 
- Added special GameMaster entity
- Added proper shutdown procedure
- Fixed Start calls on Components

## v0.6.8.1

- Fixed some things

## v0.6.8 

- Entity Draw Modes: Rectangles and Ellipses
- Entity Deletion is back and working!
- More methods for RigidBodies
- onWorldCollision for components - called when collides with edges
- Set whether your RigidBodies are screenBound or not

## v0.6.7

- Added PrefabManager!
- Load and save your Entities

## v0.6.6

- Instantiate new Entities from the Scene!
- Clone Entities and Components!
- isActive checks on Colliders
- New way of creating CustomComponents

## v0.6.5

- Entity-Entity collisions with BoxCollider!

## v0.6.4

- Seperate engine and framework example Cores

## v0.6.3

- SceneFiles - Load your Scenes without hard coding! - `NFI`
- SceneFiles currently only allow for basic Entity creation.

## v0.6.2
- Optimised Input, see the RigidBodyMove + TransformMove Class
- New Sprites: Static and Animated - allows for easy animations
- Updates to the ResourceManager
- Added `activeScene` to Runner
- New wiki entries!
- New World class: Allows for CSV worlds to be loaded - `NFI`
- New World types: Static and Tiled - `NFI`


## v0.6
- Lots of back end stablising
- Changed the way scenes work to allow proper collisions
- Added new inter-entity-componet retrival (getComponent<>())
- Added new Component calls (onHover, onClick)
- Added mouse input into the Input class
- New ResourceManager class for safely and effciently reusing assets
- Added networked Client and Server intergration (using ENet)

## v0.495

- New wiki updates!
- New example code!
- Entity Component System implemented (alpha stage)
- Framework has been re-worked to fit the new ECS 
- General error fixing
- Now uses Make not xCode

## v0.4
- Push pop Matrixes
- Matrix translation
- Fixes to the timer
- New Wiki pages!
- Ellipse rendering and collision
- Colour fills, you can now easily colour shapes
- Increased perforamce other collisions

## v0.3
- Optimised shape drawing
- Added text rendering! Only uses glyphmaps at the moment
- Fixed lines being drawn around images, they weren't being clamped properly
- Added exitCalled() call back in the Core
- Commented a lot of the collision and Math code
- mousePressed and keyPressed should now be accurate and take account to multiple presses
- Added a Timer class
- Cleaned up Vector code
- Added GLEW for text rendering

## v0.2
- Finalised the CSV Reader
- You can normalise 3D Vectors
- Triangles are now labelled properly
