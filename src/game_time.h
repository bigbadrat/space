#ifndef TANAKA_GAME_TIME_H_
#define TANAKA_GAME_TIME_H_
#include <chrono>

namespace Tanaka
{

struct GameTime
{
    typedef std::chrono::milliseconds Milliseconds;
    typedef std::chrono::high_resolution_clock Clock;
    typedef Clock::time_point TimePoint;

    GameTime():
            elapsed_time(0),
            total_time(0)
    {}

    double elapsed_time;
    double total_time;

    static
    Clock::time_point now()
    {
        return Clock::now();
    }

};

} //end namespace Tanaka
#endif
