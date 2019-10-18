#ifndef _FEED_H_
#define _FEED_H_

#include <chrono>
#include <set>

#include "GameObject.h"

namespace SnakeGame
{
    class Player;

    class Feed
    {
    public:
        Feed() = delete;
        Feed( int interval, int amount, int field_max, Util::Range x_range, Util::Range y_range );
        ~Feed() = default;

        void StartCheck();

        void TryFeed(Player const* player);

        void RemoveFeed( Util::Point const& point );

        std::set<GameObject> const& GetFeeds() const { return _feeds; }

    private:
        void _ShowFeeds();

    private:

        std::set<GameObject> _feeds;
        
        int _interval = 0; // ��ms �ֱ�� ä�� ���ΰ�
        int _amount = 0; // ��� ���̸� ä�� ���ΰ�
        int _field_max = 0; // �ִ� � ������ ���ΰ�
        Util::Range _x_range;
        Util::Range _y_range;

        std::chrono::time_point<std::chrono::system_clock> _begin;
    };
}


#endif
