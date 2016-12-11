#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

void draw_borders(WINDOW *screen) {
  

  int x, y, i;

  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "%lc", L'┌');
  mvwprintw(screen, y - 1, 0, "%lc", L'└');
  mvwprintw(screen, 0, x - 1, "%lc", L'┐');
  mvwprintw(screen, y - 1, x - 1, "%lc", L'┘');

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "│");
    mvwprintw(screen, i, x - 1, "│");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "─");
    mvwprintw(screen, y - 1, i, "─");
  }
}

int main(int argc, char *argv[]) {
  int parent_x, parent_y, new_x, new_y;
  int score_size = 3, ch;

  setlocale(LC_ALL, "");

initscr();
noecho(); 						
cbreak();
curs_set(0); 					 
keypad(stdscr, true);			
clear();		

  // set up initial windows
  getmaxyx(stdscr, parent_y, parent_x);

  WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
  WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);

  draw_borders(field);
  draw_borders(score);
  refresh();


  do{
    getmaxyx(stdscr, new_y, new_x);
  	

    if (new_y != parent_y || new_x != parent_x) {
      parent_x = new_x;
      parent_y = new_y;

      wresize(field, new_y - score_size, new_x);
      wresize(score, score_size, new_x);
      mvwin(score, new_y - score_size, 0);

      wclear(stdscr);
      wclear(field);
      wclear(score);


      draw_borders(field);
      draw_borders(score);

    }

    ch = getch();

    // draw to our windows
    mvwprintw(score, 1, 1, "Prima <x> para sair");

    // refresh each window
    wrefresh(field);
    wrefresh(score);



   
    
  } while(ch != 'x');

  endwin();

  return 0;
}