#include "clock/clock.hpp"
#include "ui/ui.hpp"
#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <thread>

using namespace std;

// Global variables.
WINDOW* ue1;
WINDOW* desc;
bool halt = false;
bool sw1 = false;
bool sw2 = false;
bool sw3 = false;
bool sw4 = false;
bool sw5 = false;
bool sw6 = false;
bool sw7 = false;

Clock* globalClock = new Clock();
Ui* myUi = new Ui();

void update_display();

void program()
{
	while (1)
	{
		update_display();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void display_basic_ui(void)
{
	// Print the basic text.
	mvwprintw(desc, 0, 2, " Events ");
	mvwprintw(desc, 1, 2, "The events shall be displayed here. ");
	mvwprintw(desc, 2, 2, "Event: ");
	
	mvwprintw(ue1, 0, 2, " Store ");
	mvwprintw(ue1, 2, 2, ">> Stocks <<");
	mvwprintw(ue1, 3, 2, "Fish :            Bean :");
	mvwprintw(ue1, 4, 2, "Beef :            Vegie:");
	
	mvwprintw(ue1, 6, 2, ">> Market price <<");
	mvwprintw(ue1, 7, 2, "Fish :            Bean :");
	mvwprintw(ue1, 8, 2, "Beef :            Vegie:");
	
	mvwprintw(ue1, 25, 2, "Processor is: RUNNING");
}


// --- UPDATE DISPLAY ---
// Update the status display.
void update_display()
{
	char time[20]; 
	globalClock->getTime(time);
	// Update with the current opcode, address, flags & register values.
	mvwprintw(ue1, 0, 40, "%s",time);
	mvwprintw(ue1, 1, 40, "%d$",10000);
	mvwprintw(ue1, 2, 2, ">> Stocks <<");
	mvwprintw(ue1, 3, 2, "Fish : %2d        Bean : %2d",12,34);
	mvwprintw(ue1, 4, 2, "Beef : %2d        Vegie: %2d",56,78);
	
	mvwprintw(ue1, 6, 2, ">> Market price <<");
	mvwprintw(ue1, 7, 2, "Fish : %2d        Bean : %2d",11,22);
	mvwprintw(ue1, 8, 2, "Beef : %2d        Vegie: %2d",33,44);
	mvwprintw(desc, 2, 9, "    ");
	
	if (halt) {
		wattron(ue1, COLOR_PAIR(2) | A_BOLD);
		mvwprintw(ue1, 25, 16, "HALTED ");
		wattroff(ue1, COLOR_PAIR(2) | A_BOLD);
		globalClock->stop();
	}
	else {
		wattron(ue1, COLOR_PAIR(3) | A_BOLD);
		mvwprintw(ue1, 25, 16, "RUNNING");
		wattroff(ue1, COLOR_PAIR(3) | A_BOLD);
		globalClock->start();
	}
	wrefresh(desc);	// Show the box.
	wrefresh(ue1);	// Show the box.
}

int main ()
{
	initscr();			/* Start curses mode 		  */
	noecho();			/* Don't echo() while we do getch */
	cbreak();			/* Line buffering disabled, Pass on everything to me */
	keypad(stdscr, TRUE);		/* I need that nifty F1  */
	curs_set(1);			/* Hide the cursor.  */
	nodelay(stdscr, TRUE);
	
	// Check for colour support in terminal.
	// FIXME: Exit if not supported.
	if (has_colors() == FALSE) {
		endwin();
		std::cout << "Your terminal doesn't support colours." << std::endl;
		return 1;
	}
	
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE); 	// fore & background colours.
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	
	//attron(COLOR_PAIR(1));
	wattron(ue1, COLOR_PAIR(1));
	
	// Create a window that we can put the emulator status on.
	// arguments: rows, columns, start_y, start_x
	desc = newwin(9, 70, 1, 2);
	ue1 = newwin(28, 60, 10, 2);
	box(desc, 0, 0);	// use default window outline characters.
	box(ue1, 0, 0);		// use default window outline characters.
	wrefresh(desc);	// Show the box.
	wrefresh(ue1);	// Show the box.
	
	// Use a panel to ease management. 
	//PANEL* desc_panel = new_panel(desc);
	//PANEL* ue1_panel = new_panel(ue1);
	display_basic_ui();

	int key;
	thread t1 = thread(&program);
	t1.detach();
	while (true) {
		wrefresh(desc);	// Show the box.
		wrefresh(ue1);	// Show the box.
		
		key = wgetch(desc);
		if (key == 'q') {
			break;
		}
		else if (key == 'h') {
			halt = true;
		}
		else if (key == 'g') {
			halt = false;
		}
	}

	wattroff(ue1, COLOR_PAIR(1));

	// Clean up ncurses library.
	delwin(desc);
	delwin(ue1);
	endwin();			/* End curses mode		  */
	return 0;
}