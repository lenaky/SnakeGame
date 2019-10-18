#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <vector>

#include "../Util.hpp"

namespace SnakeGame
{
    enum BLOCK_COLOR
    {
        BLOCK_COLOR_START = 0,
        BLOCK_COLOR_BLACK = BLOCK_COLOR_START,
        BLOCK_COLOR_BLUE,
        BLOCK_COLOR_GREEN,
        BLOCK_COLOR_CYAN,
        BLOCK_COLOR_RED,
        BLOCK_COLOR_MAGENTA,
        BLOCK_COLOR_BROWN,
        BLOCK_COLOR_LIGHTGRAY,
        BLOCK_COLOR_DARKGRAY,
        BLOCK_COLOR_LIGHTBLUE,
        BLOCK_COLOR_LIGHTGREEN,
        BLOCK_COLOR_LIGHTCYAN,
        BLOCK_COLOR_LIGHTRED,
        BLOCK_COLOR_LIGHTMAGENTA,
        BLOCK_COLOR_YELLOW,
        BLOCK_COLOR_WHITE,
        BLOCK_COLOR_END = BLOCK_COLOR_WHITE
    };

    using BlockColor = enum BLOCK_COLOR;

    class GameObject
    {
    public:
        GameObject() = delete;
        explicit GameObject( Util::Point point );
        GameObject( Util::Point point, BlockColor color, std::string symbol, bool show );
        virtual ~GameObject() = default;

        bool operator< ( GameObject const& rhs ) const
        {
            if( _point.x < rhs._point.x)
            {
                return true;
            }

            if( _point.x == rhs._point.x )
            {
                if( _point.y < rhs._point.y )
                {
                    return true;
                }                    
            }

            return false;
        }

        virtual void DrawObject() const;
        virtual void ClearObject() const;

        void SetPosition( Util::Point const& point );
        void SetVisible( bool show );
        bool GetVisible() const { return _show; }
        Util::Point const& GetPosition() const { return _point; }

    private:
        Util::Point _point;
        BlockColor _color = BLOCK_COLOR_BLACK;
        std::string _symbol;
        bool _show = false;

    };
}


#endif
