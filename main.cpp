#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <string_view>
#include <bits/stdc++.h>

void welcomeScreen(int xCenter, int yCenter)
{
  std::string ballArt[5] {"Pong", "---##---\n","-######-\n","-######-\n","---##---" };
  std::string welcomeToPong {"Welcome to pong\n"};
  move(yCenter, xCenter - welcomeToPong.length()/2);
  printw(welcomeToPong.data());
  refresh();
  getch();
  clear();
  for (int i{0} ;i<=4; i++)
  {
    move(yCenter + (3-i), xCenter - ballArt[i].length()/2);
    printw(ballArt[i].data());
  }
  getch();
  clear();
  refresh();

}

void menuScreen(int xCenter, int yCenter)
{
  WINDOW *menuWindow = newwin(10, 40, yCenter -5, xCenter - 20); 
  std::vector<std::string> menuEntries {"Play", "Exit"};
  //I want to make an array and enable cycling through the 
    // array and highlighting the selection.
  int menuLength {static_cast<int>(menuEntries.size())};
  box(menuWindow, 0,0);
  wrefresh(menuWindow);
  move(yCenter - 5, xCenter -19);
  printw("Welcome");
  move(yCenter, xCenter);
  refresh();
  getch();

}

void game()
{

}

void playAgain()
{

}

int main()
{
  
  initscr();
  keypad(stdscr, TRUE);
  int xCenter {getmaxx(stdscr)/2};
  int yCenter {getmaxy(stdscr)/2};

  // cbreak();
  bool menu {true};
  int key {};

  // std::string menuSelect[2] {"Play", "Exit"};
  // int menuLength = sizeof(menuSelect)/sizeof(menuSelect[0]);

  // WINDOW * win = newwin(10, 40, yCenter - 5, xCenter - 20);

  // box(win, 0, 0);

  welcomeScreen(xCenter, yCenter); 
  menuScreen(xCenter, yCenter); 
  // while (menu)
  // {
  //   
  // for (int i {0}; i <= menuLength; ++i)
  //   {
  //     move(yCenter -i ,xCenter);
  //     printw(menuSelect[i].data());
  //     printw("\n");
  //   
  //   }
  //   // move(yCenter, xCenter);
  //   // wrefresh(win);
  //   // refresh();
  //   key = getch();
  //   switch(key)
  //   {
  //     case KEY_ENTER:
  //       break;
  //     case KEY_UP:
  //       move(yCenter -1, xCenter);
  //     case KEY_DOWN:
  //       move(yCenter +1, xCenter);
  //     default:
  //       continue;
  //   }
  //   refresh();
  // }

  return 0;


}
