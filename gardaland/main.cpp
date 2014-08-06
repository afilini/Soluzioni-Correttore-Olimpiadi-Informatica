//
//  main.cpp
//  gardaland
//
//  Created by Alekos Filini on 02/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//dichiaro le due variabili N e L
int N, L;
//dichiaro un vettore di interi chiamato nazioni (le nazioni hanno un come nome un intero da 0 a N escluso)
vector<int> nazioni;

int main(int argc, const char * argv[])
{
    fstream in, out;
    //apro i file
    in.open("input.txt", ios::in);
    out.open("output.txt", ios::out);
    //leggo N (numero di nazioni) e L (numero di righe da leggere successivamente contenenti quanti ragazzi di una certa nazione sono su un pullman)
    in >> N >> L;
    //Leggo quanti ragazzi ci sono di ogni nazione. Dato che sono ordinati posso usare il metodo push_back e aggiungere alla fine del vettore il numero di ragazzi. potrò andare a riprenderlo più tardi sapendo il numero della nazione (es: ragazziNazione0 = nazioni.at(0))
    for (int i = 0; i < N; i++){
        //scrivo il numero in una variabile temporanea e poi lo aggiungo alla fine del vettore. Semplicemente non potevo fare in >> nazioni.push_back(), per cui serve seguire il procedimento 'lungo' dell variabile temporanea
        int tmp;
        in >> tmp;
        nazioni.push_back(tmp);
    }
    //Ora leggo tutti i dati
    for (int j = 0; j < L; j++) {
        //Leggo il numero della nazione e il numero dei ragazzi di quella nazione presenti sul pullman
        int naz, rag;
        in >> naz >> rag;
        //ora prendo l'array nazioni e tolgo il numero di ragazzi su questo pullman
        nazioni[naz] -= rag;
    }
    //dichiaro una variabile contatore
    int counter = 0;
    //scorro l'array nazioni e se il numero di ragazzi sarà diverso da 0 potrò essere certo che qualuno non è presente su nessuno degli autobus
    for (int m = 0; m < N; m++) {
        if (nazioni.at(m) != 0){
            //se il numero di ragazzi è diverso da 0 aumento il contatore
            counter++;
        }
    }
    //Scrivo il numero di nazioni con dei ragazzi mancanti
    out << counter << "\n";
    //Scorro nuovamente il vettore, questa volta per scrivere quanti ragazzi di una certa nazione m mancano
    for (int m = 0; m < N; m++) {
        if (nazioni.at(m) != 0){
            //Se il numero di ragazzi è diverso da 0 scrivo m (il numero della nazione), spazio, il numero di ragazzi mancanti che non è altro che il numero rimasto nell'array, visto che ho sottratto tutti quelli presenti e poi aggiungo un new_line
            out << m << " " << nazioni.at(m) << "\n";
        }
    }
    return 0;
}

