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

void clear_line(int y, int x){
    
     move(y,x);
     clrtoeol();   
    
}