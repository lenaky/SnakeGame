#ifndef _GAME_FIELD_H_
#define _GAME_FIELD_H_

#include <vector>

#include "GameObject.h"

namespace SnakeGame
{
    class GameField
    {
    public:
        GameField() = delete;
        GameField( int width, int height );
        ~GameField();

        void ShowField();

        friend class Player;

    private:
        int _map_width = 0;
        int _map_height = 0;
        std::vector<GameObject> _field;
        
    };
}


#endif
