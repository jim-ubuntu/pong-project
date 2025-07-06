#include <ncurses.h>



int main()
{
  
  initscr();
  int xCenter {getmaxx(stdscr)/2};
  int yCenter {getmaxy(stdscr)/2};
  move(yCenter, xCenter);
  printw("Welcome to pong\n");
  refresh();
  getch();
  clear();
  move(yCenter,xCenter);
  printw("---##---\n");
  move(yCenter + 1, xCenter);
  printw("-######-\n");
  move(yCenter + 2, xCenter);
  printw("-######-\n");
  move(yCenter + 3, xCenter);
  printw("---##---");
  refresh();
  getch();
  clear();
  endwin();  
  return 0;


}
