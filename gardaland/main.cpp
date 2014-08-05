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

int N, L;

vector<int> nazioni;

int main(int argc, const char * argv[])
{
    fstream in, out;
    in.open("input.txt", ios::in);
    out.open("output.txt", ios::out);
    in >> N >> L;
    for (int i = 0; i < N; i++){
        int tmp;
        in >> tmp;
        nazioni.push_back(tmp);
    }
    for (int j = 0; j < L; j++) {
        int naz, rag;
        in >> naz >> rag;
        nazioni[naz] -= rag;
    }
    int counter = 0;
    vector<string> temp;
    for (int m = 0; m < N; m++) {
        if (nazioni.at(m) != 0){
            counter++;
        }
    }
    out << counter << "\n";
    for (int m = 0; m < N; m++) {
        if (nazioni.at(m) != 0){
            out << m << " " << nazioni.at(m) << "\n";
        }
    }
    return 0;
}

