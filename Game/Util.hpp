#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <Windows.h>

namespace Util
{
    struct Point
    {
        Point( int x_, int y_ ) : x( x_ ), y( y_ ) { }
        int x = 0;
        int y = 0;
    };

    static void SetConsoleSize( int width, int height )
    {
        HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
        CONSOLE_SCREEN_BUFFER_INFO console_info;
        COORD coord;
        SMALL_RECT rect;

        if( !GetConsoleScreenBufferInfo( handle, &console_info ) )
        {
            std::cout << "GetConsoleScreenBufferInfo failed" << std::endl;
            return;
        }

        rect.Left = 0;
        rect.Top = 0;
        rect.Right = width - 1;
        rect.Bottom = height - 1;

        if( FALSE == SetConsoleWindowInfo( handle, TRUE, &rect ) )
        {
            std::cout << "SetConsoleWindowInfo failed" << std::endl;
            return;
        }

        coord.X = width;
        coord.Y = height;
        if( FALSE == SetConsoleScreenBufferSize( handle, coord ) )
        {
            std::cout << "SetConsoleScreenBufferSize failed" << std::endl;
            return;
        }
    }

    static void GotoPosition( Point const& p )
    {
        COORD Cur;
        Cur.X = p.x;
        Cur.Y = p.y;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), Cur );
    }

}

#endif
