#include <iostream>

#include "Player.h"

namespace SnakeGame
{
    Player::Player( int default_length ) : _default_body_length( default_length )
    {
        _body.push_back( { { 4,4 }, BLOCK_COLOR_RED, std::string( "бс" ) } );
        _body.push_back( { { 4,3 }, BLOCK_COLOR_RED, std::string( "бс" ) } );
        _body.push_back( { { 4,2 }, BLOCK_COLOR_RED, std::string( "б▄" ) } );
    }

    void Player::Move()
    {
        for( auto& body : _body )
        {
            switch( _direction )
            {
                case DIRECTION_DOWN:
                {
                    auto point = body.GetPosition();
                    body.SetPosition( { point.x, point.y + 1 } );
                } break;
                case DIRECTION_LEFT:
                {
                    auto point = body.GetPosition();
                    body.SetPosition( { point.x - 2, point.y } );

                } break;
                case DIRECTION_RIGHT:
                {
                    auto point = body.GetPosition();
                    body.SetPosition( { point.x + 2, point.y } );

                } break;
                case DIRECTION_UP:
                {
                    auto point = body.GetPosition();
                    body.SetPosition( { point.x, point.y - 1 } );

                } break;
            }
        }
    }

    void Player::ShowBody()
    {
        for( auto& body : _body )
        {
            body.DrawObject();
        }
    }

    void Player::AddBody()
    {

    }
};