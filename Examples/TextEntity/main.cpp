#include <Axilya/AXMain.h>
int main(int argc, char const *argv[])
{
	AXWindow::init(720, 480, AX_WINDOWED, "Text Example");
	Scene* scene = new Scene();
	AXWindow::setCurrentScene(scene);
	// AXGraphics::setBackground(0, 0, 0, 255);
	//we can add a font file with the size 18
	//remember that all files are prefixed with the runpath + data/
	int fontID = ResourceManager::getInstance()->addFont("Arial.ttf", 18);
	//lets make an Entity
	Entity* e = new Entity("text_entity", 0, 0, 0, 0); // The size of an Entity will be changed to fit the text you attach to it
	e->addCollider(new BoxCollider()); // Entities that display text can also have Colliders and Rigidbodies
	e->addRigidBody(true);
	//We give the renderer a AXStaticText with a name, a string to show and a fontID to use
	//we can use this name later, this works the same as Sprites
	e->getRenderer()->addText(new AXStaticText("example_text", "This is an object with gravity and a collider!", fontID));
	scene->addEntity(e);
	return AXWindow::run();
}