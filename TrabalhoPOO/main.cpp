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
  
  int parent_x, parent_y, new_x, new_y;
  int score_size = 3;

  setlocale(LC_ALL, "");

initscr();
noecho(); 						
cbreak();
curs_set(0); 					 
keypad(stdscr, true);			
clear();		

  // set up initial windows
  getmaxyx(stdscr, parent_y, parent_x);
  
  do{
      
      mvwprintw(stdscr, 1,1, "Por favor de resize a sua janela");
      
  }while(parent_y < 50 && parent_x < 175);
      

  WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
  WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);

  mvwprintw(score, 1, 1, "Prima <x> para sair");
  
  wrefresh(field);
  wrefresh(score);
  
  sleep(5);
  
  
  endwin();

 

  return 0;
}
