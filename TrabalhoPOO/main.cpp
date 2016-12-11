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
    
    
    }while(comando != "exit");
  
  endwin();

  return 0;
}
