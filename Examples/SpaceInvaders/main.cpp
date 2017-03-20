//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//  Audio from http://www.wavsource.com and http://www.freesoundeffects.com
//
#include <Axilya/AXMain.h>
#include "PlayerController.hpp"
#include "Bullet.hpp"
#include "Invader.hpp"

void SpawnText(AXScene* scene){
    // create a new entity
    // you can give 0 width and height because the text will bake it
    AXEntity* text = new AXEntity("text", 20, AXWindow::getHeight()-150, 0, 0);
    // load the font in and save the ID
    int fontID = AXResourceManager::getInstance()->addFont("Arial.ttf", 20);
    // create a new AXStaticText with the font we loaded
    AXStaticText* st = new AXStaticText("Score: 0", fontID);
    // set the colour to greyish
    st->setColour(240, 240, 240, 255);
    // get the renderer and add the text, give it a name "score" for next time
    text->getRenderer()->addText(st, "score");
    // add the new text entity to the scene
    scene->addEntity(text);
}

void SpawnPlayer(AXScene* scene){
    AXEntity* player = new AXEntity("player", 0, AXWindow::getHeight()-64, 64, 64);
    // load the audio file
    int audioID = AXResourceManager::getInstance()->addAudioChunk("fire.wav");
    player->addComponent(new PlayerController());
    //create a sprite
    AXStaticSprite* ss = new AXStaticSprite("player_1.jpg");
    player->getRenderer()->addSprite(ss, "player_static");
    // add the audio loaded with the name "fire"
    // we can use this name to play the sound
    player->getAudioPlayer()->addAudioChunk(audioID, "fire");
    scene->addEntity(player);

    AXEntity* bullet = new AXEntity("bullet", 0, 0, 32, 64);
    bullet->addCollider(new AXBoxCollider());
    bullet->addComponent(new Bullet());
    ss = new AXStaticSprite("bullet.jpg");
    //add a sprite with a name
    bullet->getRenderer()->addSprite(ss, "bullet");
    AXPrefabManager::getInstance()->addPrefab(bullet);
}

void SpawnInvaders(AXScene* scene){
    AXPrefabManager* prefabManager = AXPrefabManager::getInstance();
    // let's load in a death sound
    int audioID = AXResourceManager::getInstance()->addAudioChunk("death.wav");
    //A prefab of the invaders
    AXEntity* enemy = new AXEntity("enemy", 0, 0, 64, 64);
    // add a collider
    enemy->addCollider(new AXBoxCollider());
    // add the Invader component
    enemy->addComponent(new Invader());
    //add the death sound with the name "death"
    enemy->getAudioPlayer()->addAudioChunk(audioID, "death");
    //create a new animated sprite
    AXAnimatedSprite* as = new AXAnimatedSprite(30);
    as->addTexture("enemy_1.jpg");
    as->addTexture("enemy_2.jpg");
    //add the sprite to the enemy with a given name
    //this will also set it to the current one
    enemy->getRenderer()->addSprite(as, "enemy_sprite");

    //make the enemy a prefab so we can make copies easily
    prefabManager->addPrefab(enemy);

    int cols = (AXWindow::getWidth()/64);
    int rows = 5;
    //make a grid of enemies
    for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
            //spawn an entity with the name "enemy_col_row"
            //use the row and col numbers to determine it's position
            scene->instantiate(
                "enemy_"+std::to_string(i)+"_"+std::to_string(j), 
                prefabManager->getPrefab("enemy"),
                new AXTransform((i*64)+10, j*64, 64, 64));
        }
    }
}

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(720, 480, "Space Invaders", AX_DEFAULT)){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    //create the scene
    AXScene* scene = new AXScene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(16, 16, 16, 255);
    //spawn the invaders
    SpawnInvaders(scene);
    //spawn the player
    SpawnPlayer(scene);
    //spawn the Text Entity
    SpawnText(scene);
    return AXWindow::run();
}