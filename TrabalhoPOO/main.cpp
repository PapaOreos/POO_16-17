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
     int linhas = 0, colunas = 0; //incializadas para garantir que o cmd dim da erro mesmo que va sem lin e col
    

    start_ecra();
    set_tamanho(*parent_y, *parent_x);
    
    do{
    print_ecra(*parent_y, *parent_x);
    refresh();
    
    comando = cin_str();
    istringstream cmd(comando); //copia o comando para a stream
    cmd >> comando;//le a stream ate ao primeiro separador (' ') ficando o comando apenas com a primeira palavra
    escolha = filtra_comando(comando);//iss
    
    switch (escolha){
        case 1:
            clear_line(19, 1);
            cmd >> linhas;
            cmd >> colunas;
            
            if (linhas < 60 || colunas < 60){
                mvprintw(19, 1, "Mapa demasiado pequeno!Tente outra vez!(min:80x80)");
                linhas = 0;	colunas = 0;
             break;
            }
            
        break;   
        
        default:
            clear_line(19, 1);
            mvprintw(19, 1, "");
    }
    
    
    
    }while(comando != "exit");
  
  endwin();

  return 0;
}
