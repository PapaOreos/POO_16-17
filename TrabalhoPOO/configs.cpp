/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header.h"
#include "configs.h"


int filtra_comando(string cmd){
    int escolha = 0;
    
	if      (cmd == "dim")          escolha = 1;
	else if (cmd == "moedas")       escolha = 2;
	else if (cmd == "oponentes")    escolha = 3;
	else if (cmd == "castelo")      escolha = 4;
	else if (cmd == "mkperfil")     escolha = 5;
	else if (cmd == "addperfil")    escolha = 6;
	else if (cmd == "subperfil")    escolha = 7;
	else if (cmd == "rmperfil")     escolha = 8;
	else if (cmd == "load")         escolha = 9;
	else if (cmd == "inicio")       escolha = 10;
        else if (cmd == "show")         escolha = 11;
    
    return escolha;
}

//---------------------------------------------------------

void cmd_show(int &y, int &x){
    
    int colum [3] = { 1, 20, 45};
    
    int new_x, new_y;
    getmaxyx(stdscr, new_y, new_x);
  	
//se a janela for alterada de tamanho;
    if (new_y != y|| new_x != x) {
      x = new_x;
      y = new_y;

      wclear(stdscr);
    }

     
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
    mvwprintw(stdscr,   14,     colum[0],   "exit ");               mvwprintw(stdscr,   14,     colum[1],     "");                     mvwprintw(stdscr,   14,      colum[2],     "Sair");
}