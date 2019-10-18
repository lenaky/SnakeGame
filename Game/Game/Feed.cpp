#include <iostream>

#include "GameObject.h"
#include "Player.h"
#include "Feed.h"

namespace SnakeGame
{
    Feed::Feed( int interval, 
                int amount, 
                int field_max,
                Util::Range x_range, 
                Util::Range y_range ) : _interval( interval ), 
                                        _amount( amount ),
                                        _field_max( field_max ),
                                        _x_range( x_range ),
                                        _y_range( y_range )
    {
    }

    void Feed::StartCheck()
    {
        _begin = std::chrono::system_clock::now();
    }

    void Feed::TryFeed( Player const* player )
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

        if( _feeds.size() == _field_max )
        {
            return;
        }

        int count = _amount;

        while( count > 0 )
        {
            if( _feeds.size() == _field_max )
            {
                break;
            }

            int x_val = static_cast< int >( Util::GetRandom<std::int64_t>( _x_range.begin_, _x_range.end_ ) / 2 * 2 - 2 );
            if( 0 == x_val )
            {
                x_val = 2;
            }

            int y_val = static_cast< int >( Util::GetRandom<std::int64_t>( _y_range.begin_, _y_range.end_ ) - 1 );
            if( 0 == y_val )
            {
                y_val = 1;
            }

            if( player->IsBody( { x_val, y_val } ) )
            {
                continue;
            }

            if( _feeds.insert( GameObject( { x_val, y_val },
                                           static_cast<BlockColor>(Util::GetRandom<int>( BLOCK_COLOR_START + 1, BLOCK_COLOR_END )),
                                           std::string( "¡ß" ), 
                                           false ) ).second == true )
            {
                count--;
            }
        }

        _ShowFeeds();
    }

    void Feed::RemoveFeed( Util::Point const& point )
    {
        GameObject obj( point );
        auto& value = _feeds.find( obj );
        value->ClearObject();
        _feeds.erase( value );
    }

    void Feed::_ShowFeeds()
    {
        std::vector<GameObject> showed_array;

        for( auto& feed : _feeds )
        {
            if( false == feed.GetVisible() )
            {
                showed_array.push_back( feed );
            }
        }

        // set update.
        for( auto& feed : showed_array )
        {
            feed.SetVisible( true );
            feed.DrawObject();            
            _feeds.erase( feed );
            _feeds.insert( feed );
        }
    }
};