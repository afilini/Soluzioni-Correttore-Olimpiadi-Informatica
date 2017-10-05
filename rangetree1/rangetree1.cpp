#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int N, Q;
int segmentTree[400100]; 
bool lazy[400100];
int K;


void lazyF(int startRange, int endRange, int low, int high, int pos)
{

    if(low > high)
        return;
    if(lazy[pos] != 0)
    {
        segmentTree[pos] = -segmentTree[pos] +(high-low+1);
        if(high != low)
        {
            lazy[pos*2+1] = !lazy[pos*2+1];
            lazy[pos*2+2] = !lazy[pos*2+2];
        }
        lazy[pos] = 0;
    }
    //no overlap
    if(startRange > high || endRange < low)
        return;

    //total overlap

    if(startRange <= low && endRange >= high)
    {
        segmentTree[pos] = -segmentTree[pos] + (high-low+1);
        if(low != high)
        {
            lazy[pos*2+1] = !lazy[pos*2+1];
            lazy[pos*2+2] = !lazy[pos*2+2];
        }

        return;
    }

    //partial overlap

    int mid = (low + high)/2;
    lazyF(startRange, endRange, low, mid, pos*2+1);
    lazyF(startRange, endRange, mid+1, high, pos*2+2);

    segmentTree[pos] = segmentTree[pos*2+1] + segmentTree[pos*2+2];
}

int risposta(int startRange, int endRange, int low, int high, int pos)
{

    if(low > high)
        return 0;

    if(lazy[pos] != 0)
    {
        segmentTree[pos] = -segmentTree[pos] + (high-low+1);
        
        if(high != low)
        {
            lazy[pos*2+1] = !lazy[pos*2+1];
            lazy[pos*2+2] = !lazy[pos*2+2];
        }
        
        lazy[pos] = 0;
    }

    //no overlap

    if(startRange > high || endRange < low)
        return 0;


    //total overlap

    if(startRange <= low && high <= endRange)
        return segmentTree[pos];

    //partial overlap

    int mid = (low + high)/2;

    return risposta(startRange, endRange, low, mid, pos*2+1) + risposta(startRange, 
        endRange, mid + 1, high, pos*2+2);
}


int main()
{
    FILE *in, *out;
    in = freopen("input.txt", "r", stdin);
    out = freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &Q);
    
    for(K = 1; K < N; K += K);

    for(int i = 0; i < Q; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
       
        if(a == 0)
            lazyF(b,c,0,K-1,0);

        else
            cout << risposta(b,c,0,K-1,0) << endl;

    }
    
}