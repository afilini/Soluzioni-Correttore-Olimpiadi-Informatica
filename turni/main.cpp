//
//  main.cpp
//  turni
//
//  Created by Alekos Filini on 05/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// Creo struttura persona, con un giorno di inizio e uno di fine
struct persona{
    int inizio, fine;
};

//Definisco il criterio di ordinamento: ordino in modo decrescente i giorni di fine; a parità di fine ordino in modo decrescente gli inizi
bool const comp_persona (const persona a, const persona b){
    if (a.fine == b.fine)
        return a.inizio > b.inizio;
    else
        return a.fine > b.fine;
}

//dichiaro K, N, e il vettore contenente le persone
int K, N;
vector<persona> persone;

int main(int argc, const char * argv[])
{
    //apro il file di input e output
    ifstream in("input.txt");
    ofstream out("output.txt");
    //ottengo K e N e leggo le persone
    in >> K >> N;
    for (int i = 0; i < N; i++){
        persona tmp;
        in >> tmp.inizio >> tmp.fine;
        persone.push_back(tmp);
    }
    //ordino (secondo il criterio specificato in comp_persona)
    sort(persone.begin(), persone.end(), comp_persona);
    //dichiaro il conteggio delle persone impiegate e l'ultimo valore coperto
    int coperto = -1, conteggio = 0;
    //ripeto fino a quando tutti i giorni saranno coperti
    while (coperto < K - 1) {
        //scorro il vettore fino a trovare una persona in grado di coprire il periodo che ci interessa. Visto l'orinamento è sufficiente prendere il primo elemento che soddisfa la condizione per essere sicuri di fare la scelta ottimale
        for (int m = 0; m < N; m++) {
            if (persone.at(m).inizio <= coperto + 1) {
                coperto = persone.at(m).fine;
                conteggio++;
                break;
            }
        }
    }
    //scrivo il conteggio delle persone utilizzate
    out << conteggio;
    return 0;
}

