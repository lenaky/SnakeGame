#include "GameManager.h"
#include "../Game/GameField.h"
#include "../Game/Player.h"

#include "../Input/ConsoleKeyboardInput.h"
#include "../Util.hpp"

#include <iostream>
#include <chrono>

namespace SnakeGame
{
    GameManager::GameManager() : _kbd_input( new ConsoleInput::ConsoleKeyboardInput() )
    {
        Util::HideCursor();
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

    void GameManager::KeyEventProc( KEY_EVENT_RECORD ker, std::shared_ptr<Player>& player )
    {
        if( ker.bKeyDown )
        {
            switch( ker.wVirtualKeyCode )
            {
            case VK_LEFT:
                player->SetDirection( DIRECTION_LEFT );
                break;
            case VK_RIGHT:
                player->SetDirection( DIRECTION_RIGHT );
                break;
            case VK_DOWN:
                player->SetDirection( DIRECTION_DOWN );
                break;
            case VK_UP:
                player->SetDirection( DIRECTION_UP );
                break;
            case VK_SHIFT:
                player->AddBody();
                break;
            case VK_ESCAPE:
                std::cout << "game exit...." << std::endl;
                StopGame();
                break;
            }
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

        auto& player = std::shared_ptr<Player>( new Player() );
        player->ShowBody();

        auto base_time = std::chrono::system_clock::now();

        while( pThis->ThreadStatus() )
        {
            DWORD cNumRead;
            INPUT_RECORD irInBuf[ 128 ];

            std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

            auto current_time = std::chrono::system_clock::now();
            if( std::chrono::duration_cast<std::chrono::milliseconds>( current_time - base_time ).count() > pThis->GetRefreshMS() )
            {
                player->ClearBody();
                player->Move();
                player->ShowBody();                
                base_time = current_time;
            }

            DWORD numEvents = 0;
            GetNumberOfConsoleInputEvents( pThis->_kbd_input->GetHandle(), &numEvents );

            if( 0 >= numEvents )
            {
                continue;
            }

            if( !ReadConsoleInput(
                pThis->_kbd_input->GetHandle(),
                irInBuf,
                128,
                &cNumRead ) )
            {
                continue;
            }

            for( DWORD i = 0; i < cNumRead; i++ )
            {
                switch( irInBuf[ i ].EventType )
                {
                case KEY_EVENT:
                    pThis->KeyEventProc( irInBuf[ i ].Event.KeyEvent, player );
                    break;
                }
            }
        }
    }
}