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
    
    int escolha;
    string comando;
    
    int x, y;
     int *parent_x = &x;
     int *parent_y = &y;
    

    start_ecra();
    set_tamanho(*parent_y, *parent_x);
    
    do{
    print_ecra(*parent_y, *parent_x);
    refresh();
    
    comando = cin_str();
    istringstream iss(comando); //copia o comando para a stream
    iss >> comando;//le a stream ate ao primeiro separador (' ') ficando o comando apenas com a primeira palavra
    escolha = filtra_comando(comando);//iss
    
    switch (escolha){
        case 1:
            clear_line(y-5, 1);
            mvprintw(y-5, 1, "Escolha = dim");
        break;   
        
        default:
            clear_line(y-5, 1);
            mvprintw(y-5, 1, "Error?!");
    }
    
    
    
    }while(comando != "exit");
  
  endwin();

  return 0;
}
