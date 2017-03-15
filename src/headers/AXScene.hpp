/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This is used as a collection of Entities and a World, AXWindow will call update and draw on this object.
 */
#ifndef Scene_hpp
#define Scene_hpp
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "World.hpp"
#include "AXMath.hpp"

class AXEntity;
class AXTransform;
class AXScene{
    //the vector of entities
    std::vector<AXEntity*> entities;
    World* world;
    AXEntity* gameMaster;
    AXVector2D renderOffset;
    std::unordered_map<std::string, AXEntity*> entityMap;
public:
    /*!
    * The constructor of a AXScene
    */
    AXScene();
    /*!
    * The deconstructor of a AXScene
    *
    * This will release all Entities in the scene
    */
    ~AXScene();
    /*!
    * A method to start all AXEntity's and therefore AXComponent's in the AXScene
    *
    * This method is called once by the AXWindow
    */
    void start();
    /*!
    * A method to update all AXEntity's and therefore AXComponent's in the AXScene
    *
    * This method is called every frame by the AXWindow
    */
    void update();
    
    /*!
    * A method to draw all AXEntity's and therefore AXRenderer's in the AXScene
    *
    * This method is called every frame by the AXWindow
    */
    void draw();
    /*!
    * A method to get the AXRenderer offset
    *
    * @return the vector of how the AXRenderer is being offset
    */
    AXVector2D& getRenderOffset();
    /*!
    * A method to add to the AXRenderer offset
    *
    * @param x how much to offset in the x axis
    * @param y how much to offset in the y axis
    */
    void offsetRenderer(float x, float y);
    /*!
    * A method to add to the AXRenderer offset
    *
    * @param v how much to offset the AXRenderer (x, y)
    */
    void offsetRenderer(AXVector2D& v);
    /*!
    * A method to set the AXRenderer offset
    *
    * @param x the offset to set in the x axis
    * @param y the offset to set in the y axis
    */
    void setRenderOffset(float x, float y);
    /*!
    * A method to set the AXRenderer offset
    *
    * @param v a vector to set the offset to (x, y)
    */
    void setRenderOffset(AXVector2D& v);
    /*!
    * A method to add an AXEntity to this AXScene
    *
    * @param e the AXEntity to add
    * @return if the AXEntity was added successfully
    */
    bool addEntity(AXEntity* e);
    /*!
    * A method to set the GameMaster in this AXScene
    *
    * The GameMaster is a special AXEntity that isn't drawn and is only updated, it's used to control game states.
    * @param e the AXEntity to set the GameMaster
    * @return if the GameMaster was set successfully
    */
    bool setGameMaster(AXEntity* e);
    /*!
    * A method to get the GameMaster in this AXScene
    *
    * The GameMaster is a special AXEntity that isn't drawn and is only updated, it's used to control game states.
    * @return the GameMaster
    */
    AXEntity* getGameMaster();
    /*!
    * A method to set the World of this AXScene
    *
    * @param w the world to set
    */
    void setWorld(World* w);
    /*!
    * A method to remove a specific AXEntity
    *
    * It's better to use the destroy() method on an AXEntity
    * @param e the entity to destroy
    */
    void removeEntity(AXEntity* e);
    /*!
    * A method to instantiate a new AXEntity in this AXScene
    *
    * Instatniated AXEntity's will be put straight into the AXScene
    * @param name the name of this new AXEntity
    * @param e the AXEntity this new one will copy
    * @param t a new AXTransform for this new AXEntity to be given
    * @return a pointer to the new AXEntity
    */
    AXEntity* instantiate(const std::string& name, AXEntity* e, AXTransform* t);
    /*!
    * A method to instantiate a new AXEntity in this AXScene
    *
    * Instatniated AXEntity's will be put straight into the AXScene
    * @param name the name of this new AXEntity
    * @param e the AXEntity this new one will copy
    * @return a pointer to the new AXEntity
    *
    * Without a seperate AXTransform this new AXEntity will get a copy of @param e's
    */
    AXEntity* instantiate(const std::string& name, AXEntity* e);
    /*!
    * A method to find an AXEntity in this scene
    *
    * @param name the name of the AXEntity to find
    * @return a pointer to the found AXEntity or nullptr
    */
    AXEntity* findEntity(const std::string& name);
    /*!
    * A method to check collisions of an AXEntity against all over in this AXScene
    *
    * @param e the AXEntity to check
    * @param proposedMovement the vector of movement being attempted by @param e
    * @param colls an array of collision directions that will be filled by the Collider's
    */
    void collideCheck(AXEntity* e, AXVector2D& proposedMovement, unsigned char* colls);
    /*!
    * Returns the number of Entities in this AXScene
    * @return number of Entities in the AXScene vector
    */
    std::vector<AXEntity*>& getEntities();
    int numEntities();
};

#endif
