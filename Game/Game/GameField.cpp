#include "GameField.h"

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

    }
}