#ifndef _GAME_OBJECT
#define _GAME_OBJECT

#include <vector>

#include "../Util.hpp"

namespace SnakeGame
{
    enum BLOCK_COLOR
    {
        BLOCK_COLOR_BLACK = 0,
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
        BLOCK_COLOR_WHITE
    };

    using BlockColor = enum BLOCK_COLOR;

    class GameObject
    {
    public:
        GameObject() = delete;
        GameObject( Util::Point point, BlockColor color, std::string symbol );

        virtual void DrawObject();

    private:
        Util::Point _point;
        BlockColor _color = BLOCK_COLOR_BLACK;
        std::string _symbol;

    };
}


#endif
