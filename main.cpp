#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <string_view>
#include <bits/stdc++.h>

void welcomeScreen(int xCenter, int yCenter)
{
  std::string ballArt[5] {"Pong", "---##---\n","-######-\n","-######-\n","---##---" };
  std::string welcomeToPong {"Welcome to pong\n"};
  attron(COLOR_PAIR(2));
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
  attroff(COLOR_PAIR(2));
  getch();
  clear();
  refresh();
}
void menuScreen(int xCenter, int yCenter)
{
  WINDOW *menuWindow = newwin(10, 40, yCenter -5, xCenter - 20); 
  std::vector<std::string> menuEntries {"Play", "Exit"};
  int keyPressed {};
  uint selectedIndex {0};
  //I want to make an array and enable cycling through the 
    // array and highlighting the selection.
  int menuLength {static_cast<int>(menuEntries.size())};
  box(menuWindow, 0,0);
  refresh();
  wrefresh(menuWindow);
  move(yCenter - 5, xCenter -19);
  printw("Welcome");
  while (keyPressed != 'q')
  {
    // wrefresh(menuWindow);
    switch(keyPressed)
    {
      case KEY_DOWN:
        // if (selectedIndex<2)
        {
          selectedIndex += 1;
          break;
        }
      case KEY_UP:
        // if (selectedIndex >0)
        {
          selectedIndex -= 1;
          break;
        }
      case '\n':
        {
        if (selectedIndex % 2 == 1)
          {
          endwin(); 
          return; 
          }
        else if (selectedIndex % 2 ==0)
            // Will link to play screen from here. 
            continue;
        }
    }
    for (int i {0}; i<2; ++i)
    {
      move(yCenter-1 + i, xCenter - 2);
      if (selectedIndex  %  2  == i)
      {
      attron(COLOR_PAIR(2));
      printw(menuEntries[i].data());
      attroff(COLOR_PAIR(2));
      }
      else 
      {
         printw(menuEntries[i].data());
      }
      
    }
    keyPressed = getch();
    refresh();
  }
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
  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
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
