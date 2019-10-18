#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "GameObject.h"

namespace SnakeGame
{
    enum _MOVING_DIRECTION
    {
        DIRECTION_NONE = -1,
        DIRECTION_UP = 0,
        DIRECTION_LEFT = 1,
        DIRECTION_DOWN = 2,
        DIRECTION_RIGHT = 3
    };

    using MOVING_DIRECTION = enum _MOVING_DIRECTION;

    class GameField;

    class Player
    {
    public:
        Player();

        void Move();

        void ShowBody();

        void ClearBody();

        void AddBody();

        bool ConsumeFeed( GameField* field );

        bool CheckDeadBySelf();

        bool CheckDeadByCollision( GameField const* field );

        void SetDirection( MOVING_DIRECTION const direction )
        {
            if( true == _Changable( direction ) )
            {
                _direction = direction;
                _direction_buffer = direction;
            }            
        }

        bool IsBody( Util::Point const& point ) const;

    private:
        bool _Changable( MOVING_DIRECTION const direction );
        MOVING_DIRECTION _Opposite( MOVING_DIRECTION const direction ) const;
        
    private:
        std::vector<GameObject> _body;

        MOVING_DIRECTION _direction = DIRECTION_DOWN; // default right
        MOVING_DIRECTION _direction_buffer = DIRECTION_NONE;
    };
}


#endif
