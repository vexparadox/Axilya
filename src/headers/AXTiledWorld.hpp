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
 * This is a type of AXWorld that exists as a list of Tiles.
 */
#ifndef AXTiledWorld_hpp
#define AXTiledWorld_hpp

#include "AXWorld.hpp"
#include "AXTile.hpp"
#include <unordered_map>

class AXTiledWorld : public AXWorld {
    //tile types loaded into the world
    std::unordered_map<char, AXTile*> tileTypes;
    std::vector<AXTile*> worldMatrix;
    bool isLoaded;
    int width, height;
public:
    ~AXTiledWorld();
    AXTiledWorld(int width, int height);
    //allows the user to add a new tile type
    void addTileType(char key, AXTile* tile);
    //returns a tile type based on a char
    AXTile* getTileType(char key);
    //load a world in the data path, CSV
    void loadWorld(const std::string& path, int tileSize);
    virtual void draw();
    virtual void update();
};


#endif //Axilya_TILEDWORLD_H
