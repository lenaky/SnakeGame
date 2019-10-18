#include <iostream>

#include "GameObject.h"

namespace SnakeGame
{
    GameObject::GameObject( Util::Point point ) : _point( point )
    {

    }

    GameObject::GameObject( Util::Point point, 
                            BlockColor color, 
                            std::string symbol,
                            bool show ) : _point( point ), _color( color ), _symbol( symbol ), _show( show )
    {

    }

    void GameObject::DrawObject() const
    {
        if( false == _show )
            return;

        int block_color = _color + BLOCK_COLOR_BLACK * 16;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), block_color );

        Util::GotoPosition( _point );
        std::cout << _symbol.c_str() << std::endl;
    }

    void GameObject::ClearObject() const
    {
        if( false == _show )
            return;

        Util::GotoPosition( _point );
        std::cout << " " << std::endl;
    }

    void GameObject::SetPosition( Util::Point const& point )
    {
        _point.x = point.x;
        _point.y = point.y;
    }

    void GameObject::SetVisible( bool show )
    {
        _show = show;
    }
};