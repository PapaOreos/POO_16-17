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
	if (cmd == "dim")
		escolha = 1;
	else if (!cmd.compare("moedas"))
		escolha = 2;
	else if (!cmd.compare("oponentes"))
		escolha = 3;
	else if (!cmd.compare("castelo"))
		escolha = 4;
	else if (!cmd.compare("mkperfil"))
		escolha = 5;
	else if (!cmd.compare("addperfil"))
		escolha = 6;
	else if (!cmd.compare("subperfil"))
		escolha = 7;
	else if (!cmd.compare("rmperfil"))
		escolha = 8;
	else if (!cmd.compare("load"))
		escolha = 9;
	else if (!cmd.compare("inicio"))
		escolha = 10;
	return escolha;
}
    