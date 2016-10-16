#ifndef CustomComponent_hpp
#define CustomComponent_hpp

#include "Component.hpp"
template <typename custom>
class CustomComponent : public Component{
	
public:
	virtual Component* clone(){
        return new custom(static_cast<custom const&>(*this));
	}
};

#endif