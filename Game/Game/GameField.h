#ifndef _GAME_FIELD
#define _GAME_FIELD

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

    private:
        int _map_width = 0;
        int _map_height = 0;
        std::vector<GameObject> _field;
        
    };
}


#endif
