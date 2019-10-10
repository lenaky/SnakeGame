#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "GameManagerBase.h"

namespace ConsoleInput
{
    class ConsoleKeyboardInput;
}

namespace SnakeGame
{
    class GameField;

    class GameManager : public GameManagerBase
    {
    public:
        GameManager();
        virtual ~GameManager();

        static void GameThread( GameManagerBase* handle );

    private:

        GameField* field = nullptr;

        ConsoleInput::ConsoleKeyboardInput* _kbd_input = nullptr;

    };
}


#endif
