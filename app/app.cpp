#include "clock/clock.hpp"
#include "ui/ui.hpp"
#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <thread>

using namespace std;

int main ()
{
  Clock* myClock = Clock::getClock();
  Ui* myUi = Ui::getUi();
  while (0 == myUi->run()) {
  }
  // Wait 1 sec for all thread stop
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return 0;
}