#ifndef _GAME_FIELD_H_
#define _GAME_FIELD_H_

#include <vector>

#include "GameObject.h"

namespace SnakeGame
{
    class Feed;

    class GameField
    {
    public:
        GameField() = delete;
        GameField( int width, int height );
        ~GameField();

        void ShowField();

        friend class Player;

        Feed* GetFeed() { return _feed; }

    private:
        int _map_width = 0;
        int _map_height = 0;
        std::vector<GameObject> _field;

        Feed* _feed = nullptr;
        
    };
}


#endif
