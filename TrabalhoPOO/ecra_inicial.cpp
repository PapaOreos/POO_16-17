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
    
    int colum [3] = { 1, 20, 45};
    
    int new_x, new_y;
    getmaxyx(stdscr, new_y, new_x);
  	
//se a janela for alterada de tamanho;
    if (new_y != y|| new_x != x) {
      x = new_x;
      y = new_y;

      wclear(stdscr);
    }

    draw_borders(stdscr); 
    mvwprintw(stdscr,   1,      colum[0],   "Comandos Validos");    mvwprintw(stdscr,   1,      colum[1],      "Parametros");           mvwprintw(stdscr,   1,      colum[2],      "Caracteristica");
    
    mvwprintw(stdscr,   3,      colum[0],   "dim");                 mvwprintw(stdscr,   3,      colum[1],      "linhas colunas");       mvwprintw(stdscr,   3,      colum[2],      "Define a Dimensão da planície");
    mvwprintw(stdscr,   4,      colum[0],   "moedas");              mvwprintw(stdscr,   4,      colum[1],      "numero");               mvwprintw(stdscr,   4,      colum[2],      "Define a quantidade de moedas inicial");
    mvwprintw(stdscr,   5,      colum[0],   "oponentes ");          mvwprintw(stdscr,   5,      colum[1],      "numero");               mvwprintw(stdscr,   5,      colum[2],      "Define o nr de oponentes");
    mvwprintw(stdscr,   6,      colum[0],   "castelo ");            mvwprintw(stdscr,   6,      colum[1],      "colonia lin col");      mvwprintw(stdscr,   6,      colum[2],      "Define a posição inicial da colonia indicada");
    mvwprintw(stdscr,   7,      colum[0],   "mkperfil ");           mvwprintw(stdscr,   7,      colum[1],      "letra");                mvwprintw(stdscr,   7,      colum[2],      "Cria um perfil novo");
    mvwprintw(stdscr,   8,      colum[0],   "addperfil");           mvwprintw(stdscr,   8,      colum[1],      "letra caracteristica"); mvwprintw(stdscr,   8,      colum[2],      "Adiciona um perfil");
    mvwprintw(stdscr,   9,      colum[0],   "subperfil");           mvwprintw(stdscr,   9,      colum[1],      "letra caracteristica"); mvwprintw(stdscr,   9,      colum[2],      "Remove caracteristica ao perfil");
    mvwprintw(stdscr,   10,     colum[0],   "rmperfil");            mvwprintw(stdscr,   10,     colum[1],     "letra");                 mvwprintw(stdscr,   10,     colum[2],     "Remove o perfil indicado");
    mvwprintw(stdscr,   11,     colum[0],   "load");                mvwprintw(stdscr,   11,     colum[1],     "ficheiro");              mvwprintw(stdscr,   11,     colum[2],     "Carrega Jogo");
    
    mvwprintw(stdscr,   13,     colum[0],   "inicio ");             mvwprintw(stdscr,   12,     colum[1],     "");                      mvwprintw(stdscr,   13,     colum[2],     "Inicia o Jogo");
    mvwprintw(stdscr,   14,     colum[0],   "exit ");               mvwprintw(stdscr,   14,      colum[1],     "");                     mvwprintw(stdscr,   14,      colum[2],     "Sair");
    
    mvwprintw(stdscr,   y-2,    colum[0],  "Comando > ");
    curs_set(1);
    clear_line(y-2,    colum[0]+10);
}
