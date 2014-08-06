//
//  main.cpp
//  galattici
//
//  Created by Alekos Filini on 07/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tripletta{
    int I, J;
    char c;
};

bool comp_triplette (const tripletta a, const tripletta b){
    if (a.c == b.c)
        return a.I < b.I;
    else
        return (int) a.c < (int) b.c;
}

int M, N, K;
vector<char> S;
vector<tripletta> triplette;

int main(int argc, const char * argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        char tmp;
        in >> tmp;
        S.push_back(tmp);
    }
    for (int j = 0; j < M; j++) {
        tripletta tmp;
        in >> tmp.I >> tmp.J >> tmp.c;
        triplette.push_back(tmp);
    }
    sort(triplette.begin(), triplette.end(), comp_triplette);
    int stato = 1;
    for (int i = 0; i < K; i++) {
        char attuale = S.at(i);
        int a = 0;
        while (true) {
            if (triplette.at(a).c == attuale && triplette.at(a).I == stato) {
                stato = triplette.at(a).J;
                break;
            }
            a++;
        }
    }
    out << stato;
    return 0;
}

