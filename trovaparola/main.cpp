//
//  main.cpp
//  trovaparola
//
//  Created by Alekos Filini on 05/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int R, C;
char parola[10000];
char mosse[10000];
char tabella[101][101];

bool cerca(int x, int y, int char_pos){
    if(char_pos == strlen(parola))
        return true;
    if(parola[char_pos] == tabella[x][y]){
        if(cerca(x + 1, y, char_pos + 1)){
            mosse[char_pos] = 'B';
            return true;
        }else if(cerca(x, y + 1, char_pos + 1)){
            mosse[char_pos] = 'D';
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> R >> C;
    in >> parola;
    for (int i = 0; i < R; i++) {
        in >> tabella[i];
    }
    if(cerca(0, 0, 0)){
        mosse[strlen(parola) - 1] = '\0';
        out << mosse;
    }else
        out << "ASSENTE";
    return 0;
}

