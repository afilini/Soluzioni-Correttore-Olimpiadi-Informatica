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

// dichiaro le variabili contenenti il conteggio delle righe colonne, la parola e le mosse

int R, C;
char parola[10000];
char mosse[10000];
char tabella[101][101];

/* creo una funzione ricorsiva che partendo dalle coordinate e dalla lettera da cercare ritorna:
    Vero se si è aggiunta alla fine della parola;
    Vero se una delle due mosse possibili.
infine aggiunge alla variabile mosse la mossa eseguita.
 */
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
    //il file di input e output E leggo R, C e parola
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> R >> C;
    in >> parola;
    // leggo le R righe successive E inserisco tutte le lettere nella variabile tabella
    for (int i = 0; i < R; i++) {
        in >> tabella[i];
    }
    // controllo se la funzione ricorsiva ritorna vero (se è stato possibile trovare tutte le lettere) E se è vero cancello l'ultima lettera aggiunta al vettore mosse. se falso scrivo "assente"
    if(cerca(0, 0, 0)){
        mosse[strlen(parola) - 1] = '\0';
        out << mosse;
    }else
        out << "ASSENTE";
    return 0;
}

