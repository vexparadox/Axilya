#include "headers/ResourceManager.hpp"
#include "headers/AXFont.hpp"

ResourceManager* ResourceManager::instance = new ResourceManager();

ResourceManager* ResourceManager::getInstance(){
    if(!instance){
        instance = new ResourceManager();
    }
    return instance;
}

ResourceManager::~ResourceManager() {
    for(auto& t : textures){
        delete t;
        t = 0;
    }
    textures.clear();
    textureMap.clear();
}

int ResourceManager::addTexture(const std::string& s){
    if(isTextureLoaded(s)){
        return textureMap.at(s)->getID();
    }
    Graphics::Image* tempImg = new Graphics::Image(); // create a new image
    //attempt to load the file given
    if(tempImg->loadImage(s)){
        int id = textures.size(); // get the new id
        Texture* tempTex = new Texture(id, tempImg); // create the texture
        textures.push_back(tempTex); // push it back
        textureMap.insert(std::pair<std::string, Texture*>(s, tempTex));
        return id; // return the new id
    }
    std::cout << "Texture data failed to load." << std::endl;
    return -1;
}

int ResourceManager::addFont(const std::string& s){
    if(isFontLoaded(s)){
        return fontMap.at(s)->getID();
    }
    //attempt to load the file given
    int id = fonts.size(); // get the new id
    AXFont* tempFont = new AXFont(id); // create the texture
    if(tempFont->loadFont(s)){
        fonts.push_back(tempFont); // push it back
        fontMap.insert(std::pair<std::string, AXFont*>(s, tempFont));
        return id; // return the new id
    }else{
        delete tempFont;
    }
    std::cout << "Texture data failed to load." << std::endl;
    return -1;
}

bool ResourceManager::isTextureLoaded(const std::string &s) {
    if (textureMap.find(s) != textureMap.end()){
        return true;
    }
    return false;
}

bool ResourceManager::isFontLoaded(const std::string &s) {
    if (fontMap.find(s) != fontMap.end()){
        return true;
    }
    return false;
}

Texture* ResourceManager::getTexture(int i){
    if(i >= 0 && i < textures.size()){
        return textures[i];
    }else{
        std::cout << "No texture with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

Texture* ResourceManager::getTexture(const std::string &s) {
    if(isTextureLoaded(s)){
        return textureMap.at(s);
    }else{
        std::cout << "No texture with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXFont* ResourceManager::getFont(int i){
    if(i >= 0 && i < fonts.size()){
        return fonts[i];
    }else{
        std::cout << "No font with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXFont* ResourceManager::getFont(const std::string &s) {
    if(isFontLoaded(s)){
        return fontMap.at(s);
    }else{
        std::cout << "No font with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

