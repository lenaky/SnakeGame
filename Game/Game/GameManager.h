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
    class Player;

    class GameManager : public GameManagerBase
    {
    public:
        typedef struct _SIZE
        {
            _SIZE(int width, int height) : width_( width ), height_( height ) { }
            int width_ = 0;
            int height_ = 0;
        } CONSOLE_SIZE, FIELD_SIZE;

    public:
        GameManager();
        virtual ~GameManager();

        ErrorDefine::ErrorCode InitGame( CONSOLE_SIZE cons_size, 
                                         FIELD_SIZE field_size,
                                         std::int64_t refresh_ms, 
                                         std::int64_t end_score );

        void ShowField();

        void DestroyGame();

        void KeyEventProc( KEY_EVENT_RECORD ker, std::shared_ptr<Player>& player );

        static void GameThread( GameManagerBase* handle );

    private:

        GameField* _field = nullptr;
        ConsoleInput::ConsoleKeyboardInput* _kbd_input = nullptr;

    };
}


#endif
