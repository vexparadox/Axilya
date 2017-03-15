#ifndef AXResource_hpp
#define AXResource_hpp

class AXResource{
protected:
	int id;
	AXResource(int id) : id(id){};
public:
	int getID(){ return id; };
};
#endif