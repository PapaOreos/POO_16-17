/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "header.h"
#include "ecra_inicial.h"


void start_ecra(){
    //para podermos ir buscar todos os codigos ascii
    setlocale(LC_ALL, "");

    initscr();
    //noecho(); 						
    cbreak();
    curs_set(0); 					 
    keypad(stdscr, true);			
    clear();
}
//--------------------------------------------------------------------------------------------------------------------------
void set_tamanho(int &parent_y, int &parent_x){
    
    
    do{
        //obter tamanho da consola
        getmaxyx(stdscr, parent_y, parent_x);
        
        //centrar informação
        mvwprintw(stdscr, (parent_y/2)-1,    (parent_x/2)-17, "Por favor aumento o tamanho do ecra");
        mvwprintw(stdscr, (parent_y/2),      (parent_x/2)-10, "Tamanho atual: %dx%d", parent_x, parent_y);
        mvwprintw(stdscr, (parent_y/2)+1,    (parent_x/2)-12, "Tamanho pretendido: 150x45");

        //ir limpando para garantir que nao fica "feio" com o resize
        getch();
        clear_line((parent_y/2)-1,   (parent_x/2)-17);
        clear_line((parent_y/2),   (parent_x/2)-10);
        clear_line((parent_y/2)+1,   (parent_x/2)-12);
        refresh();

        //condição de saida do ciclo (condição dentro do ciclo aparenta ter problemas)
        if(parent_y >= 45 && parent_x >= 150)
            break;
    }while(1);
}

//--------------------------------------------------------------------------------------------------------------------------


void draw_borders(WINDOW *screen){
    
      int x, y, i;

  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0,       "%lc", L'┌');
  mvwprintw(screen, y-1, 0,     "%lc", L'└');
  mvwprintw(screen, 0, x-1,     "%lc", L'┐');
  mvwprintw(screen, y-1, x-1,   "%lc", L'┘');

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0,     "│");
    mvwprintw(screen, i, x-1,   "│");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i,     "─");
    mvwprintw(screen, y - 1, i, "─");
  }
  
    refresh();
    
}

//--------------------------------------------------------------------------------------------------------------------------

void print_ecra(int &y, int &x){
        
    int new_x, new_y;
    getmaxyx(stdscr, new_y, new_x);
  	
//se a janela for alterada de tamanho;
    if (new_y != y|| new_x != x) {
      x = new_x;
      y = new_y;

      wclear(stdscr);
    }
    draw_borders(stdscr);
    mvwprintw(stdscr,   y-2,    1,  "Comando > ");
    curs_set(1);
    clear_line(y-2,    11);    mvprintw(y-2, x-1,   "│");  move(y-2, 11); //caso contrario a linha da border nao aparece!
}

//--------------------------------------------------------------------------------------------------------------------------

