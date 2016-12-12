/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: filmaluco
 *
 * Created on December 11, 2016, 4:38 PM
 */

#include "header.h"

using namespace std;


int main() {
    
    //variaveis para menu
    int escolha;
    string comando;
    
    //variaveis para ecra
    int x, y;
     int *parent_x = &x;
     int *parent_y = &y;
     
     //variaveis para comando dim
     int linhas = -1, colunas = -1; //incializadas para garantir que o cmd dim da erro mesmo que va sem lin e col
    

    start_ecra();
    set_tamanho(*parent_y, *parent_x);
 
    
    do{
    print_ecra(*parent_y, *parent_x);
    refresh();
    comando = cin_str();
    clear();
    draw_borders(stdscr);
    istringstream cmd(comando); //copia o comando para a stream
    cmd >> comando;//le a stream ate ao primeiro separador (' ') ficando o comando apenas com a primeira palavra
    escolha = filtra_comando(comando);
    switch (escolha){
        case 1:
            
            clear_line(1, 1);
            cmd >> linhas;
            cmd >> colunas;
            
            if(linhas == -1 || colunas == -1){
                mvprintw(1, 1, "Informações insuficientes para o comando");
                linhas = -1;	colunas = -1;
             break;
            }
            
            else if (linhas < 60 || colunas < 60){
                mvprintw(1, 1, "Mapa demasiado pequeno!Tente outra vez!(min:80x80)");
                linhas = -1;	colunas = -1;
             break;
            }
            break;   
        
        case 11:
            
            cmd_show(*parent_y, *parent_x);
        break;
        
        
        
        default:
            clear_line(1, 1);
            mvprintw(1, 1, "Comando invalido, em caso de duvida use o comando < show >");
    }
    
    
    
    }while(comando != "exit");
  
  endwin();

  return 0;
}
