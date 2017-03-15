#include "headers/AXResourceManager.hpp"
AXResourceManager* AXResourceManager::instance = new AXResourceManager();

AXResourceManager* AXResourceManager::getInstance(){
    if(!instance){
        instance = new AXResourceManager();
    }
    return instance;
}

AXResourceManager::~AXResourceManager() {
    for(auto& t : textures){
        delete t;
        t = 0;
    }
    for(auto& f : fonts){
        delete f;
        f = 0;
    }
    textures.clear();
    textureMap.clear();
    fonts.clear();
    fontMap.clear();
}

int AXResourceManager::addTexture(const std::string& s){
    if(isTextureLoaded(s)){
        return textureMap.at(s)->getID();
    }
    int id = textures.size(); // get the new id
    AXTexture* tempTexture = new AXTexture(id, s); // create a new image
    //check if it loaded correctly
    if(tempTexture->isLoaded()){
        textures.push_back(tempTexture); // push it back
        textureMap.insert(std::pair<std::string, AXTexture*>(s, tempTexture));
        return id; // return the new id
    }
    std::cout << "AXTexture data failed to load." << std::endl;
    return -1;
}

int AXResourceManager::addFont(const std::string& s, int size){
    if(isFontLoaded(s)){
        return fontMap.at(s)->getID();
    }
    //attempt to load the file given
    int id = fonts.size(); // get the new id
    AXFont* tempFont = new AXFont(id, s, size); // create the AXTexture
    if(tempFont->isLoaded()){
        fonts.push_back(tempFont); // push it back
        fontMap.insert(std::pair<std::string, AXFont*>(s, tempFont));
        return id; // return the new id
    }else{
        delete tempFont;
    }
    std::cout << "AXFont data failed to load." << std::endl;
    return -1;
}

bool AXResourceManager::isTextureLoaded(const std::string &s) {
    if (textureMap.find(s) != textureMap.end()){
        return true;
    }
    return false;
}

bool AXResourceManager::isFontLoaded(const std::string &s) {
    if (fontMap.find(s) != fontMap.end()){
        return true;
    }
    return false;
}

AXTexture* AXResourceManager::getTexture(int i){
    if(i >= 0 && i < textures.size()){
        return textures[i];
    }else{
        std::cout << "No AXTexture with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXTexture* AXResourceManager::getTexture(const std::string &s) {
    if(isTextureLoaded(s)){
        return textureMap.at(s);
    }else{
        std::cout << "No AXTexture with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXFont* AXResourceManager::getFont(int i){
    if(i >= 0 && i < fonts.size()){
        return fonts[i];
    }else{
        std::cout << "No font with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXFont* AXResourceManager::getFont(const std::string &s) {
    if(isFontLoaded(s)){
        return fontMap.at(s);
    }else{
        std::cout << "No font with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

