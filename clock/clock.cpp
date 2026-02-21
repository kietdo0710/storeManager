#include "clock.hpp"
#include <string>

using namespace std;

Clock::Clock(void)
{
    day = 0;
    hour = 0;
    min = 0;
    status = 1;
    thread t1 = thread(&Clock::run, this);
    t1.detach();
}

Clock::~Clock(void)
{
    t1.join();
}

void Clock::getTime(char * time)
{
    sprintf(time, "Day %3d, %2d:%2d", day, hour, min);
}

void Clock::start()
{
    status = 1;
}

void Clock::stop()
{
    status = 0;
}

void Clock::run(void)
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (status == 1)
        {
            min++;
            if (min == 60)
            {
                min = 0;
                hour++;
            }
            if (hour == 24) {
                hour = 0;
                day++;
            }
        }
    }
}
