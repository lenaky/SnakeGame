#include <iostream>

#include "GameField.h"
#include "Feed.h"
#include "Player.h"

namespace SnakeGame
{
    Player::Player()
    {
        _body.push_back( { { 4,4 }, BLOCK_COLOR_RED, std::string( "¡Ü" ), true } );
        _body.push_back( { { 4,3 }, BLOCK_COLOR_RED, std::string( "¡á" ), true } );
        _body.push_back( { { 4,2 }, BLOCK_COLOR_RED, std::string( "¡á" ), true } );
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

        _direction_buffer = DIRECTION_NONE; // clear buffer
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
        if( _body.size() > 0 )
        {
            _body[ _body.size() - 1 ].ClearObject();
        }
    }

    void Player::AddBody()
    {
        _body.push_back( { { 0,0 }, BLOCK_COLOR_RED, std::string( "¡á" ), false } );
    }

    bool Player::ConsumeFeed( GameField* field )
    {
        bool consume = false;
        if( _body.size() > 0 )
        {
            auto feed = field->GetFeed();
            auto& head = _body[ 0 ];
            auto const& point = head.GetPosition();

            auto collison_feed = field->GetFeed()->GetFeeds().find( head );
            if( collison_feed != field->GetFeed()->GetFeeds().end() ) // Ãæµ¹
            {
                field->GetFeed()->RemoveFeed( point );
                consume = true;
            }
        }

        return consume;
    }

    bool Player::CheckDeadBySelf()
    {
        if( _body.size() > 0 )
        {
            auto& head = _body[ 0 ];
            int index = 0;
            for( auto const& body : _body )
            {
                if( 0 == index++ )
                    continue;

                if( body.GetPosition() == head.GetPosition() )
                {
                    return true; // dead
                }
            }
        }

        return false;
    }

    bool Player::CheckDeadByCollision( GameField const* field )
    {
        if( _body.size() > 0 )
        {
            auto& head = _body[ 0 ];
            for( auto const& field : field->_field )
            {
                if( head.GetPosition() == field.GetPosition() )
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool Player::IsBody( Util::Point const& point ) const
    {
        for( auto const& body : _body )
        {
            if( body.GetPosition() == point )
            {
                return true;
            }
        }

        return false;
    }

    bool Player::_Changable( MOVING_DIRECTION const direction )
    {
        if( _direction_buffer != DIRECTION_NONE )
        {
            return false;
        }

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