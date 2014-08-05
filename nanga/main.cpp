//
//  main.cpp
//  nanga
//
//  Created by Alekos Filini on 02/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, alt = 0;
vector<int> altitudini;
int freq[2000010];
int main(int argc, const char * argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        in >> temp;
        alt += temp;
        altitudini.push_back(alt);
        freq[alt + 1000000] += 1;
    }
    int max = 0;
    int alt_max = 5000;
    for (int j = 0; j < N; j++){
        if (freq[altitudini.at(j) + 1000000] > max) {
            max = freq[altitudini.at(j) + 1000000];
            alt_max = altitudini.at(j);
        }
    }
    out << alt_max + 5000 << endl;
    return 0;
}

