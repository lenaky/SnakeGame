#include <iostream>

#include "Player.h"

namespace SnakeGame
{
    Player::Player()
    {
        _body.push_back( { { 4,4 }, BLOCK_COLOR_RED, std::string( "��" ), true } );
        _body.push_back( { { 4,3 }, BLOCK_COLOR_RED, std::string( "��" ), true } );
        _body.push_back( { { 4,2 }, BLOCK_COLOR_RED, std::string( "��" ), true } );
    }

    void Player::Move()
    {
        int index = 0;

        Util::Point prev_point( 0, 0 );

        for( auto& body : _body )
        {
            if( 0 == index )
            {
                prev_point = body.GetPosition();

                switch( _direction )
                {
                case DIRECTION_DOWN:
                    body.SetPosition( { prev_point.x, prev_point.y + 1 } );
                    break;
                case DIRECTION_LEFT:
                    body.SetPosition( { prev_point.x - 2, prev_point.y } );
                    break;
                case DIRECTION_RIGHT:
                    body.SetPosition( { prev_point.x + 2, prev_point.y } );
                    break;
                case DIRECTION_UP:
                    body.SetPosition( { prev_point.x, prev_point.y - 1 } );
                    break;
                }
            }
            else
            {
                auto temp_point = body.GetPosition();
                body.SetPosition( prev_point );
                body.SetVisible( true );
                prev_point = temp_point;
            }

            index++;
        }
    }

    void Player::ShowBody()
    {
        for( auto& body : _body )
        {
            body.DrawObject();
        }
    }

    void Player::ClearBody()
    {
        for( auto& body : _body )
        {
            body.ClearObject();
        }
    }

    void Player::AddBody()
    {
        _body.push_back( { { 0,0 }, BLOCK_COLOR_RED, std::string( "��" ), false } );
    }

    bool Player::CheckDeadBySelf()
    {

    }

    bool Player::_Changable( MOVING_DIRECTION const direction )
    {
        if( _Opposite( _direction ) == direction )
        {
            return false;
        }

        return true;
    }

    MOVING_DIRECTION Player::_Opposite( MOVING_DIRECTION const direction ) const
    {
        switch( direction )
        {
        case DIRECTION_DOWN:
            return DIRECTION_UP;
        case DIRECTION_UP:
            return DIRECTION_DOWN;
        case DIRECTION_LEFT:
            return DIRECTION_RIGHT;
        case DIRECTION_RIGHT:
            return DIRECTION_LEFT;
        }

        return DIRECTION_NONE;
    }
};