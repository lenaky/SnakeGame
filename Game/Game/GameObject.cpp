#include <iostream>

#include "GameObject.h"

namespace SnakeGame
{
    GameObject::GameObject( Util::Point point, 
                            BlockColor color, 
                            std::string symbol ) : _point( point ), _color( color ), _symbol( symbol )
    {

    }

    void GameObject::DrawObject()
    {
        Util::GotoPosition( _point );
        std::cout << _symbol.c_str() << std::endl;
    }

    void GameObject::ClearObject()
    {
        Util::GotoPosition( _point );
        std::cout << " " << std::endl;
    }

    void GameObject::SetPosition( Util::Point const& point )
    {
        _point.x = point.x;
        _point.y = point.y;
    }
};