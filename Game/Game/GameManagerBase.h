#ifndef _GAME_MANAGER_BASE_H_
#define _GAME_MANAGER_BASE_H_

#include <thread>
#include <functional>

#include "../ErrorDefine.h"

namespace SnakeGame
{
    class GameManagerBase
    {
    public:
        using GAME_THREAD_PTR = std::shared_ptr<std::thread>;
        using GameThreadFunc = std::function<void( GameManagerBase* handle )>;

    public:
        GameManagerBase() = default;
        virtual ~GameManagerBase() = default;

    protected:
        ErrorDefine::ErrorCode InitGame( int width,
                                         int height,
                                         std::int64_t refresh_ms,
                                         std::int64_t end_score,
                                         GameThreadFunc game_thread_func )
        {
            _game_thread_func = game_thread_func;

            return ErrorDefine::ERROR_NONE;
        }

        ErrorDefine::ErrorCode StartGame()
        {
            _run = true;

            _game_thread = GAME_THREAD_PTR( new std::thread( _game_thread_func, this ) );

            return ErrorDefine::ERROR_NONE;
        }

        ErrorDefine::ErrorCode StopGame()
        {
            _run = false;
            if( _game_thread->joinable() )
            {
                _game_thread->join();
            }

            return ErrorDefine::ERROR_NONE;
        }

        bool ThreadStatus() const
        {
            return _run;
        }

        void SetThreadStatus( bool run )
        {
            _run = run;
        }

    private:
        bool _run = false;
        GAME_THREAD_PTR _game_thread = nullptr;
        GameThreadFunc _game_thread_func;
    };
}

#endif