//
//  main.cpp
//  tamburello
//
//  Created by Alekos Filini on 28/07/14.
//  Copyright (c) 2014 Alekos Filini. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int N;
char stringa[10005];
char periodo[10005];
char tmp[5010];

int main(int argc, const char * argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> stringa[i];
    }
    int l;
    for (int i = 0; i < N/2; i++) {
        l = i + 1;
        periodo[i] = stringa[i];
        periodo[l] = '\0';
        for (int j = 0; j < N; j += l) {
            memcpy(&tmp, &stringa[j], sizeof(char) * l);
            tmp[l] = '\0';
            if (strcmp(tmp, periodo) != 0)
                break;
            else{
                if(j+l == N){
                    for (int m = 0; m < strlen(periodo); m++) {
                        out << periodo[m] << " ";
                    }
                    goto end;
                }
            }
        }
    }
    out << '2';
    end:
    return 0;
}

