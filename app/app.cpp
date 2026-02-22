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
  Ui* myUi = Ui::open();
  while (0 == myUi->run()) {
  }
  myUi->close();
  return 0;
}