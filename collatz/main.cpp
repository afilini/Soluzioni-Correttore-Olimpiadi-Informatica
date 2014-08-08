//
//  main.cpp
//  collatz
//
//  Created by Alekos Filini on 08/08/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int conteggio = 1;
ifstream in("input.txt");
ofstream out("output.txt");

void ricorsivo (int n){
    if (n == 1)
        out << conteggio << endl;
    else{
        conteggio++;
        if (n % 2 == 0) {
            ricorsivo(n / 2);
        }else{
            ricorsivo(3 * n + 1);
        }
    }
}

int main(int argc, const char * argv[])
{
    
    int N;
    in >> N;
    
    ricorsivo(N);
    
    return 0;
}

