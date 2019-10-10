#include "GameManager.h"

#include <iostream>

namespace SnakeGame
{
    GameManager::GameManager()
    {

    }

    GameManager::~GameManager()
    {

    }

    void GameManager::GameThread( GameManagerBase* handle )
    {
        GameManager* pThis = dynamic_cast< GameManager* >( handle );
        if( nullptr == pThis )
        {
            std::cout << "pThis is nullptr" << std::endl;
            return;
        }
    }
}