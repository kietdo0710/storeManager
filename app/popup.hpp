#include <ncurses.h>
#include <string>

class SetPricePopup
{
  private:
    WINDOW* setp;
    std::string cont;
    int fcurs;
  public:
    SetPricePopup(int row, int col, int x, int y, char * goods){
    	setp = newwin(row, col, x, y);
      box(setp, 0, 0);
  		mvwprintw(setp, 0, 2, " Set price for selling %s :", goods);
  		mvwprintw(setp, 2, 2, ">> ");
      fcurs = 5;
      wrefresh(setp);
    }
    int input(int in)
    {
      if (in == 127)
      {
        if (!cont.empty())
        {
          cont.pop_back();
        }
      }
      else if ((47 < in) && (in < 58))
      {
        if (cont.length() < 4)
        {
          cont.push_back(in);
        }
      }
      else if (in == 10)
      {
        delete this;
        return -1;
      }
      else
      {
        // Do nothing 
      }
  		mvwprintw(setp, 2, fcurs, "                    ");
  		mvwprintw(setp, 2, fcurs, cont.c_str());
      wrefresh(setp);
      return 0;
    }
    ~SetPricePopup(){
  		wclear(setp);
      wrefresh(setp);
    	delwin(setp);
    }
};