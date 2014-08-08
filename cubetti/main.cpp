//
//  main.cpp
//  cubetti
//
//  Created by Alekos Filini on 08/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N;
vector<int> cubi;
bool fatti[100001];

int main(int argc, const char * argv[])
{
    in >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        in >> tmp;
        cubi.push_back(tmp);
    }
    sort(cubi.begin(), cubi.end());
    int conteggio = 0;
    for (int i = 0; i <  N; i++) {
        if (fatti[cubi.at(i)]) {
            conteggio++;
        }else{
            fatti[cubi.at(i)] = true;
        }
    }
    out << conteggio;
    return 0;
}