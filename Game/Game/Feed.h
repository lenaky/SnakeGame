#ifndef _FEED_H_
#define _FEED_H_

#include <chrono>
#include <set>

#include "GameObject.h"

namespace SnakeGame
{
    class Feed
    {
    public:
        Feed() = delete;
        Feed( int interval, int amount, Util::Range x_range, Util::Range y_range );
        ~Feed() = default;

        void StartCheck();

        void TryFeed();

        void RemoveFeed( Util::Point const& point );

    private:

        std::set<GameObject> _feeds;

        int _interval = 0; // ��ms �ֱ�� ä�� ���ΰ�
        int _amount = 0; // ��� ���̸� ä�� ���ΰ�
        Util::Range _x_range;
        Util::Range _y_range;

        std::chrono::time_point<std::chrono::system_clock> _begin;
    };
}


#endif
