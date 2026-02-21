#include <stdlib.h>
#include <unistd.h>
#include <thread>

using namespace std;

class Clock
{
  public:
    Clock();
    ~Clock();
    void getTime(char * );
    void start();
    void stop();
  private:
    void run(void);
    int day;
    int hour;
    int min;
    int status;
    thread t1;
};
