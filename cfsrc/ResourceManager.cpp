#include "ResourceManager.hpp"

ResourceManager* ResourceManager::instance = new ResourceManager();

ResourceManager* ResourceManager::getInstance(){
    if(!instance){
        instance = new ResourceManager();
    }
    return instance;
}

int ResourceManager::addTexture(Graphics::Image* i){
    if(i){
        int id = textures.size(); // get the next id
        Texture* tempTex = new Texture(id, i); // create the new texture
        textures.push_back(tempTex); // push it back
        return id; //return the new id
    }
    std::cout << "Texture data was invalid." << std::endl;
    return -1;
}

int ResourceManager::addTexture(const std::string& s){
    Graphics::Image* tempImg = new Graphics::Image(); // create a new image
    //attempt to load the file given
    if(tempImg->loadImage(s)){
        int id = textures.size(); // get the new id
        Texture* tempTex = new Texture(id, tempImg); // create the texture
        textures.push_back(tempTex); // push it back
        return id; // return the new id
    }
    std::cout << "Texture data failed to load." << std::endl;
    return -1;
}

Texture* ResourceManager::getTexture(int i){
    if(i >= 0 && i < textures.size()){
        return textures[i];
    }else{
        std::cout << "No texture with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}