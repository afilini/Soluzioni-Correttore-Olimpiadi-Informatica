//
//  main.cpp
//  sbarramento
//
//  Created by Alekos Filini on 29/07/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm> 

using namespace std;

struct arm {
    int row, col;
    bool operator <(const struct arm & rhs){
        return col < rhs.col;
    }
};

vector<arm> armate;
int N, R;
bool riga[505];

bool my_cmp(const arm& a, const arm& b)
{
    if (a.col == b.col){
        return abs(R - a.row) < abs(R - b.row);
    }else{
        return a.col < b.col;
    }
}

int main(int argc, const char * argv[])
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N >> R;
    for (int i = 0; i < N; i++) {
        armate.push_back(arm());
        in >> armate[i].row >> armate[i].col;
    }
    
    sort(armate.begin(), armate.end(), my_cmp);
    
    int moves = 0;
    
    for (int i = 0; i < N; i++){
        int col = 0;
        for (int m = 1; m <= N; m++) {
            if (!riga[m]){
                riga[m] = true;
                col = m;
                break;
            }
        }
        /*cout << "Mi trovo in " << armate[i].row << " " << armate[i].col;
        cout << " e devo andare a " << R << " " << col;
        cout << " con " << abs(R - armate[i].row) + abs(col - armate[i].col) << " mosse" << endl; */
        moves += abs(R - armate[i].row);
        moves += abs(col - armate[i].col);
    }
    //cout << "Moves: " << moves << endl;
    out << moves;
    return 0;
}

