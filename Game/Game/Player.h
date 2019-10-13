#ifndef _PLAYER
#define _PLAYER

#include "GameObject.h"

namespace SnakeGame
{
    enum _MOVING_DIRECTION
    {
        DIRECTION_UP = 0,
        DIRECTION_LEFT = 1,
        DIRECTION_DOWN = 2,
        DIRECTION_RIGHT = 3
    };

    using MOVING_DIRECTION = enum _MOVING_DIRECTION;

    class Player
    {
    public:
        Player() = default;
        Player( int default_length );

        void Move();

        void ShowBody();

        void AddBody();

    private:
        int _default_body_length = 0;
        std::vector<GameObject> _body;

        MOVING_DIRECTION _direction = DIRECTION_DOWN; // default right
    };
}


#endif
