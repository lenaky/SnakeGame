#include <iostream>

#include "ConsoleKeyboardInput.h"

namespace ConsoleInput
{
    ConsoleKeyboardInput::~ConsoleKeyboardInput()
    {
        SetConsoleMode( _stdin_handle, _old_console_mode ); // restore console mode
    }

    ErrorCode ConsoleKeyboardInput::InitializeKeyboardInput()
    {
        _stdin_handle = GetStdHandle( STD_INPUT_HANDLE );
        if( _stdin_handle == INVALID_HANDLE_VALUE )
        {
            std::cout << "failed to GetStdHandle" << std::endl;
            return GET_HANDLE_FAILED;
        }

        if( !GetConsoleMode( _stdin_handle, &_old_console_mode ) )
        {
            std::cout << "failed to GetConsoleMode" << std::endl;
            return GET_CONSOLE_FAILED;
        }

        DWORD fdwMode = ENABLE_WINDOW_INPUT;
        if( !SetConsoleMode( _stdin_handle, fdwMode ) )
        {
            std::cout << "SetConsoleMode failed" << std::endl;
            return SET_CONSOLE_FAILED;
        }

        return ERROR_NONE;
    }
}