#include "GameManager.h"
#include "../Game/GameField.h"

#include "../Input/ConsoleKeyboardInput.h"
#include "../Util.hpp"

#include <iostream>
#include <chrono>

namespace SnakeGame
{
    GameManager::GameManager() : _kbd_input( new ConsoleInput::ConsoleKeyboardInput() )
    {

    }

    GameManager::~GameManager()
    {
        if( nullptr != _kbd_input )
        {
            delete _kbd_input;
        }

        if( nullptr != _field )
        {
            delete _field;
        }
    }

    ErrorDefine::ErrorCode GameManager::InitGame( CONSOLE_SIZE cons_size,
                                                  FIELD_SIZE field_size,
                                                  std::int64_t refresh_ms, 
                                                  std::int64_t end_score )
    {
        ErrorDefine::ErrorCode error = GameManagerBase::InitGame( cons_size.width_, 
                                                                  cons_size.height_, 
                                                                  refresh_ms, 
                                                                  end_score, 
                                                                  &GameManager::GameThread );
        if( ErrorDefine::ERROR_NONE != error )
        {
            std::cout << "InitGame Failed. errorcode = " << error << std::endl;
            return error;
        }

        error = _kbd_input->InitializeKeyboardInput();
        if( ErrorDefine::ERROR_NONE != error )
        {
            std::cout << "InitGame Failed. errorcode = " << error << std::endl;
            return error;
        }

        _field = new GameField( field_size.width_, field_size.height_ );

        return ErrorDefine::ERROR_NONE;
    }

    void GameManager::ShowField()
    {
        if( nullptr != _field )
        {
            _field->ShowField();
        }
    }

    void GameManager::DestroyGame()
    {
        if( nullptr != _field )
        {
            delete _field;
            _field = nullptr;
        }
    }

    void GameManager::GameThread( GameManagerBase* handle )
    {
        GameManager* pThis = dynamic_cast< GameManager* >( handle );
        if( nullptr == pThis )
        {
            std::cout << "pThis is nullptr" << std::endl;
            return;
        }

        pThis->ShowField();

        auto base_time = std::chrono::system_clock::now();

        while( pThis->ThreadStatus() )
        {
            auto current_time = std::chrono::system_clock::now();
            if( std::chrono::duration_cast<std::chrono::milliseconds>( current_time - base_time ).count() > pThis->GetRefreshMS() )
            {
                base_time = current_time;
            }



            std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

        }
    }
}