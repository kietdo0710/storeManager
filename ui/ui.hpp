#ifndef UI_HPP
#define UI_HPP
#include <thread>
#include <ncurses.h>

class Ui
{
  public:
    static Ui* getUi();
    int run();
  private:
    Ui();
    ~Ui();
    static void refresh();
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