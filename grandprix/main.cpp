//
//  main.cpp
//  grandprix
//
//  Created by Alekos Filini on 02/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> macchine;

int main(int argc, const char * argv[])
{
    fstream in, out;
    in.open("input.txt", ios::in);
    out.open("output.txt", ios::out);
    in >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        in >> tmp;
        macchine.push_back(tmp);
    }
    for (int j = 0; j < M; j++) {
        int iniz, fine;
        in >> iniz >> fine;
        int pos = find(macchine.begin(), macchine.end(), iniz) - macchine.begin();
        macchine[pos] = fine;
        macchine[pos - 1] = iniz;
    }
    out << macchine.at(0);
    return 0;
}

