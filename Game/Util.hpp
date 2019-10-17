#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <random>

#include <Windows.h>

namespace Util
{
    struct Point
    {
        Point( int x_, int y_ ) : x( x_ ), y( y_ ) { }
        bool operator==( Point const& rhs ) const
        {
            if( rhs.x == x && rhs.y == y )
            {
                return true;
            }

            return false;
        }
        int x = 0;
        int y = 0;
    };

    struct Range
    {
        Range( std::int64_t begin, std::int64_t end ) : begin_( begin ), end_( end ) { }
        std::int64_t begin_ = 0;
        std::int64_t end_ = 0;
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
    
    static void HideCursor()
    {
        HANDLE consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo( consoleHandle, &info );
    }

    static void GotoPosition( Point const& p )
    {
        COORD Cur;
        Cur.X = p.x;
        Cur.Y = p.y;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), Cur );
    }

    template<typename T>
    static T GetRandom( T min, T max )
    {
        std::random_device random_device;
        std::mt19937_64 mt( random_device() );
        std::uniform_int_distribution<T> range( min, max );

        return range( mt );
    }
}

#endif
