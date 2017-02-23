#ifndef AXText_hpp
#define AXText_hpp
#include "Component.hpp"
#include <stdio.h>
#include "ResourceManager.hpp"
class AXText : public Component{
protected:
	AXFont* font;
	ResourceManager* resourceManager = ResourceManager::getInstance();
public:
	virtual void setFont(AXFont* font) = 0;
	virtual void setFont(int id) = 0;
	virtual void draw(float x, float y) = 0;
};
#endif