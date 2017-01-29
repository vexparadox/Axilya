#ifndef CustomTileComponent_hpp
#define CustomTileComponent_hpp
#include "TileComponent.hpp"

template <typename custom>
class CustomTileComponent : public TileComponent{
public:
	virtual TileComponent* clone(){
        return new custom(static_cast<custom const&>(*this));
	}
};

#endif