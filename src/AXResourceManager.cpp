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
    for(auto& c : chunks){
        delete c;
        c = 0;
    }
}

int AXResourceManager::addTexture(const std::string& path){
    if(isTextureLoaded(path)){
        return textureMap.at(path)->getID();
    }
    int id = textures.size(); // get the new id
    AXTexture* tempTexture = new AXTexture(id, path); // create a new image
    //check if it loaded correctly
    if(tempTexture->isLoaded()){
        textures.push_back(tempTexture); // push it back
        textureMap.insert(std::pair<std::string, AXTexture*>(path, tempTexture));
        return id; // return the new id
    }
    std::cout << "AXTexture data failed to load." << std::endl;
    return -1;
}

int AXResourceManager::addFont(const std::string& path, int size){
    if(isFontLoaded(path)){
        return fontMap.at(path)->getID();
    }
    //attempt to load the file given
    int id = fonts.size(); // get the new id
    AXFont* tempFont = new AXFont(id, path, size); // create the AXTexture
    if(tempFont->isLoaded()){
        fonts.push_back(tempFont); // push it back
        fontMap.insert(std::pair<std::string, AXFont*>(path, tempFont));
        return id; // return the new id
    }else{
        delete tempFont;
    }
    std::cout << "AXFont data failed to load." << std::endl;
    return -1;
}

int AXResourceManager::addAudioChunk(const std::string& path){
    if(isAudioChunkLoaded(path)){
        return audioMap.at(path)->getID();
    }
    //attempt to load the file given
    int id = chunks.size(); // get the new id
    AXAudioChunk* tempChunk = new AXAudioChunk(id, path); // create the AXTexture
    if(tempChunk->isLoaded()){
        chunks.push_back(tempChunk); // push it back
        audioMap.insert(std::pair<std::string, AXAudioChunk*>(path, tempChunk));
        return id; // return the new id
    }else{
        delete tempChunk;
    }
    std::cout << "AXAudioChunk data failed to load." << std::endl;
    return -1;

}

bool AXResourceManager::isTextureLoaded(const std::string &path) {
    if (textureMap.find(path) != textureMap.end()){
        return true;
    }
    return false;
}

bool AXResourceManager::isFontLoaded(const std::string &path) {
    if (fontMap.find(path) != fontMap.end()){
        return true;
    }
    return false;
}

bool AXResourceManager::isAudioChunkLoaded(const std::string &path){
    if (audioMap.find(path) != audioMap.end()){
        return true;
    }
    return false;
}

AXTexture* AXResourceManager::getTexture(int id){
    if(id >= 0 && id < textures.size()){
        return textures[id];
    }else{
        std::cout << "No AXTexture with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXTexture* AXResourceManager::getTexture(const std::string &path) {
    if(isTextureLoaded(path)){
        return textureMap.at(path);
    }else{
        std::cout << "No AXTexture with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXFont* AXResourceManager::getFont(int id){
    if(id >= 0 && id < fonts.size()){
        return fonts[id];
    }else{
        std::cout << "No AXFont with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXFont* AXResourceManager::getFont(const std::string &path) {
    if(isFontLoaded(path)){
        return fontMap.at(path);
    }else{
        std::cout << "No AXFont with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXAudioChunk* AXResourceManager::getAudioChunk(const std::string& path){
    if(isAudioChunkLoaded(path)){
        return audioMap.at(path);
    }else{
        std::cout << "No AXAudioChunk with this path. Has it been loaded?" << std::endl;
        return 0;
    }
}

AXAudioChunk* AXResourceManager::getAudioChunk(int id){
    if(id >= 0 && id < chunks.size()){
        return chunks[id];
    }else{
        std::cout << "No AXAudioChunk with this id. Has it been loaded?" << std::endl;
        return 0;
    }
}

