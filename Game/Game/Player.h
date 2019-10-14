#ifndef _PLAYER
#define _PLAYER

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

    class Player
    {
    public:
        Player();

        void Move();

        void ShowBody();

        void ClearBody();

        void AddBody();

        bool CheckDeadBySelf();

        void SetDirection( MOVING_DIRECTION const direction )
        {
            if( true == _Changable( direction ) )
            {
                _direction = direction;
            }            
        }

    private:
        bool _Changable( MOVING_DIRECTION const direction );
        MOVING_DIRECTION _Opposite( MOVING_DIRECTION const direction ) const;
        
    private:
        std::vector<GameObject> _body;

        MOVING_DIRECTION _direction = DIRECTION_DOWN; // default right
    };
}


#endif
