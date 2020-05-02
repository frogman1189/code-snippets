//start 11:29
//end 11:50
//url http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html#using


//to compile either dynamically link library
//   gcc -lncurses prog.c
//or statically link
//   gcc prog.c libncurses.a
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
  initscr(); //initialize curses

  cbreak(); //one char at a time input

  noecho(); //prevents echo of entered character

  keypad(stdscr, TRUE); //get special char i.e arrow keys, bckspce, delete

  WINDOW * win = newwin(nlines, ncols, y0, x0); //declares new window
  //where y0 and x0 change where on screen, and nlines and ncols are char* size

  // LINES and COLUMNS contains size of screen
  // if terminal resized then void getmaxyx(WINDOW *, int y, int x)
  // is used to get screen

  //windows cannot overlap so either use stdscr or make multiple
  // non-overlapping windows using newwin

  wrefresh(stdscr); //refreshes stdscr -- updates the output.
  // Changes not visible until refreshed.

  wrefresh(win).refresh(); // erases everything written to a window.
  delwin(win); //deletes a window.


  //int wmove(WINDOW *win, int y, int x) use this function to move cursor.
  // cursor is default loc for most output and tells user where input expected
  // again, screen must be refreshed before it is displayed.

  //equiv to move(y, x);

  int ch = getch(); //takes user input. if noecho() then won't display
  //if cbreak() then immediatly returned rather than waiting for \n

  nodelay(stdscr, TRUE); // getch but non-blocking.
  //for(;;){} is an infinite loop.

  /*
           key code        description

           KEY_DOWN        The four arrow keys ...
           KEY_UP
           KEY_LEFT
           KEY_RIGHT
           KEY_HOME        Home key 
           KEY_BACKSPACE   Backspace
           KEY_F(n)        Function keys, for 0 <= n >= 63
           KEY_DC          Delete character
           KEY_IC          Insert char or enter insert mode
           KEY_ENTER       Enter or send
  */
  
  
  endwin(); //must be called to return terminal settings before exit
  return 0;
}
