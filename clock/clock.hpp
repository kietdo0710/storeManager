#ifndef CLOCK_HPP
#define CLOCK_HPP
#include <stdlib.h>
#include <unistd.h>
#include <thread>
using namespace std;

class Clock
{
  public:
    static Clock * getClock();
    void getTime(char * );
    void start();
    void stop();
  private:
    Clock();
    ~Clock();
    void run(void);
    // Delete copy constructor and assignment
    Clock(const Clock&) = delete;
    Clock& operator=(const Clock&) = delete;
    int day;
    int hour;
    int min;
    int status;
    thread t1;
    static Clock* inst;
};

#endif
