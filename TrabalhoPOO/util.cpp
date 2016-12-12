/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "util.h"


using namespace std;

string cin_str(){
    
    ostringstream os;
    
        char* str = new char[160];
        getstr(str);
        
        os << str;
        
        delete str;
        
        return os.str();
    
    
}

//---------------------------------------------------------

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

void clear_line(int y, int x){
    
     move(y,x);
     clrtoeol();   
    
}