#include <iostream>

#include "GameObject.h"
#include "Feed.h"

namespace SnakeGame
{
    Feed::Feed( int interval, 
                int amount, 
                Util::Range x_range, 
                Util::Range y_range ) : _interval( interval ), 
                                        _amount( amount ),
                                        _x_range( x_range ),
                                        _y_range( y_range )
    {
    }

    void Feed::StartCheck()
    {
        _begin = std::chrono::system_clock::now();
    }

    void Feed::TryFeed()
    {
        auto current = std::chrono::system_clock::now();
        if( _interval < std::chrono::duration_cast< std::chrono::milliseconds >( current - _begin ).count() )
        {
            _begin = current;
        }
        else
        {
            return;
        }

        int count = _amount;

        while( count > 0 )
        {
            if( _feeds.insert( GameObject( { Util::GetRandom<int>( 10, 100 ), Util::GetRandom<int>( 10, 100 ) }, 
                                           BLOCK_COLOR_BLUE, 
                                           std::string( "¡Ú" ), 
                                           true ) ).second == true )
            {
                count--;
            }                
        }
    }

    void Feed::RemoveFeed( Util::Point const& point )
    {

    }
};