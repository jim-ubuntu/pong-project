#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <string_view>
#include <bits/stdc++.h>
#include <vector>

void gameplay(int xCenter, int yCenter, WINDOW * menuWindow);
void playAgain(int xCenter, int yCenter, WINDOW * menuWindow);

void welcomeScreen(int xCenter, int yCenter)
{
  std::string ballArt[5] {"Pong", "---##---\n","-######-\n","-######-\n","---##---" };
  std::string welcomeToPong {"Welcome to pong\n"};
  // attron(COLOR_PAIR(2));
  move(yCenter, xCenter - welcomeToPong.length()/2);
  printw(welcomeToPong.data());
  refresh();
  //timer screen off when testing...
  // sleep(3);
  getch();
  clear();
  for (int i{0} ;i<=4; i++)
  {
    move(yCenter + (3-i), xCenter - ballArt[i].length()/2);
    printw(ballArt[i].data());
  }
  // attroff(COLOR_PAIR(2));
  refresh();
  getch();
  clear();
  // timer screen off when testing...
  // sleep(3);
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
           gameplay(xCenter, yCenter, menuWindow); 
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

void gameplay(int xCenter, int yCenter, WINDOW * menuWindow)
{
  clear();
  // WINDOW * gameWindow = newwin();
  constexpr int courtHeight {20};
  constexpr int courtWidth{60};
  bool game {true};
  int input {};

  WINDOW * gameSpace = newwin(courtHeight,courtWidth, yCenter-(courtHeight/2), xCenter-(courtWidth/2));
  refresh();


  // box(gameSpace,0,0);
  wrefresh(gameSpace);
  wborder(gameSpace,0,0,0,0,0,0,0,0);
  for (int i {3}; i >=0; --i)
  {
    switch(i)
      {
        case 0:
        {
          move(yCenter,xCenter);
          printw("");
          break;
        }
        default:
       {       
        move(yCenter, xCenter);
        printw("%d", i);
        refresh();
        sleep(1);
        break;
       }
       }
  }

  wborder(gameSpace, '%s' , '%s' , 0,0,0,0,0,0);
  wrefresh(gameSpace);
  refresh();
  wrefresh(gameSpace);
  refresh();
  while (game)
  {
    
    if (input == '\n')
    {
      clear();
      game = false; 
      break;
    }
    wrefresh(gameSpace);
    refresh();
    input = getch();
  }

  clear();
  refresh();
  playAgain(xCenter,yCenter,menuWindow);

}

void playAgain(int xCenter, int yCenter, WINDOW * menuWindow)
{
  std::vector<std::string> menuEntries {"Play again", "Exit"};
  constexpr bool endScreen {true};
  uint selectedIndex {0};
  int keyPressed {};
  while (endScreen)
  {
    switch(keyPressed)
    {
      case KEY_DOWN:
        {
          selectedIndex +=1;
          break;
        }
      case KEY_UP:
        {
          selectedIndex -=1;
          break;
        }
      case '\n':
      {
        if (selectedIndex % 2 == 0)
        {
          gameplay(xCenter,yCenter,menuWindow);
          break;
        }
        else
        {
          endwin();
          std::exit(0);
        }
      }
      default:
        break;
    }
    box(menuWindow, 0,0);
    move(yCenter - 5, xCenter -19);
    printw("Game Over");
    wrefresh(menuWindow);

    for (int i {0}; i < 2; ++i)
    {
      if (selectedIndex % 2 == i)
      {
        attron(COLOR_PAIR(3));
        move(yCenter-1 + i, xCenter - menuEntries[i].length()/2);
        printw(menuEntries[i].data());
      attroff(COLOR_PAIR(3));
      }
      else 
      {
        move(yCenter-1 + i, xCenter - menuEntries[i].length()/2);
        printw(menuEntries[i].data());
      }
    }
    refresh();
    keyPressed = getch();
  }
}

int main()
{
  
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  noecho();

  const int xCenter {getmaxx(stdscr)/2};
  const int yCenter {getmaxy(stdscr)/2};
  const int& xCenterRef {xCenter};
  const int& yCenterRef {yCenter};

  WINDOW *menuWindow = newwin(10, 40, yCenter -5, xCenter - 20); 

  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  // cbreak();
  bool menu {true};
  int key {};

  welcomeScreen(xCenterRef, yCenterRef); 
  menuScreen(xCenterRef, yCenterRef, menuWindow); 
  
  return 0;
}

