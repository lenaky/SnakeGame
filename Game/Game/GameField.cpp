#include "GameField.h"
#include "Feed.h"

namespace SnakeGame
{
    GameField::GameField( int width, int height ) : _map_width( width ), 
                                                    _map_height( height )
    {
        for( int y = 0; y < height; y++ )
        {
            for( int x = 0; x < width; x++ )
            {
                if( y == 0 || y == height - 1 )
                {
                    _field.push_back( { { x * 2, y }, BLOCK_COLOR_WHITE, std::string( "бс" ), true } );
                }
                else
                {
                    if( x == 0 || x == width - 1 )
                    {
                        _field.push_back( { { x * 2, y }, BLOCK_COLOR_WHITE, std::string( "бс" ), true } );
                    }
                }                
            }
        }

        _feed = new Feed( 2000, 2, 10, { 2, width * 2 }, { 1, height - 1 } );
    }

    void GameField::ShowField()
    {
        for( auto& field : _field )
        {
            field.DrawObject();
        }
    }

    GameField::~GameField()
    {
        if( nullptr != _feed )
        {
            delete _feed;
            _feed = nullptr;
        }
    }
}