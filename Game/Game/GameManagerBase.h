#ifndef _GAME_MANAGER_BASE_H_
#define _GAME_MANAGER_BASE_H_

#include <thread>
#include <functional>

#include "../ErrorDefine.h"
#include "../Util.hpp"

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
        ErrorDefine::ErrorCode InitGame( int console_width,
                                         int console_height,
                                         std::int64_t refresh_ms,
                                         std::int64_t end_score,
                                         GameThreadFunc game_thread_func )
        {
            _console_width = console_width;
            _console_height = console_height;
            _refresh_ms = refresh_ms;
            _end_score = end_score;
            _game_thread_func = game_thread_func;

            Util::SetConsoleSize( console_width, console_height );

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

        std::int64_t GetRefreshMS() const { return _refresh_ms; }
        std::int64_t GetGameEndScore() const { return _end_score; }

    public:
        ErrorDefine::ErrorCode StartGame()
        {
            _run = true;

            _game_thread = GAME_THREAD_PTR( new std::thread( _game_thread_func, this ) );

            return ErrorDefine::ERROR_NONE;
        }

        ErrorDefine::ErrorCode WaitExit()
        {
            if( _game_thread->joinable() )
            {
                _game_thread->join();
            }

            return ErrorDefine::ERROR_NONE;
        }

        ErrorDefine::ErrorCode StopGame()
        {
            _run = false;

            return ErrorDefine::ERROR_NONE;
        }

    private:
        volatile bool _run = false;
        GAME_THREAD_PTR _game_thread = nullptr;
        GameThreadFunc _game_thread_func;

        int _console_width = 0;
        int _console_height = 0;

        std::int64_t _refresh_ms = 0;
        std::int64_t _end_score = 0;
    };
}

#endif