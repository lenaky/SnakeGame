#ifndef _CONSOLE_KEYBOARD_INPUT_H_
#define _CONSOLE_KEYBOARD_INPUT_H_

#include <Windows.h>

#include "../ErrorDefine.h"

using namespace ErrorDefine;

namespace ConsoleInput {

    class ConsoleKeyboardInput
    {
    public:
        ConsoleKeyboardInput() = default;
        virtual ~ConsoleKeyboardInput();

        ErrorCode InitializeKeyboardInput();

        HANDLE const& GetHandle() const
        {
            return _stdin_handle;
        }

    private:
        HANDLE _stdin_handle = nullptr;
        DWORD _old_console_mode;
    };
}

#endif