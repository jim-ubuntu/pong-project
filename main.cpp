#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <string_view>
#include <bits/stdc++.h>

void gameplay(int xCenter, int yCenter);

void welcomeScreen(int xCenter, int yCenter)
{
  std::string ballArt[5] {"Pong", "---##---\n","-######-\n","-######-\n","---##---" };
  std::string welcomeToPong {"Welcome to pong\n"};
  // attron(COLOR_PAIR(2));
  move(yCenter, xCenter - welcomeToPong.length()/2);
  printw(welcomeToPong.data());
  refresh();
  sleep(3);
  clear();
  for (int i{0} ;i<=4; i++)
  {
    move(yCenter + (3-i), xCenter - ballArt[i].length()/2);
    printw(ballArt[i].data());
  }
  // attroff(COLOR_PAIR(2));
  refresh();
  clear();
  sleep(3);
}
void menuScreen(int xCenter, int yCenter, WINDOW * menuWindow)
{
  std::vector<std::string> menuEntries {"Play", "Exit"};
  int keyPressed {};
  uint selectedIndex {0};
  //I want to make an array and enable cycling through the 
    // array and highlighting the selection.
  int menuLength {static_cast<int>(menuEntries.size())};
  refresh();
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
           gameplay(xCenter, yCenter); 
           break;
        }
    }

    box(menuWindow, 0,0);
    wrefresh(menuWindow);
    move(yCenter - 5, xCenter -19);
    printw("Welcome");
    refresh();

    for (int i {0}; i<2; ++i)
    {
      move(yCenter-1 + i, xCenter - 2);
      if (selectedIndex  %  2  == i)
      {
      attron(COLOR_PAIR(3));
      printw(menuEntries[i].data());
      attroff(COLOR_PAIR(3));
      }
      else 
      {
         printw(menuEntries[i].data());
      }
    refresh();
    }
    keyPressed = getch();
  }
  refresh();
  getch();

}

void gameplay(int xCenter, int yCenter)
{
  clear();
  // WINDOW * gameWindow = newwin();
  
  for (int i {3}; i >=1; --i)
  {
    move(yCenter, xCenter);
    printw("%d", i);
    refresh();
    sleep(1);
  }
}

void playAgain(int xCenter, int yCenteri, WINDOW * menuWindow)
{
  
}

int main()
{
  
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);

  const int xCenter {getmaxx(stdscr)/2};
  const int yCenter {getmaxy(stdscr)/2};
  const int& xCenterRef {xCenter};
  const int& yCenterRef {yCenter};

  WINDOW *menuWindow = newwin(10, 40, yCenter -5, xCenter - 20); 

  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  // cbreak();
  bool menu {true};
  int key {};

  // std::string menuSelect[2] {"Play", "Exit"};
  // int menuLength = sizeof(menuSelect)/sizeof(menuSelect[0]);

  // WINDOW * win = newwin(10, 40, yCenter - 5, xCenter - 20);

  // box(win, 0, 0);

  welcomeScreen(xCenterRef, yCenterRef); 
  menuScreen(xCenterRef, yCenterRef, menuWindow); 
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

