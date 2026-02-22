#ifndef UI_HPP
#define UI_HPP
#include <thread>
#include <ncurses.h>

class Ui
{
  public:
    static Ui* open();
    int run();
    void close();
  private:
    Ui();
    ~Ui();
    // Delete copy constructor and assignment
    Ui(const Ui&) = delete;
    Ui& operator=(const Ui&) = delete;
    void refresh();
    void display_basic_ui();
    void debug_display(int);
    void event_display();
    void store_display();
    WINDOW* ue1;
    WINDOW* desc;
    WINDOW* debug;
    std::thread t1;
    static Ui* uiInst;
};
#endif