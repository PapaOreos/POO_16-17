/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header.h"
#include "configs.h"


int filtra_comando(string cmd){
    int escolha = 0;
    
	if      (cmd == pt_cmd_dim)          escolha = 1;
	else if (cmd == pt_cmd_moedas)       escolha = 2;
	else if (cmd == pt_cmd_oponentes)    escolha = 3;
	else if (cmd == pt_cmd_castelo)      escolha = 4;
	else if (cmd == pt_cmd_mkperfil)     escolha = 5;
	else if (cmd == pt_cmd_addperfil)    escolha = 6;
	else if (cmd == pt_cmd_subperfil)    escolha = 7;
	else if (cmd == pt_cmd_rmperfil)     escolha = 8;
	else if (cmd == pt_cmd_load)         escolha = 9;
	else if (cmd == pt_cmd_inicio)       escolha = 10;
        else if (cmd == pt_cmd_show)         escolha = 11;
        else if (cmd == pt_cmd_clear)        escolha = 12;
    
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
    
    mvwprintw(stdscr,   3,      colum[0],   pt_cmd_dim.c_str());                mvwprintw(stdscr,   3,      colum[1],     pt_cmd_dim_param.c_str());                mvwprintw(stdscr,   3,      colum[2],      "Define a Dimensão da planície");
    mvwprintw(stdscr,   4,      colum[0],   pt_cmd_moedas.c_str());             mvwprintw(stdscr,   4,      colum[1],     pt_cmd_moedas_param.c_str());             mvwprintw(stdscr,   4,      colum[2],      "Define a quantidade de moedas inicial");
    mvwprintw(stdscr,   5,      colum[0],   pt_cmd_oponentes.c_str());          mvwprintw(stdscr,   5,      colum[1],     pt_cmd_oponentes_param.c_str());          mvwprintw(stdscr,   5,      colum[2],      "Define o nr de oponentes");
    mvwprintw(stdscr,   6,      colum[0],   pt_cmd_castelo.c_str());            mvwprintw(stdscr,   6,      colum[1],     pt_cmd_castelo_param.c_str());            mvwprintw(stdscr,   6,      colum[2],      "Define a posição inicial da colonia indicada");
    mvwprintw(stdscr,   7,      colum[0],   pt_cmd_mkperfil.c_str());           mvwprintw(stdscr,   7,      colum[1],     pt_cmd_mkperfil_param.c_str());           mvwprintw(stdscr,   7,      colum[2],      "Cria um perfil novo");
    mvwprintw(stdscr,   8,      colum[0],   pt_cmd_addperfil.c_str());          mvwprintw(stdscr,   8,      colum[1],     pt_cmd_addperfil_param.c_str());          mvwprintw(stdscr,   8,      colum[2],      "Adiciona um perfil");
    mvwprintw(stdscr,   9,      colum[0],   pt_cmd_subperfil.c_str());          mvwprintw(stdscr,   9,      colum[1],     pt_cmd_subperfil_param.c_str());          mvwprintw(stdscr,   9,      colum[2],      "Remove caracteristica ao perfil");
    mvwprintw(stdscr,   10,     colum[0],   pt_cmd_rmperfil.c_str());           mvwprintw(stdscr,   10,     colum[1],     pt_cmd_rmperfil_param.c_str());           mvwprintw(stdscr,   10,     colum[2],     "Remove o perfil indicado");
    mvwprintw(stdscr,   11,     colum[0],   pt_cmd_load.c_str());               mvwprintw(stdscr,   11,     colum[1],     pt_cmd_load_param.c_str());               mvwprintw(stdscr,   11,     colum[2],     "Carrega Jogo");
    
    mvwprintw(stdscr,   13,     colum[0],   pt_cmd_inicio.c_str());             mvwprintw(stdscr,   13,     colum[1],     pt_cmd_inicio_param.c_str());             mvwprintw(stdscr,   13,     colum[2],     "Inicia o Jogo");
     mvwprintw(stdscr,   14,     colum[0],  pt_cmd_clear.c_str());              mvwprintw(stdscr,   14,     colum[1],     pt_cmd_clear_param.c_str());              mvwprintw(stdscr,   14,     colum[2],     "Limpa o ecra");
    mvwprintw(stdscr,   15,     colum[0],   pt_cmd_exit.c_str());               mvwprintw(stdscr,   15,     colum[1],     pt_cmd_exit_param.c_str());               mvwprintw(stdscr,   15,     colum[2],     "Sair");
}

//---------------------------------------------------------

void cmd_clear(int &y, int &x){

        int new_x, new_y;
    getmaxyx(stdscr, new_y, new_x);
  	
//se a janela for alterada de tamanho;
    if (new_y != y|| new_x != x) {
      x = new_x;
      y = new_y;

    }

    wclear(stdscr);

}

