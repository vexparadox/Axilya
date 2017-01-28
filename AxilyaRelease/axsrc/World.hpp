#ifndef World_hpp
#define World_hpp
class Scene;
class World{
    Scene* scene = 0;
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    void setScene(Scene* scene);
    Scene* getScene();
};

#endif
